#include "Wife.h"
#include "IEgg.h"
#include "IHusband.h"
#include "IMilkCarton.h"
#include "IStore.h"

using namespace std;

bool Wife::RequestPurchase(shared_ptr<IHusband> husband, shared_ptr<IStore> store,
                           vector<shared_ptr<IMilkCarton>>& milkCartons,
                           vector<shared_ptr<IEgg>>& eggs)
{
    if (husband == nullptr)
        return false;
    if (store == nullptr)
        return false;

    // TODO
    if(store->HasMilk()) {
        milkCartons = husband->BuyMilk(store, 1);
    }

    if(store->HasEggs()) {
        eggs = husband->BuyEggs(store, 12);
    }

    return milkCartons.size()==1 && eggs.size()==12;
}
