/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-COMMON-IEs"
 * 	found in "e2sm_kpm_v02.01_standard.asn1"
 * 	`asn1c -no-gen-BER -no-gen-UPER -no-gen-OER -no-gen-JER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#ifndef	_GUMMEI_H_
#define	_GUMMEI_H_


#include <asn_application.h>

/* Including external dependencies */
#include "PLMNIdentity.h"
#include "MME-Group-ID.h"
#include "MME-Code.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GUMMEI */
typedef struct GUMMEI {
	PLMNIdentity_t	 pLMN_Identity;
	MME_Group_ID_t	 mME_Group_ID;
	MME_Code_t	 mME_Code;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GUMMEI_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GUMMEI;
extern asn_SEQUENCE_specifics_t asn_SPC_GUMMEI_specs_1;
extern asn_TYPE_member_t asn_MBR_GUMMEI_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _GUMMEI_H_ */
#include <asn_internal.h>
