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
  Vector(Vector &&v);
  Vector &operator=(Vector &&v);
  ~Vector();
  double operator[](std::size_t s) const;
  double &operator[](std::size_t s);
  std::size_t size() const;

  double *begin();
  double *end();
};
#endif