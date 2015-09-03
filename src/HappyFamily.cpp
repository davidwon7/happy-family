#include "IHusband.h"
#include "IStore.h"
#include "IMilkCarton.h"
#include "IEgg.h"
#include "Wife.h"
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Husband : public IHusband
{
public:
    virtual vector<shared_ptr<IEgg>> BuyEggs(shared_ptr<IStore> store, int pieces)
    {
        vector<shared_ptr<IEgg>> eggs;
        // TODO
        if(store->HasEggs()) {
            bool status = store->ProceedPurchaseEggs(eggs, pieces);

            if(status)
                cout << "All eggs are bought." << endl;
            else
                cout << "Insufficient eggs." << endl;
        }
        return eggs;
    }
    virtual vector<shared_ptr<IMilkCarton>> BuyMilk(shared_ptr<IStore> store, int cartons)
    {
        vector<shared_ptr<IMilkCarton>> milkCartons;
        // TODO
        if(store->HasMilk()) {
            bool status = store->ProceedPurchaseMilk(milkCartons, cartons);

            if(status)
                cout << "All milks are bought." << endl;
            else
                cout << "Insufficient milk." << endl;
        }
        return milkCartons;
    }
};

class Egg : public IEgg
{
    virtual string ToString() const
    {
        return "Egg";
    }
};

class MilkCarton : public IMilkCarton
{
    virtual string ToString() const
    {
        return "Milk Carton";
    }
};

class Store : public IStore
{
public:
    virtual bool HasMilk() const
    {
        return true;
    }
    virtual bool HasEggs() const
    {
        return true;
    }
    virtual bool ProceedPurchaseEggs(vector<shared_ptr<IEgg>>& eggs, int quantity)
    {
        // TODO
        try {
            for(int i=0; i<quantity; i++) {
                shared_ptr<IEgg> egg(new Egg());
                eggs.push_back(egg);
            }
        } catch(const bad_alloc& e1) {
            cout << "There was a memory error." << endl;
        } catch(const exception& e2) {
            cout << "There was an error." << endl;
        }

        return eggs.size() == (size_t)quantity;
    }
    virtual bool ProceedPurchaseMilk(vector<shared_ptr<IMilkCarton>>& milkCartons, int quantity)
    {
        // todo
        try {
            for(int i=0; i<quantity; i++) {
                shared_ptr<IMilkCarton> milk(new MilkCarton());
                milkCartons.push_back(milk);
            }
        } catch(const bad_alloc& e1) {
            cout << "There was a memory error." << endl;
        } catch(const exception& e2) {
            cout << "There was an error." << endl;
        }

        return milkCartons.size() == (size_t)quantity;
    }
};

int main()
{
    Wife wife;
    shared_ptr<IHusband> husband(new Husband());
    shared_ptr<IStore> store(new Store());
    vector<shared_ptr<IMilkCarton>> milkCartons;
    vector<shared_ptr<IEgg>> eggs;
    return wife.RequestPurchase(husband, store, milkCartons, eggs);
}

