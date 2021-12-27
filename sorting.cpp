#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>

template<typename T>
void print(const T& container)
{
    std::copy(container.begin(), container.end(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    std::cout << '\n';
}

template<typename T>
void test_sort(T container)
{
    std::cout << "Before sort():\n";
    print(container);
    
    std::sort(container.begin(), container.end());
    
    std::cout << "After sort():\n";
    print(container);
}

template<typename T>
void test_partial_sort(T container, int middle_elem_offset)
{
    assert(middle_elem_offset < container.size());
    
    std::cout << "Before partial_sort():\n";
    print(container);
    
    std::partial_sort(container.begin(), container.begin() + middle_elem_offset, container.end());
    
    std::cout << "After partial_sort():\n";
    print(container);
}

template<typename T>
void test_heap();

int main()
{
    std::vector<int> vec  = {20, 18, 35, 41, 5, 12, 3, 7};
    test_sort(vec);
    
    test_partial_sort(vec, 3);
    test_partial_sort(vec, 7);
    
    return 0;
}