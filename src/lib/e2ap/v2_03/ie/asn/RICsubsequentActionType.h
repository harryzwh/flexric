/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "e42ap_v2_03.asn"
 * 	`asn1c -gen-APER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_RICsubsequentActionType_H_
#define	_RICsubsequentActionType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RICsubsequentActionType {
	RICsubsequentActionType_continue	= 0,
	RICsubsequentActionType_wait	= 1
	/*
	 * Enumeration is extensible
	 */
} e_RICsubsequentActionType;

/* RICsubsequentActionType */
typedef long	 RICsubsequentActionType_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_RICsubsequentActionType_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_RICsubsequentActionType;
extern const asn_INTEGER_specifics_t asn_SPC_RICsubsequentActionType_specs_1;
asn_struct_free_f RICsubsequentActionType_free;
asn_struct_print_f RICsubsequentActionType_print;
asn_constr_check_f RICsubsequentActionType_constraint;
ber_type_decoder_f RICsubsequentActionType_decode_ber;
der_type_encoder_f RICsubsequentActionType_encode_der;
xer_type_decoder_f RICsubsequentActionType_decode_xer;
xer_type_encoder_f RICsubsequentActionType_encode_xer;
jer_type_encoder_f RICsubsequentActionType_encode_jer;
per_type_decoder_f RICsubsequentActionType_decode_uper;
per_type_encoder_f RICsubsequentActionType_encode_uper;
per_type_decoder_f RICsubsequentActionType_decode_aper;
per_type_encoder_f RICsubsequentActionType_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _RICsubsequentActionType_H_ */
#include <asn_internal.h>
