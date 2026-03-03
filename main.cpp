#include <iostream>
#include <fstream>
#include "Vector.h"

int main()
{
  std::ofstream out("results.txt");

  // Test 1: push_back and growth
  Vector<int> v;
  for (int i = 1; i <= 10; ++i)
    v.push_back(i);

  out << "Test 1: push_back\n";
  out << "Size: " << v.size() << "\n";
  out << "Capacity: " << v.capacity_get() << "\n";
  out << "Elements: ";
  for (std::size_t i = 0; i < v.size(); ++i)
    out << v[i] << " ";
  out << "\n\n";

  // Test 2: Copy constructor
  Vector<int> copy(v);
  out << "Test 2: Copy constructor\n";
  out << "Copy elements: ";
  for (std::size_t i = 0; i < copy.size(); ++i)
    out << copy[i] << " ";
  out << "\n\n";

  // Modify original to ensure deep copy
  v[0] = 100;
  out << "After modifying original v[0] = 100\n";
  out << "Original first element: " << v[0] << "\n";
  out << "Copy first element: " << copy[0] << "\n\n";

  // Test 3: Move constructor
  Vector<int> moved(std::move(v));
  out << "Test 3: Move constructor\n";
  out << "Moved size: " << moved.size() << "\n";
  out << "Moved elements: ";
  for (std::size_t i = 0; i < moved.size(); ++i)
    out << moved[i] << " ";
  out << "\n\n";

  // Test 4: Copy assignment
  Vector<int> assign;
  assign = copy;
  out << "Test 4: Copy assignment\n";
  out << "Assigned elements: ";
  for (std::size_t i = 0; i < assign.size(); ++i)
    out << assign[i] << " ";
  out << "\n\n";

  // Test 5: Move assignment
  Vector<int> moveAssign;
  moveAssign = std::move(copy);
  out << "Test 5: Move assignment\n";
  out << "Move-assigned elements: ";
  for (std::size_t i = 0; i < moveAssign.size(); ++i)
    out << moveAssign[i] << " ";
  out << "\n\n";
  // Test 6: for each
  out << "Test 6: for each\n";
  out << "Elements from for each statement: ";
  for (auto i : moved)
  {
    out << i << " ";
  }
  out << "\n\n";

  // Test 7: Inner vectors
  out << "Last test: Inner vectors\n";
  Vector<Vector<std::string>> vv;

  Vector<std::string> inner_1;
  inner_1.push_back("inner_1_first_element");
  inner_1.push_back("inner_1_second_element");
  inner_1.push_back("inner_1_third_element");

  Vector<std::string> inner_2;
  inner_2.push_back("inner_2_first_element");
  inner_2.push_back("inner_2_second_element");
  inner_2.push_back("inner_2_third_element");

  Vector<std::string> inner_3;
  inner_3.push_back("inner_3_first_element");
  inner_3.push_back("inner_3_second_element");
  inner_3.push_back("inner_3_third_element");
  vv.push_back(inner_1);
  vv.push_back(inner_2);
  vv.push_back(inner_3);

  out << "Outer size: " << vv.size() << "\n";
  out << "Outer capacity: " << vv.capacity_get() << "\n";

  // Print as rows
  out << "Contents:\n";
  std::size_t row_index = 0;

  for (const auto &row : vv)
  {
    out << "  row " << row_index++
        << " (size=" << row.size()
        << ", cap=" << row.capacity_get() << "): ";

    for (const auto &value : row)
    {
      out << value << " ";
    }

    out << "\n";
  }

  // Verify deep copy behavior: modify original 'a' after push_back
  inner_1[0] = "inner_1_first_modified";
  out << "After modifying original 'inner_1[0]=inner_1_first_modified' (should NOT affect vv[0][0]):\n";
  out << "  inner_1[0] = " << inner_1[0] << "\n";
  out << "  vv[0][0] = " << vv[0][0] << "\n";

  // Modify an element inside vv and show it changes there
  vv[1][1] = "inner_2_second_modified_by_vv";
  out << "After modifying vv[1][1]=inner_2_second_modified_by_vv:\n";
  out << "  vv[1]: ";
  for (std::size_t j = 0; j < vv[1].size(); ++j)
    out << vv[1][j] << " ";
  out << "\n";
  out.close();
  return 0;
}