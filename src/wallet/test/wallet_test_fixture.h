// Copyright (c) 2017-2018 SECI developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SECI_WALLET_TEST_FIXTURE_H
#define SECI_WALLET_TEST_FIXTURE_H

#include "test/test_seci.h"

/** Testing setup and teardown for wallet.
 */
struct WalletTestingSetup: public TestingSetup {
    WalletTestingSetup(const std::string& chainName = CBaseChainParams::MAIN);
    ~WalletTestingSetup();
};

#endif

