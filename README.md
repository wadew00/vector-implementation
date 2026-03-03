
# Custom Vector Implementation (C++)

This project is a simplified reimplementation of `std::vector` written in c++.

The purpose of this project is to better practice:

- Dynamic memory management
- The Rule of Five
- Move semantics
- Resizing
- Iterator support
- Generic coding in c++ with templates

---

## Features

- Dynamic array with automatic capacity growth (doubling strategy)
- `push_back(const T&)`
- Copy and move constructors
- Copy and move assignments
- `operator[]` overload
- `size()`
- `capacity_get()`
- Range-based for loop support with  (`begin()` / `end()`)
- Supports nested vectors (`Vector<Vector<T>>`)

---

## Example Usage

### Basic Usage
Basic usage has been provided in main.cpp.  You should just include the Vector.h file in your project if you want to test yourself.
