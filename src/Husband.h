#ifndef HUSBAND_H
#define HUSBAND_H

#include <memory>
#include <vector>

#include "IHusband.h"

class IEgg;
class IMilkCarton;

using namespace std;

class Husband : public IHusband {
 public:
  virtual vector<shared_ptr<IEgg>> BuyEggs(shared_ptr<IStore> store,
                                           int pieces);

  virtual vector<shared_ptr<IMilkCarton>> BuyMilk(shared_ptr<IStore> store,
                                                  int cartons);
};

#endif // HUSBAND_H
