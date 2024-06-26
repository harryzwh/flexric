set(e2ap_src_types
  ric_subscription_request.c
  ric_subscription_response.c
  ric_subscription_failure.c 
  ric_indication.c 
  ric_subscription_delete_request.c 
  ric_subscription_delete_response.c 
  ric_subscription_delete_failure.c 
  ric_control_request.c
  ric_control_ack.c 
  ric_control_failure.c
  e2ap_error_indication.c 
  e2_setup_request.c 
  e2_setup_response.c 
  e2_setup_failure.c 

  e42_setup_request.c 
  e42_setup_response.c 
  e42_ric_control_request.c 
  e2_node_connected.c
  e42_ric_subscription_request.c
  e42_ric_subscription_delete_request.c
  e42_update_e2_node.c

  e2ap_reset_request.c 
  e2ap_reset_response.c 
  ric_service_update.c 
  ric_service_update_ack.c 
  ric_service_update_failure.c 
  ric_service_query.c 
  e2_node_configuration_update.c 
  common/e2ap_ran_function_id_rev.c 
  common/e2ap_ran_function_id.c 
  common/ric_action.c 
  common/ric_gen_id.c 
  common/ric_action_admitted.c 
  common/ric_action_not_admitted.c 
  common/e2ap_criticality_diagnostics.c 
  common/e2ap_cause.c 
  common/e2ap_global_node_id.c
  common/e2ap_global_ric_id.c 
  common/e2ap_ran_function.c 
  common/e2ap_time_to_wait.c 
  common/e2ap_rejected_ran_function.c 
  common/e2ap_node_component_config_update.c  
  common/transport_layer_info.c 
  common/e2ap_plmn.c 
  common/ric_subsequent_action.c
  )

add_library(e2ap_types_obj OBJECT 
                       ${e2ap_src_types} 
                        ) 

target_link_libraries(e2ap_types_obj PRIVATE e2_conv_obj)