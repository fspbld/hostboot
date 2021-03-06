/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/test/testattrsync.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __TARGETING_TESTATTRSYNC_H
#define __TARGETING_TESTATTRSYNC_H

/**
 *  @file targeting/test/testattrsync.H
 *
 *  @brief All unit tests which test attribute sync
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stdio.h>
#include <sys/time.h>

// CXXTEST
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>

// This component
#include <targeting/common/attributes.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/attrsync.H>
#include <errl/errludtarget.H>
#include <targeting/common/trace.H>
#include <kernel/console.H>
#include <initservice/initserviceif.H>

class AttrSyncTestSuite : public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test sync of targeting attributes to FSP
     */
    void testAttributeSync()
    {
        TS_TRACE(ENTER_MRK "testAttributeSync" );

        using namespace TARGETING;

        AttributeSync l_attrSync;

        TS_TRACE( "Sync PNOR RW" );

        errlHndl_t err = l_attrSync.syncSectionToFsp(
                                    TARGETING::SECTION_TYPE_PNOR_RW );

        if( err )
        {
            if( INITSERVICE::spBaseServicesEnabled() )
            {
                TS_FAIL(" Error returned when syncing SECTION_TYPE_PNOR_RW");
            }
            delete err;
            err = NULL;
        }

        TS_TRACE("Sync PNOR INIT " );

        err = l_attrSync.syncSectionToFsp(
                TARGETING::SECTION_TYPE_HEAP_PNOR_INIT );

        if( err )
        {
            if( INITSERVICE::spBaseServicesEnabled() )
            {
                TS_FAIL(" Error returned when syncing SECTION_TYPE_HEAP_PNOR_INIT"); 
            }
            delete err;
            err = NULL;
        }

        TS_TRACE( "Sync PNOR ZERO INIT" );

        err = l_attrSync.syncSectionToFsp(  
                TARGETING::SECTION_TYPE_HEAP_ZERO_INIT );

        if( err )
        {
           if( INITSERVICE::spBaseServicesEnabled() )
           {
               TS_FAIL(" Error returned when syncing SECTION_TYPE_HEAP_ZERO_INIT"); 
           }
           delete err;
           err = NULL;
        }

    }

    /**
     *  @brief Test sync of targeting attributes from FSP
     */
    void testAttributeSyncFromFsp()
    {
        TS_TRACE(ENTER_MRK "testAttributeSyncFromFsp" );

        using namespace TARGETING;

        AttributeSync l_attrSync;

        errlHndl_t l_errl = NULL;

        do
        {

            // create Hostboot message queue
            msg_q_t l_hbMsgQ = msg_q_create();

            // register Hostboot message queue with mailbox to receive messages
            l_errl = MBOX::msgq_register(MBOX::HB_ATTR_SYNC_MSGQ, l_hbMsgQ);
            if (l_errl)
            {
                TS_FAIL( "Error registering the Hostboot message queue with "
                    "mailbox service."); 
                delete l_errl;
                l_errl = NULL;
                break;
            }

            // these are the sections we want to sync
            SECTION_TYPE section_type[] ={SECTION_TYPE_PNOR_RW,
                                          SECTION_TYPE_HEAP_PNOR_INIT,
                                          SECTION_TYPE_HEAP_ZERO_INIT};

            size_t section_count = sizeof(section_type)/sizeof(section_type[0]);

            // pull all attributes from FSP
            AttributeSync l_Sync;

            for(uint8_t i = 0; i < section_count; i++)
            {
                TS_TRACE( "Syncing section type %d", section_type[i] );

                l_errl = l_Sync.syncSectionFromFsp( section_type[i], l_hbMsgQ );

                if (l_errl)
                {
                    if( INITSERVICE::spBaseServicesEnabled() )
                    {
                        TS_FAIL( "Error returned when syncing section type %d "
                        "from FSP", section_type[i]);
                    }

                    delete l_errl;
                    l_errl = NULL;
                }
            }

            // unregister the Hosboot message queue from the mailbox service.
            MBOX::msgq_unregister(MBOX::HB_ATTR_SYNC_MSGQ);

        } while (0);

        TS_TRACE(EXIT_MRK "testAttributeSyncFromFsp" );
    }
};

#endif // End __TARGETING_TESTTARGETING_H
