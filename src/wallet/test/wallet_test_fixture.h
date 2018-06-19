// Copyright (c) 2017-2018 STRAKS developers
// Copyright (c) 2018 SECI Core Developers
// Distributed under the MIT software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

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

