#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "IEgg.h"
#include "IHusband.h"
#include "IMilkCarton.h"
#include "IStore.h"

class MockStore : public IStore
{
public:
    virtual ~MockStore() {}
    MOCK_CONST_METHOD0(HasMilk, bool());
    MOCK_CONST_METHOD0(HasEggs, bool());
    MOCK_METHOD2(ProceedPurchaseEggs, bool(std::vector<std::shared_ptr<IEgg>>&, int));
    MOCK_METHOD2(ProceedPurchaseMilk, bool(std::vector<std::shared_ptr<IMilkCarton>>&, int));
};
