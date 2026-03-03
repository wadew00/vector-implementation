#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <algorithm>
#include <utility>
template <typename T>
class Vector
{
private:
  std::size_t sz;
  std::size_t capacity;
  T *arr;
  void swap(Vector &v)
  {
    std::swap(sz, v.sz);
    std::swap(arr, v.arr);
    std::swap(capacity, v.capacity);
  }
  void grow(std::size_t new_capacity)
  {
    if (capacity >= new_capacity)
      return;
    T *new_array = new T[new_capacity];
    std::move(arr, arr + sz, new_array);
    delete[] arr;
    arr = new_array;
    capacity = new_capacity;
  }

public:
  // constructor
  Vector() : sz{0}, capacity{0}, arr{nullptr} {};
  Vector(std::size_t c) : sz{0}, capacity{c}, arr{new T[c]} {};
  // copy constructor
  // (with constructor delegation)
  Vector(const Vector &v) : Vector(v.capacity)
  {
    sz = v.sz;
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
    if (this == &v)
      return *this;
    swap(v);
    return *this;
  }
  // destructor
  ~Vector() { delete[] arr; }
  // GETTER and SETTER
  const T &operator[](std::size_t s) const
  {
    return arr[s];
  }
  T &operator[](std::size_t s)
  {
    return arr[s];
  }
  std::size_t size() const
  {
    return sz;
  }
  std::size_t capacity_get() const
  {
    return capacity;
  }
  // Iterator
  const T *begin() const
  {
    return arr;
  }
  const T *end() const
  {
    return arr + sz;
  }
  T *begin() { return arr; }
  T *end() { return arr + sz; }
  void push_back(const T &element)
  {
    if (capacity == 0)
    {
      grow(1);
    }
    else if (sz >= capacity)
    {
      grow(2 * capacity);
    }

    arr[sz++] = element;
  }
};
#endif