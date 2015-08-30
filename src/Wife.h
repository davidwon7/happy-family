#pragma once

#include <memory>
#include <vector>

class IEgg;
class IHusband;
class IMilkCarton;
class IStore;

class Wife
{
public:
    ~Wife() {}
    bool RequestPurchase(std::shared_ptr<IHusband> husband, std::shared_ptr<IStore> store,
        std::vector<std::shared_ptr<IMilkCarton>>& milkCartons,
        std::vector<std::shared_ptr<IEgg>>& eggs);
};

