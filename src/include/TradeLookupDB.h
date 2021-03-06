/*
 * This file is released under the terms of the Artistic License.  Please see
 * the file LICENSE, included in this package, for details.
 *
 * Copyright (C) 2006-2010 Rilson Nascimento
 *
 * 08 July 2006
 */

#ifndef TRADE_LOOKUP_DB_H
#define TRADE_LOOKUP_DB_H

#include "TxnHarnessDBInterface.h"

//#include "TxnBaseDB.h"
#include "TxnRestDB.h"
#include "DBConnection.h"
using namespace TPCE;

class CTradeLookupDB : public TxnRestDB, public CTradeLookupDBInterface
{
    public:
        //CTradeLookupDB(CDBConnection *pDBConn) : CTxnBaseDB(pDBConn) {};
        CTradeLookupDB(CBrokerageHouse *bh, CDBConnection *pDBConn) : TxnRestDB(bh) {};
        ~CTradeLookupDB() {};

        virtual void DoTradeLookupFrame1(
		int clientId,
		const TTradeLookupFrame1Input *pIn,
                TTradeLookupFrame1Output *pOut);
        virtual void DoTradeLookupFrame2(
		int clientId,
		const TTradeLookupFrame2Input *pIn,
                TTradeLookupFrame2Output *pOut);
        virtual void DoTradeLookupFrame3(
		int clientId,
		const TTradeLookupFrame3Input *pIn,
                TTradeLookupFrame3Output *pOut);
        virtual void DoTradeLookupFrame4(
		int clientId,
		const TTradeLookupFrame4Input *pIn,
                TTradeLookupFrame4Output *pOut);

        // Function to pass any exception thrown inside
        // database class frame implementation
        // back into the database class
        void Cleanup(void* pException) {};
};

#endif	// TRADE_LOOKUP_DB_H
