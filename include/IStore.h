#pragma once

class IEgg;
class IMilkCarton;

class IStore
{
public:
    virtual ~IStore() {}
    virtual bool HasMilk() const = 0;
    virtual bool HasEggs() const = 0;
    virtual bool ProceedPurchaseEggs(std::vector<std::shared_ptr<IEgg>>& eggs, int quantity) = 0;
    virtual bool ProceedPurchaseMilk(std::vector<std::shared_ptr<IMilkCarton>>& milkCartons, int quantity) = 0;
};
