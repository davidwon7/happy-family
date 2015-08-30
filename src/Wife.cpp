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

#if WHAT_HUSBAND_THOUGHT
    if (!store->HasMilk())
        return false;
    if (store->HasEggs())
    {
        milkCartons = husband->BuyMilk(store, 12);
        return milkCartons.size() == 12;
    }
    milkCartons = husband->BuyMilk(store, 1);
    return milkCartons.size() == 1;
#else
    bool ret = false;
    if (store->HasMilk())
    {
        milkCartons = husband->BuyMilk(store, 1);
        ret = milkCartons.size() == 1;
    }
    if (store->HasEggs())
        eggs = husband->BuyEggs(store, 12);

    return ret;
#endif
}
