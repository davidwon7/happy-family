#include "UnitTestMock.h"
#include "Wife.h"

using namespace std;
using ::testing::_;
using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::Return;

class HappyFamilyTest : public ::testing::Test { };

TEST_F(HappyFamilyTest, WifeRequestPurchase)
{
    // arrange
    shared_ptr<MockHusband> mockHusband(new MockHusband());
    shared_ptr<MockStore> mockStore(new MockStore());
    shared_ptr<MockMilkCarton> mockMilkCarton(new MockMilkCarton());
    shared_ptr<MockEgg> mockEgg(new MockEgg());
    vector<shared_ptr<IMilkCarton>> milkCartons;
    vector<shared_ptr<IEgg>> eggs;
    milkCartons.push_back(mockMilkCarton);
    for (int i = 0; i < 12; ++i)
        eggs.push_back(mockEgg);

    // expect
    EXPECT_CALL(*mockStore, HasMilk()).Times(AtLeast(1)).WillOnce(Return(true));
    EXPECT_CALL(*mockStore, HasEggs()).Times(AtLeast(1)).WillOnce(Return(true));
    EXPECT_CALL(*mockHusband, BuyEggs(_,_)).Times(Exactly(1)).WillOnce(Return(eggs));
    EXPECT_CALL(*mockHusband, BuyMilk(_,_)).Times(Exactly(1)).WillOnce(Return(milkCartons));

    // act
    Wife wife;
    bool result = wife.RequestPurchase(mockHusband, mockStore, milkCartons, eggs);

    // verify
    ASSERT_TRUE(result);
}

