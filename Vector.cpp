// build vector class
// 1) RAII
#include "Vector.h";
#include <iostream>
class Vector
{
private:
  std::size_t sz;
  double *arr;

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
  Vector &operator=(const Vector &v)
  {
    if (this == &v)
      return *this;

    delete[] arr;
    sz = v.sz;
    arr = new double[sz];
    std::copy(v.arr, v.arr + v.size(), arr);
    return *this;
  }
  // destructor
  ~Vector() { delete[] arr; }
  // GETTER and SETTER
  double get(std::size_t i) const
  {
    return arr[i];
  }
  double set(std::size_t i, double d)
  {
    arr[i] = d;
  }
  std::size_t size() const
  {
    return sz;
  }
};

int main()
{
  Vector v(32);
  for (std::size_t i = 0; i != v.size(); ++i)
  {
    v.set(i, i * i);
  }
  for (std::size_t i = 0; i != v.size(); ++i)
  {
    std::cout << v.get(i) << " ";
  }
  return 0;
}