/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-RC-IEs"
 * 	found in "e2sm_rc_v1_03_modified.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RANParameter_Definition_H_
#define	_RANParameter_Definition_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RANParameter_Definition_Choice;

/* RANParameter-Definition */
typedef struct RANParameter_Definition {
	struct RANParameter_Definition_Choice	*ranParameter_Definition_Choice;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RANParameter_Definition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RANParameter_Definition;
extern asn_SEQUENCE_specifics_t asn_SPC_RANParameter_Definition_specs_1;
extern asn_TYPE_member_t asn_MBR_RANParameter_Definition_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _RANParameter_Definition_H_ */
#include <asn_internal.h>
