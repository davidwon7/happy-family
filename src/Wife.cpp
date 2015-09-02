#include "Wife.h"
#include "IEgg.h"
#include "IHusband.h"
#include "IMilkCarton.h"
#include "IStore.h"

using namespace std;

bool Wife::RequestPurchase(shared_ptr<IHusband> husband,
                           shared_ptr<IStore> store,
                           vector<shared_ptr<IMilkCarton>>& milkCartons,
                           vector<shared_ptr<IEgg>>& eggs) {
  if (husband == nullptr) return false;
  if (store == nullptr) return false;

  const auto MilkCartonsToBuy = 1;
  const auto EggsToBuy = 12;

  milkCartons = husband->BuyMilk(store, MilkCartonsToBuy);
  eggs = husband->BuyEggs(store, EggsToBuy);

  return milkCartons.size() == MilkCartonsToBuy && eggs.size() == EggsToBuy;
}
