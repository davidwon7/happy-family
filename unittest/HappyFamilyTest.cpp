#include "UnitTestMock.h"
#include "Wife.h"

using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::Return;
using ::testing::ReturnPointee;
using ::testing::Invoke;

class HappyFamilyTest : public ::testing::Test { };

TEST_F(HappyFamilyTest, WifeRequestPurchase)
{
    // arrange
    Wife wife;
    vector<shared_ptr<IEgg>> eggs;
    vector<shared_ptr<IMilkCarton>> milkCartons;

    shared_ptr<MockStore> mockStore(new MockStore());
    shared_ptr<MockHusband> mockHusband(new MockHusband());

    // expect
    EXPECT_CALL(*mockStore, HasMilk()).Times(AtLeast(1)).WillOnce(Return(true));
    EXPECT_CALL(*mockStore, HasEggs()).Times(AtLeast(1)).WillOnce(Return(true));

    EXPECT_CALL(*mockHusband, BuyEggs(_, 12)).Times(AtLeast(1)).WillOnce(Return(vector<shared_ptr<IEgg>>(12)));
    EXPECT_CALL(*mockHusband, BuyMilk(_, 1)).Times(AtLeast(1)).WillOnce(Return(vector<shared_ptr<IMilkCarton>>(1)));

    // act
    bool done = wife.RequestPurchase(mockHusband, mockStore, milkCartons, eggs);

    // verify
    EXPECT_EQ(12, eggs.size());
    EXPECT_EQ(1, milkCartons.size());
    EXPECT_EQ(true, done);
}
