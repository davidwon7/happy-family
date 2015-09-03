#ifndef IMILKCARTON_H
#define IMILKCARTON_H

class IMilkCarton {
 public:
  virtual ~IMilkCarton() {}
  virtual std::string ToString() const = 0;
};

#endif // IMILKCARTON_H
