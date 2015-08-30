#pragma once

class IMilkCarton
{
public:
    virtual ~IMilkCarton() {}
    virtual std::string ToString() const = 0;
};

