# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/perv/p9_ram_getspr.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2016
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG
PROCEDURE=p9_ram_getspr
libp9_ram_getspr_DEPLIBS += p9_ram_core
libp9_ram_getspr_DEPLIBS += p9_spr_name_map
$(call BUILD_PROCEDURE)

