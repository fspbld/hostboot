/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/vpdreasoncodes.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __VPDREASONCODES_H
#define __VPDREASONCODES_H

// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace VPD
{

/**
* @enum vpdModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum vpdModuleId
{
    VPD_INVALID_MODULE                      = 0x00,

    // Common VPD
    VPD_WRITE_PNOR                          = 0x10,
    VPD_ENSURE_CACHE_IS_IN_SYNC             = 0x11,
    VPD_GET_PN_AND_SN                       = 0x12,
    VPD_GET_VPD_LOCATION                    = 0x13,

    // IPVPD
    VPD_IPVPD_TRANSLATE_RECORD              = 0x20,
    VPD_IPVPD_TRANSLATE_KEYWORD             = 0x21,
    VPD_IPVPD_FIND_RECORD_OFFSET            = 0x22,
    VPD_IPVPD_FIND_KEYWORD_ADDR             = 0x23,
    VPD_IPVPD_CHECK_BUFFER_SIZE             = 0x24,
    VPD_IPVPD_FIND_RECORD_OFFSET_SEEPROM    = 0x30,
    VPD_IPVPD_FETCH_DATA                    = 0x31,
    VPD_IPVPD_WRITE_KEYWORD                 = 0x32,
    VPD_IPVPD_LOAD_PNOR                     = 0x33,
    VPD_IPVPD_GET_RECORD_LIST_SEEPROM       = 0x34,

    // PVPD
    VPD_PVPD_PRESENCEDETECT                 = 0x50,

    // DVPD
    VPD_DVPD_PRESENCEDETECT                 = 0x58,

    // DIMM SPD
    VPD_SPD_GET_KEYWORD_VALUE               = 0x61,
    VPD_SPD_GET_VALUE                       = 0x62,
    VPD_SPD_CHECK_SIZE                      = 0x63,
    VPD_SPD_READ_BINARY_FILE                = 0x64,
    VPD_SPD_WRITE_KEYWORD_VALUE             = 0x65,
    VPD_SPD_SPECIAL_CASES                   = 0x66,
    VPD_SPD_DDR3_SPECIAL_CASES              = 0x67,
    VPD_SPD_DDR4_SPECIAL_CASES              = 0x68,
    VPD_SPD_PRESENCE_DETECT                 = 0x69,
    VPD_SPD_CHECK_MODULE_SPECIFIC_KEYWORD   = 0x6A,
    VPD_SPD_WRITE_VALUE                     = 0x6B,
    VPD_SPD_GET_KEYWORD_ENTRY               = 0x6C,
    VPD_SPD_WRITE_DATA                      = 0x6D,
    VPD_SPD_GET_MOD_TYPE                    = 0x6E,
    VPD_SPD_FETCH_DATA                      = 0x6F,

    // Runtime VPD
    VPD_RT_GET_ADDR                         = 0x80,
    VPD_RT_WRITE_PNOR                       = 0x81,
    VPD_BLD_RT_IMAGE                        = 0x82,
    VPD_SEND_MBOX_WRITE_MESSAGE             = 0x83,
    VPD_MOD_XXX                             = 0x84,
    VPD_SEND_I2C_LOCK_MSG                   = 0x85,
    VPD_FILL_I2C_LOCK_MSG                   = 0x86,

    // DDIMM VPD
    MOD_OCMBPRESENCEDETECT                  = 0x90,

    // Centaur FRU VPD


};

/**
 * @enum vpdReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum vpdReasonCode
{
    VPD_INVALID_REASONCODE              = VPD_COMP_ID | 0x00,   // Invalid RC
    VPD_INSUFFICIENT_FILE_SIZE          = VPD_COMP_ID | 0x01,
    VPD_OPERATION_NOT_SUPPORTED         = VPD_COMP_ID | 0x02,
    VPD_RECORD_NOT_FOUND                = VPD_COMP_ID | 0x03,
    VPD_KEYWORD_NOT_FOUND               = VPD_COMP_ID | 0x04,
    VPD_RECORD_MISMATCH                 = VPD_COMP_ID | 0x05,
    VPD_INSUFFICIENT_BUFFER_SIZE        = VPD_COMP_ID | 0x06,
    VPD_INVALID_BASIC_MEMORY_TYPE       = VPD_COMP_ID | 0x07,
    VPD_BASIC_MEMORY_TYPE               = VPD_COMP_ID | 0x08,
    VPD_INVALID_SPD_KEYWORD             = VPD_COMP_ID | 0x09,
    VPD_MEMTYPE_NOT_SUPPORTED           = VPD_COMP_ID | 0x0A,
    VPD_KEYWORD_NOT_WRITABLE            = VPD_COMP_ID | 0x0B,
    VPD_NOT_SUPPORTED                   = VPD_COMP_ID | 0x0C,
    VPD_MOD_SPECIFIC_MISMATCH_UMM       = VPD_COMP_ID | 0x0D,
    VPD_MOD_SPECIFIC_MISMATCH_RMM       = VPD_COMP_ID | 0x0E,
    VPD_MOD_SPECIFIC_MISMATCH_CMM       = VPD_COMP_ID | 0x0F,
    VPD_MOD_SPECIFIC_MISMATCH_LRMM      = VPD_COMP_ID | 0x10,
    VPD_MOD_SPECIFIC_UNSUPPORTED        = VPD_COMP_ID | 0x11,
    VPD_SIZE_MISMATCH                   = VPD_COMP_ID | 0x12,
    VPD_INVALID_WRITE_METHOD            = VPD_COMP_ID | 0x13,
    VPD_NULL_ENTRY                      = VPD_COMP_ID | 0x14,
    VPD_UNSUPPORTED_WRITE               = VPD_COMP_ID | 0x15,
    VPD_RT_INVALID_TYPE                 = VPD_COMP_ID | 0x16,
    VPD_RT_CALL_TO_HYPR_FAILED          = VPD_COMP_ID | 0x17,
    VPD_RT_WRITE_NOT_SUPPORTED          = VPD_COMP_ID | 0x18,
    VPD_RT_NOT_INITIALIZED              = VPD_COMP_ID | 0x19,
    VPD_RT_NULL_VPD_PTR                 = VPD_COMP_ID | 0x1a,
    VPD_INSUFFICIENT_SPACE_FOR_IMAGE    = VPD_COMP_ID | 0x1b,
    VPD_MBOX_NOT_SUPPORTED_RT           = VPD_COMP_ID | 0x1c,
    VPD_RECORD_INVALID_VHDR             = VPD_COMP_ID | 0x30,
    VPD_READ_SOURCE_UNRESOLVED          = VPD_COMP_ID | 0x31,
    VPD_REMOVE_PAGES_FAIL               = VPD_COMP_ID | 0x32,
    VPD_UNEXPECTED_TARGET_TYPE          = VPD_COMP_ID | 0x33,
    VPD_WRITE_DEST_UNRESOLVED           = VPD_COMP_ID | 0x34,
    VPD_CACHE_SIZE_EXCEEDED             = VPD_COMP_ID | 0x35,
    VPD_INVALID_LENGTH                  = VPD_COMP_ID | 0x36,
    VPD_RT_NULL_FIRMWARE_REQUEST_PTR    = VPD_COMP_ID | 0x37,
    VPD_RC_XXX                          = VPD_COMP_ID | 0x38,
    VPD_TARGET_CHIP_NOT_FOUND           = VPD_COMP_ID | 0x39,
    VPD_EEPROM_VPD_PRIMARY_INFO_MISSING = VPD_COMP_ID | 0x3a,
    VPD_RT_NODE_TOO_LARGE               = VPD_COMP_ID | 0x3b,
    VPD_CANNOT_WRITE_OVERRIDDEN_VPD     = VPD_COMP_ID | 0x3c,
    VPD_FAILED_TO_RESOLVE_NODE_TARGET   = VPD_COMP_ID | 0x3d,
    VPD_BAD_REC_NUM                     = VPD_COMP_ID | 0x3e,
};


/**
 * @enum VPD::UserDetailsTypes
 *
 * @brief UserDetailsTypes for VPD User Details Section
 *
 */

enum UserDetailsTypes
{
    VPD_UDT_NO_FORMAT       = 0x0,
    VPD_UDT_PARAMETERS      = 0x1,
    VPD_UDT_CONFIG_PARMS    = 0x2,
};

};  // end MVPD

#endif
