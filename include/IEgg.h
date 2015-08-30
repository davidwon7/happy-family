#pragma once

#include <string>

class IEgg
{
public:
    virtual ~IEgg() {}
    virtual std::string ToString() const = 0;
};

