#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
class Vector
{
public:
  Vector();
  Vector(std::size_t s);
  Vector(const Vector &v);
  Vector &operator=(const Vector &v);
  ~Vector();
  double operator[](std::size_t s);
  std::size_t size() const;
};
#endif