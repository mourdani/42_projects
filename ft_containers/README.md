# ft_containers

ft_containers is a collection of custom implementations of the C++ STL containers: vector, map, and stack. The project is implemented in C++98.

## Requirements
- The namespace for all implementations is ft.
- Inner data structures used in the containers must be logical and justified.
- The number of public functions and variables must be limited and each must be justified.
- All member functions, non-member functions, and overloads of the standard containers are expected.
- Original naming and attention to detail must be followed.
- If the container has an iterator system, it must be implemented.
- The std::allocator must be used.
- The keyword friend is allowed for non-member overloads, but each use must be justified.
- The keyword friend is also allowed for the implementation of std::map::value_compare.

## Included Containers
ft::vector
ft::map
ft::stack (uses ft::vector as the underlying container)

## Included Utilities
std::iterator_traits
std::reverse_iterator
std::enable_if
std::is_integral
std::equal and/or std::lexicographical_compare
std::pair
std::make_pair

## Testing
Tests are provided in a main.cpp file. To test the custom containers, run the binary with ft::<container>. A separate binary that uses the STL containers is also provided for comparison. Outputs and performance/timing should be compared.

## Building
A Makefile is provided to build the project. Simply run make to build the project.

## Usage
All containers are in the ft namespace and can be used like their standard counterparts. For example, to create a vector of integers:

ft::vector<int> my_vec;

## Note
The vector<bool> specialization is not implemented in this project.
