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
    shared_ptr<MockStore> mockStore(new MockStore());
    vector<shared_ptr<IMilkCarton>> milkCartons;
    vector<shared_ptr<IEgg>> eggs;

    // expect
    EXPECT_CALL(*mockStore, HasMilk()).Times(AtLeast(1)).WillOnce(Return(true));
    EXPECT_CALL(*mockStore, HasEggs()).Times(AtLeast(1)).WillOnce(Return(true));

    // act

    // verify
}

