// build vector class
// 1) RAII
#include "Vector.h";
#include <iostream>
class Vector
{
private:
  std::size_t sz;
  double *arr;
  void swap(Vector &v)
  {
    std::swap(sz, v.sz);
    std::swap(arr, v.arr);
  }

public:
  // constructor
  Vector() : sz{0}, arr{nullptr} {};
  Vector(std::size_t s) : sz{s}, arr{new double[s]} {};
  // copy constructor
  // (with constructor delegation)
  Vector(const Vector &v) : Vector(v.sz)
  {
    std::copy(v.arr, v.arr + v.sz, arr);
  }
  // assignment operator
  // (with copy-swap)
  Vector &operator=(const Vector &v)
  {
    Vector cpy(v);
    swap(cpy);
    return *this;
  }
  // destructor
  ~Vector() { delete[] arr; }
  // GETTER and SETTER
  double operator[](std::size_t s) const
  {
    return arr[s];
  }
  double &operator[](std::size_t s)
  {
    return arr[s];
  }
  std::size_t size() const
  {
    return sz;
  }
};

int main()
{
  Vector v(32);
  for (std::size_t i = 0; i < v.size(); ++i)
  {
    v[i] = i;
  }
  Vector w = v; // copy constructor
  for (std::size_t i = 0; i < w.size(); ++i)
  {
    w[i] = i * i;
  }
  return 0;
}