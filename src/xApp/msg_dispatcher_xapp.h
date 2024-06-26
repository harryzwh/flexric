/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */



#ifndef MESSAGE_DISPATCHER_XAPP_H
#define MESSAGE_DISPATCHER_XAPP_H 


#include "../util/alg_ds/ds/tsn_queue/tsn_queue.h"
#include "../sm/agent_if/read/sm_ag_if_rd.h"
#include "../lib/e2ap/e2ap_global_node_id_wrapper.h"

#include <pthread.h>


typedef struct{
  pthread_t p;
  tsnq_t q;
} msg_dispatcher_xapp_t;

typedef struct{
  sm_ag_if_rd_t rd;
  global_e2_node_id_t e2_node;
  void (*sm_cb)(sm_ag_if_rd_t const*,  const global_e2_node_id_t*);
} msg_dispatch_t ;

void init_msg_dispatcher( msg_dispatcher_xapp_t* d);

void free_msg_dispatcher( msg_dispatcher_xapp_t* d);

void send_msg_dispatcher( msg_dispatcher_xapp_t* d, msg_dispatch_t* msg );

size_t size_msg_dispatcher(msg_dispatcher_xapp_t* d);

#endif

