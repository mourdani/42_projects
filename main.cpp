
#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};






#define COUNT (MAX_RAM / (int)sizeof(Buffer))


// diff unit tests between ft::vector and std::vector
int main(void)
{
	std::cout << "sizeof(ft::vector) = " << sizeof(ft::vector<int>) << std::endl;
	std::cout << "sizeof(std::vector) = " << sizeof(std::vector<int>) << std::endl;
	std::cout << "sizeof(ft::vector<int>::iterator) = " << sizeof(ft::vector<int>::iterator) << std::endl;
	std::cout << "sizeof(std::vector<int>::iterator) = " << sizeof(std::vector<int>::iterator) << std::endl;
	std::cout << "sizeof(ft::vector<int>::const_iterator) = " << sizeof(ft::vector<int>::const_iterator) << std::endl;
	std::cout << "sizeof(std::vector<int>::const_iterator) = " << sizeof(std::vector<int>::const_iterator) << std::endl;
	std::cout << "sizeof(ft::vector<int>::reverse_iterator) = " << sizeof(ft::vector<int>::reverse_iterator) << std::endl;
	std::cout << "sizeof(std::vector<int>::reverse_iterator) = " << sizeof(std::vector<int>::reverse_iterator) << std::endl;
	std::cout << "sizeof(ft::vector<int>::const_reverse_iterator) = " << sizeof(ft::vector<int>::const_reverse_iterator) << std::endl;
	std::cout << "sizeof(std::vector<int>::const_reverse_iterator) = " << sizeof(std::vector<int>::const_reverse_iterator) << std::endl;
	std::cout << "sizeof(ft::vector<int>::reference) = " << sizeof(ft::vector<int>::reference) << std::endl;
	std::cout << "sizeof(std::vector<int>::reference) = " << sizeof(std::vector<int>::reference) << std::endl;
	std::cout << "sizeof(ft::vector<int>::const_reference) = " << sizeof(ft::vector<int>::const_reference) << std::endl;
	std::cout << "sizeof(std::vector<int>::const_reference) = " << sizeof(std::vector<int>::const_reference) << std::endl;
	std::cout << "sizeof(ft::vector<int>::pointer) = " << sizeof(ft::vector<int>::pointer) << std::endl;
	std::cout << "sizeof(std::vector<int>::pointer) = " << sizeof(std::vector<int>::pointer) << std::endl;
	

// diff unit tests between ft::vector and std::vector to test iterators
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	ft::vector<int>::iterator ft_it;
	std::vector<int>::iterator std_it;
	ft::vector<int>::const_iterator ft_cit;
	std::vector<int>::const_iterator std_cit;
	ft::vector<int>::reverse_iterator ft_rit;
	std::vector<int>::reverse_iterator std_rit;
	ft::vector<int>::const_reverse_iterator ft_crit;
	std::vector<int>::const_reverse_iterator std_crit;


// diff unit tests between ft::vector and std::vector to test constructors
	ft::vector<int> ft_vec1;
	std::vector<int> std_vec1;
	ft::vector<int> ft_vec2(5);
	std::vector<int> std_vec2(5);
	ft::vector<int> ft_vec3(5, 42);
	std::vector<int> std_vec3(5, 42);
	ft::vector<int> ft_vec4(ft_vec3.begin(), ft_vec3.end());
	std::vector<int> std_vec4(std_vec3.begin(), std_vec3.end());
	ft::vector<int> ft_vec5(std_vec3);
	std::vector<int> std_vec5(std_vec3);
	ft::vector<int> ft_vec6(ft_vec3);
	std::vector<int> std_vec6(ft_vec3);
	ft::vector<int> ft_vec7(ft::vector<int>(5, 42));
	std::vector<int> std_vec7(std::vector<int>(5, 42));
	ft::vector<int> ft_vec8(std::vector<int>(5, 42));
	std::vector<int> std_vec8(std::vector<int>(5, 42));
	ft::vector<int> ft_vec9(ft::vector<int>(5));
	std::vector<int> std_vec9(std::vector<int>(5));
	ft::vector<int> ft_vec10(std::vector<int>(5));
	std::vector<int> std_vec10(std::vector<int>(5));
	
	std::cout << "ft_vec1.size() = " << ft_vec1.size() << std::endl;
	std::cout << "std_vec1.size() = " << std_vec1.size() << std::endl;
	std::cout << "ft_vec2.size() = " << ft_vec2.size() << std::endl;
	std::cout << "std_vec2.size() = " << std_vec2.size() << std::endl;
	std::cout << "ft_vec3.size() = " << ft_vec3.size() << std::endl;
	std::cout << "std_vec3.size() = " << std_vec3.size() << std::endl;
	std::cout << "ft_vec4.size() = " << ft_vec4.size() << std::endl;
	std::cout << "std_vec4.size() = " << std_vec4.size() << std::endl;
	std::cout << "ft_vec5.size() = " << ft_vec5.size() << std::endl;
	std::cout << "std_vec5.size() = " << std_vec5.size() << std::endl;
	std::cout << "ft_vec6.size() = " << ft_vec6.size() << std::endl;
	std::cout << "std_vec6.size() = " << std_vec6.size() << std::endl;
	std::cout << "ft_vec7.size() = " << ft_vec7.size() << std::endl;
	std::cout << "std_vec7.size() = " << std_vec7.size() << std::endl;
	std::cout << "ft_vec8.size() = " << ft_vec8.size() << std::endl;
	std::cout << "std_vec8.size() = " << std_vec8.size() << std::endl;
	std::cout << "ft_vec9.size() = " << ft_vec9.size() << std::endl;
	std::cout << "std_vec9.size() = " << std_vec9.size() << std::endl;
	std::cout << "ft_vec10.size() = " << ft_vec10.size() << std::endl;
	std::cout << "std_vec10.size() = " << std_vec10.size() << std::endl;
	


return 0;
}

