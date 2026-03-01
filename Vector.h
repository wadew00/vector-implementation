#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
class Vector
{
public:
  Vector();
  Vector(std::size_t s);
  ~Vector();
  double get(std::size_t i) const;
  void set(std::size_t i, double d);
  std::size_t size() const;
};
#endif