#include "../inc/easyfind.hpp"

int 	main() {
	std::list<int> list;
	std::vector<int> vector;

	std::cout << "================ Testing empty containers ====================" << std::endl;


	try {	std::cout << "Empty vector: " << easyfind(vector, 42) << std::endl << std::endl;	}
	catch (std::exception &e) {	std::cout << e.what() << std::endl;}
	try {	std::cout << "Empty list: " << easyfind(list, 42) << std::endl;	}
	catch (std::exception &e) {	std::cout << e.what() << std::endl << std::endl;	}
	
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	vector.push_back(11);
	vector.push_back(22);
	vector.push_back(33);
	vector.push_back(44);

	std::cout << "================ Testing Full containers ====================" << std::endl;
	try {	std::cout << "List return : " << easyfind(list, 4) << std::endl;	}
	catch (std::exception &e) {	std::cout << e.what() << std::endl;}
	try {	std::cout << "Vector return : " << easyfind(vector, 33) << std::endl;	}
	catch (std::exception &e) {	std::cout << e.what() << std::endl;}

	return (0);
}