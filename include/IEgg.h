#ifndef IEGG_H
#define IEGG_H

#include <string>

class IEgg {
 public:
  virtual ~IEgg() {}
  virtual std::string ToString() const = 0;
};

#endif // IEGG_H
