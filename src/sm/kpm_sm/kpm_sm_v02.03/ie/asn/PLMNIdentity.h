/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v02.03_modified.asn1"
 * 	`asn1c -no-gen-BER -no-gen-UPER -no-gen-OER -no-gen-JER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_PLMNIdentity_H_
#define	_PLMNIdentity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PLMNIdentity */
typedef OCTET_STRING_t	 PLMNIdentity_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PLMNIdentity_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PLMNIdentity;
asn_struct_free_f PLMNIdentity_free;
asn_struct_print_f PLMNIdentity_print;
asn_constr_check_f PLMNIdentity_constraint;
xer_type_decoder_f PLMNIdentity_decode_xer;
xer_type_encoder_f PLMNIdentity_encode_xer;
per_type_decoder_f PLMNIdentity_decode_aper;
per_type_encoder_f PLMNIdentity_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _PLMNIdentity_H_ */
#include <asn_internal.h>
