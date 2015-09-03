#include "husband.h"

#include "IStore.h"
#include "IEgg.h"
#include "IMilkCarton.h"

vector<shared_ptr<IEgg>> Husband::BuyEggs(shared_ptr<IStore> store,
                                          int pieces) {
  vector<shared_ptr<IEgg>> eggs;

  if (store == nullptr) return eggs;

  // If the store has egg then just buy.
  // The husband doesn't care if the correct quantity is bought.
  if (store->HasEggs())
    store->ProceedPurchaseEggs(eggs, pieces);

  return eggs;
}

vector<shared_ptr<IMilkCarton>> Husband::BuyMilk(shared_ptr<IStore> store,
                                                 int cartons) {
  vector<shared_ptr<IMilkCarton>> milkCartons;

  if (store == nullptr) return milkCartons;

  // If the store has milk then just buy.
  // The husband doesn't care if the correct quantity is bought.
  if (store->HasMilk())
    store->ProceedPurchaseMilk(milkCartons, cartons);

  return milkCartons;
}
