#include "../inc/Span.hpp"

int main()
{
    {
        std::cout << "========== addNumber ===========" << std::endl;
        Span s = Span(6);
        try { 
            std::cout << "Filling span..." << std::endl;
            s.addNumber(6);
            s.addNumber(45);
            s.addNumber(44);
            s.addNumber(1);
            s.addNumber(98);
            s.addNumber(12);
            std::cout << "Should return an error..." << std::endl;
            s.addNumber(120);
        }
        catch (std::length_error &e) { std::cout << e.what() << std::endl;  }
    
        try {   std::cout << "Shortest span : " << s.shortestSpan() << std::endl;  }
        catch (std::length_error &e) { std::cout << e.what() << std::endl;  }
    
        try {   std::cout << "Longest span  : "  << s.longestSpan() << std::endl;  }
        catch (std::length_error &e) { std::cout << e.what() << std::endl;  }
    }

    std::cout << std::endl;
    
    {
        std::cout << "========== addNumbers ===========" << std::endl;
        Span s = Span(6);
        try {  
            std::cout << "Filling span..." << std::endl;
            s.addNumbers(6);
            std::cout << "Should return an error..." << std::endl;
            s.addNumber(42);
        }
        catch (std::length_error &e) { std::cout << e.what() << std::endl;  }
    
        try {   std::cout << "Shortest span : " << s.shortestSpan() << std::endl;  }
        catch (std::length_error &e) { std::cout << e.what() << std::endl;  }
    
        try {   std::cout << "Longest span  : "  << s.longestSpan() << std::endl;  }
        catch (std::length_error &e) { std::cout << e.what() << std::endl;  }
    }

    return 0;
}