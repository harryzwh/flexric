#include "../../rnd/fill_rnd_data_slice.h"
#include "../../../src/sm/slice_sm/slice_sm_agent.h"
#include "../../../src/sm/slice_sm/slice_sm_ric.h"
#include "../../../src/util/alg_ds/alg/defer.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>


// For testing purposes
static
slice_ind_data_t cp;

static
slice_ctrl_req_data_t cp_ctrl;

//
// Functions 


/////
// AGENT
////

static
void read_ind_slice(void* read)
{
  assert(read != NULL);

  slice_ind_data_t* slice = (slice_ind_data_t*)read;
  fill_slice_ind_data(slice);
  cp.msg = cp_slice_ind_msg(&slice->msg);
  assert(eq_slice_ind_msg(&cp.msg, &slice->msg) );
}

static 
sm_ag_if_ans_t write_ctrl_slice(void const* data)
{
  assert(data != NULL);

  slice_ctrl_req_data_t const* ctrl = (slice_ctrl_req_data_t const*)data; 

  bool const ans_hdr = eq_slice_ctrl_hdr(&cp_ctrl.hdr, &ctrl->hdr);
  assert(ans_hdr == true);

  bool const ans_msg = eq_slice_ctrl_msg(&cp_ctrl.msg, &ctrl->msg);
  assert(ans_msg == true);

  sm_ag_if_ans_t ans = {.type = CTRL_OUTCOME_SM_AG_IF_ANS_V0}; 
  ans.ctrl_out.type = SLICE_AGENT_IF_CTRL_ANS_V0;
 
  const char* str = "THIS IS ANS STRING";
  ans.ctrl_out.slice.len_diag = strlen(str);
  ans.ctrl_out.slice.diagnostic = malloc(strlen(str));
  assert(ans.ctrl_out.slice.diagnostic != NULL && "Memory exhausted");

  memcpy(ans.ctrl_out.slice.diagnostic, str, strlen(str));

  return ans;
}

/////////////////////////////
// Check Functions
// //////////////////////////

static
void check_eq_ran_function(sm_agent_t const* ag, sm_ric_t const* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);
  assert(ag->info.id() == ric->ran_func_id);
}

// RIC -> E2
static
void check_subscription(sm_agent_t* ag, sm_ric_t* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);

  char sub[] = "2_ms";
  sm_subs_data_t data = ric->proc.on_subscription(ric, &sub );
  subscribe_timer_t t = ag->proc.on_subscription(ag, &data); 

  assert(t.ms == 2);
  free_sm_subs_data(&data);
}

// E2 -> RIC
static
void check_indication(sm_agent_t* ag, sm_ric_t* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);

  sm_ind_data_t sm_data = ag->proc.on_indication(ag, NULL);
  defer({ free_sm_ind_data(&sm_data); }); 

  sm_ag_if_rd_ind_t msg = ric->proc.on_indication(ric, &sm_data);

  slice_ind_data_t* data = &msg.slice;
  assert(msg.type == SLICE_STATS_V0);

  assert(eq_slice_ind_msg(&cp.msg, &data->msg) == true);

  free_slice_ind_hdr(&data->hdr); 
  free_slice_ind_msg(&data->msg); 

  free_slice_ind_hdr(&cp.hdr);
  free_slice_ind_msg(&cp.msg);
}

static
void check_ctrl(sm_agent_t* ag, sm_ric_t* ric)
{
  assert(ag != NULL);
  assert(ric != NULL);

  //sm_ag_if_wr_t wr = {.type = CONTROL_SM_AG_IF_WR };
  //wr.ctrl.type = SLICE_CTRL_REQ_V0 ;

  slice_ctrl_req_data_t slice_req_ctrl = {0};
  fill_slice_ctrl(&slice_req_ctrl);

  cp_ctrl.hdr = cp_slice_ctrl_hdr(&slice_req_ctrl.hdr);
  cp_ctrl.msg = cp_slice_ctrl_msg(&slice_req_ctrl.msg);

  sm_ctrl_req_data_t ctrl_req = ric->proc.on_control_req(ric, &slice_req_ctrl);

  sm_ctrl_out_data_t out_data = ag->proc.on_control(ag, &ctrl_req);

  sm_ag_if_ans_ctrl_t ans = ric->proc.on_control_out(ric, &out_data);
  assert(ans.type == SLICE_AGENT_IF_CTRL_ANS_V0);

  if(ctrl_req.len_hdr > 0)
    free(ctrl_req.ctrl_hdr);

  if(ctrl_req.len_msg > 0)
    free(ctrl_req.ctrl_msg);

  if(out_data.len_out > 0)
    free(out_data.ctrl_out);

  free_slice_ctrl_out(&ans.slice);

  free_slice_ctrl_hdr(&slice_req_ctrl.hdr); 
  free_slice_ctrl_msg(&slice_req_ctrl.msg); 

  free_slice_ctrl_hdr(&cp_ctrl.hdr);
  free_slice_ctrl_msg(&cp_ctrl.msg);
}

int main()
{
  sm_io_ag_ran_t io_ag = {0}; //.read = read_RAN, .write = write_RAN};  
  io_ag.read_ind_tbl[SLICE_STATS_V0] = read_ind_slice;
  io_ag.write_ctrl_tbl[SLICE_CTRL_REQ_V0] = write_ctrl_slice;

  sm_agent_t* sm_ag = make_slice_sm_agent(io_ag);
  sm_ric_t* sm_ric = make_slice_sm_ric();

  for(int i = 0; i < 64*1024; ++i){
    check_eq_ran_function(sm_ag, sm_ric);
    check_subscription(sm_ag, sm_ric);
    check_indication(sm_ag, sm_ric);
    check_ctrl(sm_ag, sm_ric);
  }

  sm_ag->free_sm(sm_ag);
  sm_ric->free_sm(sm_ric);

  printf("Success\n");
  return EXIT_SUCCESS;
}

