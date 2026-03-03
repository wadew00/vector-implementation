#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
template <typename T>
class Vector
{
private:
  std::size_t sz;
  T *arr;
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
  // move constructor
  Vector(Vector &&v) : Vector()
  {
    swap(v);
  }
  // move assignment
  Vector &operator=(Vector &&v)
  {
    swap(v);
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
  // Iterator
  double *begin()
  {
    return arr;
  }
  double *end()
  {
    arr + sz;
  }
};
#endif