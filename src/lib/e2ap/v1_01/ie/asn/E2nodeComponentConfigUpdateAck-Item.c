/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v01.01.asn1"
 * 	`asn1c -gen-APER -no-gen-JER -no-gen-OER -fcompound-names -no-gen-example -findirect-choice -fno-include-deps`
 */

#include "E2nodeComponentConfigUpdateAck-Item.h"

#include "E2nodeComponentID.h"
asn_TYPE_member_t asn_MBR_E2nodeComponentConfigUpdateAck_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct E2nodeComponentConfigUpdateAck_Item, e2nodeComponentType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2nodeComponentType,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"e2nodeComponentType"
		},
	{ ATF_POINTER, 1, offsetof(struct E2nodeComponentConfigUpdateAck_Item, e2nodeComponentID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_E2nodeComponentID,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"e2nodeComponentID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct E2nodeComponentConfigUpdateAck_Item, e2nodeComponentConfigUpdateAck),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_E2nodeComponentConfigUpdateAck,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"e2nodeComponentConfigUpdateAck"
		},
};
static const int asn_MAP_E2nodeComponentConfigUpdateAck_Item_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_E2nodeComponentConfigUpdateAck_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* e2nodeComponentType */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* e2nodeComponentID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* e2nodeComponentConfigUpdateAck */
};
asn_SEQUENCE_specifics_t asn_SPC_E2nodeComponentConfigUpdateAck_Item_specs_1 = {
	sizeof(struct E2nodeComponentConfigUpdateAck_Item),
	offsetof(struct E2nodeComponentConfigUpdateAck_Item, _asn_ctx),
	asn_MAP_E2nodeComponentConfigUpdateAck_Item_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_E2nodeComponentConfigUpdateAck_Item_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_E2nodeComponentConfigUpdateAck_Item = {
	"E2nodeComponentConfigUpdateAck-Item",
	"E2nodeComponentConfigUpdateAck-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1,
	sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1)
		/sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1[0]), /* 1 */
	asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1)
		/sizeof(asn_DEF_E2nodeComponentConfigUpdateAck_Item_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_E2nodeComponentConfigUpdateAck_Item_1,
	3,	/* Elements count */
	&asn_SPC_E2nodeComponentConfigUpdateAck_Item_specs_1	/* Additional specs */
};

