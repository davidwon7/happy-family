#include "IHusband.h"
#include "IStore.h"
#include "IMilkCarton.h"
#include "IEgg.h"
#include "Wife.h"
#include "Husband.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;

class Egg : public IEgg {
  virtual string ToString() const { return "Egg"; }
};

class MilkCarton : public IMilkCarton {
  virtual string ToString() const { return "Milk Carton"; }
};

class Store : public IStore {
 public:
  virtual bool HasMilk() const { return true; }
  virtual bool HasEggs() const { return true; }
  virtual bool ProceedPurchaseEggs(vector<shared_ptr<IEgg>>& eggs,
                                   int quantity) {
    // Assume that the store can create eggs out of thin air
    for (auto i = 0; i < quantity; ++i)
      eggs.push_back(make_shared<Egg>());

    // Just make sure the eggs returned is of correct quantity
    return eggs.size() == (size_t)quantity;
  }
  virtual bool ProceedPurchaseMilk(vector<shared_ptr<IMilkCarton>>& milkCartons,
                                   int quantity) {
    // Assume that the store can make milk from water
    for (auto i = 0; i < quantity; ++i)
      milkCartons.push_back(make_shared<MilkCarton>());

    // Make sure the milk cartons returned is of correct quantity
    return milkCartons.size() == (size_t)quantity;
  }
};

int main() {
  Wife wife;
  shared_ptr<IHusband> husband(new Husband());
  shared_ptr<IStore> store(new Store());
  vector<shared_ptr<IMilkCarton>> milkCartons;
  vector<shared_ptr<IEgg>> eggs;

  return wife.RequestPurchase(husband, store, milkCartons, eggs);
}
