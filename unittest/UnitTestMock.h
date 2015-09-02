#ifndef UNITTESTMOCK_H
#define UNITTESTMOCK_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "IEgg.h"
#include "IHusband.h"
#include "IMilkCarton.h"
#include "IStore.h"

class MockStore : public IStore {
 public:
  virtual ~MockStore() {}
  MOCK_CONST_METHOD0(HasMilk, bool());
  MOCK_CONST_METHOD0(HasEggs, bool());
  MOCK_METHOD2(ProceedPurchaseEggs,
               bool(std::vector<std::shared_ptr<IEgg>>&, int));
  MOCK_METHOD2(ProceedPurchaseMilk,
               bool(std::vector<std::shared_ptr<IMilkCarton>>&, int));
};

class MockHusband : public IHusband {
 public:
  virtual ~MockHusband() {}
  MOCK_METHOD2(BuyEggs,
               std::vector<std::shared_ptr<IEgg>>(std::shared_ptr<IStore> store,
                                                  int pieces));
  MOCK_METHOD2(BuyMilk, std::vector<std::shared_ptr<IMilkCarton>>(
                            std::shared_ptr<IStore> store, int cartons));
};

#endif // UNITTESTMOCK_H
