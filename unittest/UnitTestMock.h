#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "IEgg.h"
#include "IHusband.h"
#include "IMilkCarton.h"
#include "IStore.h"
#include "vector"

using namespace std;

class MockStore : public IStore
{
public:
    virtual ~MockStore() {}
    MOCK_CONST_METHOD0(HasMilk, bool());
    MOCK_CONST_METHOD0(HasEggs, bool());
    MOCK_METHOD2(ProceedPurchaseEggs, bool(std::vector<std::shared_ptr<IEgg>>&, int));
    MOCK_METHOD2(ProceedPurchaseMilk, bool(std::vector<std::shared_ptr<IMilkCarton>>&, int));
};

class MockHusband : public IHusband
{
public:
    virtual ~MockHusband() {}
    MOCK_METHOD2(BuyEggs, vector<shared_ptr<IEgg>>(shared_ptr<IStore>, int));
    MOCK_METHOD2(BuyMilk, vector<shared_ptr<IMilkCarton>>(shared_ptr<IStore>, int));
};
