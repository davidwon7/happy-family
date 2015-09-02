#include "UnitTestMock.h"
#include "Wife.h"
#include "husband.h"

using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::Return;

class HappyFamilyTest : public ::testing::Test {};

TEST_F(HappyFamilyTest, WifeRequestPurchase) {
  // arrange
  shared_ptr<MockStore> mockStore(new MockStore());
  shared_ptr<MockHusband> mockHusband(new MockHusband());
  vector<shared_ptr<IMilkCarton>> milkCartons;
  vector<shared_ptr<IEgg>> eggs;

  // expect
  EXPECT_CALL(*mockHusband, BuyEggs(_,_)).Times(AtLeast(1))
      .WillRepeatedly(Return(std::vector<std::shared_ptr<IEgg>>()));
  EXPECT_CALL(*mockHusband, BuyMilk(_,_)).Times(AtLeast(1))
      .WillRepeatedly(Return(std::vector<std::shared_ptr<IMilkCarton>>()));

  // act
  Wife wife;

  bool ret = wife.RequestPurchase(mockHusband, mockStore, milkCartons, eggs);

  // verify
  //ASSERT_EQ(ret, true); // Assert that wife is happy
}

TEST_F(HappyFamilyTest, HusbandBuyEggs) {
  // arrange
  shared_ptr<MockStore> mockStore(new MockStore());
  const auto EggsToBuy = 12;

  // expect
  EXPECT_CALL(*mockStore, HasEggs()).Times(AtLeast(1)).WillOnce(Return(true));
  EXPECT_CALL(*mockStore, ProceedPurchaseEggs(_,_))
      .Times(AtLeast(1))
      .WillOnce(Return(true));

  // act
  Husband husband;

  auto eggs = husband.BuyEggs(mockStore, EggsToBuy);

  // verify
  //ASSERT_EQ(eggs.size(), EggsToBuy);  // Assert the number of eggs returned
}

TEST_F(HappyFamilyTest, HusbandBuyMilk) {
  // arrange
  shared_ptr<MockStore> mockStore(new MockStore());

  const auto MilkCartonsToBuy = 1;

  // expect
  EXPECT_CALL(*mockStore, HasMilk()).Times(AtLeast(1)).WillOnce(Return(true));
  EXPECT_CALL(*mockStore, ProceedPurchaseMilk(_,_))
      .Times(AtLeast(1))
      .WillOnce(Return(true));

  // act
  Husband husband;

  auto milkCartons = husband.BuyMilk(mockStore, MilkCartonsToBuy);

  // verify

  // Assert the number of eggs returned
  //ASSERT_EQ(milkCartons.size(), MilkCartonsToBuy);

}
