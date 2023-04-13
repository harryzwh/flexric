#include <assert.h>

#include "kpm_data_ie.h"

void free_kpm_ind_data(kpm_ind_data_t* ind) 
{
  assert(ind != NULL);
  
  // Indication Header
  free_kpm_ind_hdr(&ind->hdr);

  // Indication Message
  free_kpm_ind_msg(&ind->msg);

  // 
  assert(ind->proc_id == NULL && "Not implemented");
}

kpm_ind_data_t cp_kpm_ind_data(kpm_ind_data_t const* src) 
{
  assert(src != NULL);
  kpm_ind_data_t ret = {0};
  
  // Indication Header
  ret.hdr = cp_kpm_ind_hdr(&src->hdr);

  // Indication Message
  ret.msg = cp_kpm_ind_msg(&src->msg);

  assert(src->proc_id == NULL && "Not implemented");

  return ret;
}

bool eq_kpm_ind_data(kpm_ind_data_t const* ind0, kpm_ind_data_t const* ind1)
{
  assert(ind0 != NULL);
  assert(ind1 != NULL);

  if (ind0 == ind1) return true;

  if(ind0 == NULL || ind1 == NULL)
    return false;

  // Indication Header
  if (eq_kpm_ind_hdr(&ind0->hdr, &ind1->hdr) != true)
    return false;

  // Indication Message
  if (eq_kpm_ind_msg(&ind0->msg, &ind1->msg) != true)
    return false;

  assert(ind0->proc_id == NULL && "Not implemented");
  assert(ind1->proc_id == NULL && "Not implemented");

  return true;
}

void free_kpm_sub_data(kpm_sub_data_t* src)
{
  assert(src != NULL);

  //kpm_event_trigger_t et; 

  //action definition
  for(size_t i = 0; i < src->sz_ad; ++i){
    free_kpm_action_def(&src->ad[i]);
  }
  free(src->ad);
}

