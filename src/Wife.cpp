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
    int milkToBuy = 1;
    int eggToBuy = 12;
    bool mistake = false;

    if(store->HasMilk()) {
        milkCartons = husband->BuyMilk(store, milkToBuy);
    }

    if(store->HasEggs()) {
        eggs = husband->BuyEggs(store, eggToBuy);
    }

    mistake = !(milkCartons.size()==milkToBuy && eggs.size()==eggToBuy);

    return mistake;
}
