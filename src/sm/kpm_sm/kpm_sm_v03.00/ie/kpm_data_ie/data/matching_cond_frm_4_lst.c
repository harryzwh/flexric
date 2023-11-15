#include <assert.h>

#include "matching_cond_frm_4_lst.h"

void free_matching_cond_frm_4(matching_condition_format_4_lst_t* src)
{
  assert(src != NULL);

  // Test Information List
  free_test_info(&src->test_info_lst);

  // Logical OR
  if (src->logical_OR != NULL)
    free(src->logical_OR);

}

static
bool eq_logical_or(enum_value_e const *m0, enum_value_e const *m1)
{
  if(m0 == m1) 
    return true;

  if(m0 == NULL || m1 == NULL)
    return false;

  if(*m0 != *m1)
    return false;

  return true;
}


bool eq_matching_cond_frm_4(matching_condition_format_4_lst_t const * m0, matching_condition_format_4_lst_t const * m1)
{
  assert(m0 != NULL);
  assert(m1 != NULL);

  // Test Information List
  if (eq_test_info(&m0->test_info_lst, &m1->test_info_lst) != true)
    return false;

  // Logical OR
  if(eq_logical_or(m0->logical_OR, m1->logical_OR) == false)
    return false;

  return true;
}
