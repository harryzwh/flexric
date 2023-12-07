/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03_modified.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RANParameter_Definition_Choice_H_
#define	_RANParameter_Definition_Choice_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RANParameter_Definition_Choice_PR {
	RANParameter_Definition_Choice_PR_NOTHING,	/* No components present */
	RANParameter_Definition_Choice_PR_choiceLIST,
	RANParameter_Definition_Choice_PR_choiceSTRUCTURE
	/* Extensions may appear below */
	
} RANParameter_Definition_Choice_PR;

/* Forward declarations */
struct RANParameter_Definition_Choice_LIST;
struct RANParameter_Definition_Choice_STRUCTURE;

/* RANParameter-Definition-Choice */
typedef struct RANParameter_Definition_Choice {
	RANParameter_Definition_Choice_PR present;
	union RANParameter_Definition_Choice_u {
		struct RANParameter_Definition_Choice_LIST	*choiceLIST;
		struct RANParameter_Definition_Choice_STRUCTURE	*choiceSTRUCTURE;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_Definition_Choice_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_Definition_Choice;
extern asn_CHOICE_specifics_t asn_SPC_RANParameter_Definition_Choice_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_Definition_Choice_1[2];
extern asn_per_constraints_t asn_PER_type_RANParameter_Definition_Choice_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_Definition_Choice_H_ */
#include <asn_internal.h>
