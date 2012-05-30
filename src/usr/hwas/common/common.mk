#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/usr/hwas/common/common.mk $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END
################################################################################
#
#  @file hwas/common.mk
#
#  @brief Common hwas makefile to be included in 
#      hwas/makefile 
#
################################################################################

HWAS_OBJS =       \
    hwas.o

OTHER_OBJS =
     
# Common     
COMMON_HWAS_OBJS = \
    ${HWAS_OBJS}      \
    ${OTHER_OBJS}

