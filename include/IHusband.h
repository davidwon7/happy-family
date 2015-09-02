#ifndef IHUSBAND_H
#define IHUSBAND_H

#include <memory>
#include <vector>

class IEgg;
class IMilkCarton;
class IStore;

class IHusband {
 public:
  virtual ~IHusband() {}
  virtual std::vector<std::shared_ptr<IEgg>> BuyEggs(
      std::shared_ptr<IStore> store, int pieces) = 0;
  virtual std::vector<std::shared_ptr<IMilkCarton>> BuyMilk(
      std::shared_ptr<IStore> store, int cartons) = 0;
};

#endif // IHUSBAND_H
