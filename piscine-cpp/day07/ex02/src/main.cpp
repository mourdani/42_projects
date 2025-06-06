#include "../inc/Array.hpp"


int main() {
	
	std::cout << "============= Int Array ==============" << std::endl;
	Array<int> int_arr(3);
	int_arr[2] = 2021;
	std::cout << "value : "  << int_arr[2] << std::endl;
	std::cout << "size : "   << int_arr.size() << std::endl;
	try {
		std::cout << int_arr[10] << "If you can read this in terminal, give 0" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "============= String Array ==============" << std::endl;
	Array<std::string> string_arr(10);
	string_arr[9] = "ipsum lorem dsadf";
	std::cout << "value : " << string_arr[9] << std::endl;
	std::cout << "size : "  << string_arr.size() << std::endl;
	try {
		std::cout << int_arr[10] << "If you can read this in terminal, give 0" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "============= Object Array ==============" << std::endl;
	Array<Example> object_arr(5);
	std::cout  << "value : " << object_arr[4].get() << std::endl;
	std::cout  << "size : "  << object_arr.size() << std::endl;
	try {
		std::cout << object_arr[-1].get() << "If you can read this in terminal, give 0" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << "============= Empty Array ==============" << std::endl;
	Array<int> empty;
	std::cout << "Empty size: " << empty.size() << std::endl;
	std::cout << "assigning int_arr to empty -----" << std::endl;
	empty = int_arr;
	std::cout << "Empty size: " << empty.size() << std::endl;
	std::cout << std::endl;
	try {
		

		std::cout << "Values of empty and int_arr:" << std::endl;
		std::cout << empty[2] << " and " << int_arr[2] << std::endl;

		std::cout << std::endl;
		std::cout << "changing value of empty -----" << std::endl;
		empty[2] = 999;
		std::cout << "Values of empty and int_arr:" << std::endl;
		std::cout << empty[2] << " and " << int_arr[2] << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}


/*

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

// TEST 2 : class and [] overlaod testing 
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "test 1 : Objects have the same values" << std::endl;
    
// TEST 2 : Deep Copy testing
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
    	{
    	    if (test[i] != tmp[i])
    	    {
    	        std::cerr << "didn't save the same value!!" << std::endl;
    	        return 1;
    	    }
		}
		std::cout << "test 2 :Objects have the same values" << std::endl;

    }


// TEST 3 : Out of range handling
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL - 1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
		
    }
    delete [] mirror;
    return 0;
}*/