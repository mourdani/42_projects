/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 02:16:01 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/25 02:16:03 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

class Base {public: virtual ~Base(void){}};

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base * generate(void)
{
	int ret = rand() % 3;
	if (ret == 0)
		return static_cast<Base *>(new A());
	else if (ret == 1)
		return static_cast<Base *>(new B());
	else
		return static_cast<Base *>(new C());
}

void identify(Base * p)
{
	A * a = dynamic_cast<A *>(p);
	B * b = dynamic_cast<B *>(p);
	C * c = dynamic_cast<C *>(p);
    (void)a;
    (void)b;
    (void)c;
	if (a)
        std::cout << "class A" << std::endl;
    else if (b)
		std::cout << "class B" << std::endl;
	else if (c)
		std::cout << "class C" << std::endl;
	else
		std::cout << "Can not identify this type" << std::endl;
    
}

void identify(Base & p)
{

	try {
		A & a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "class A" << std::endl;
	}
	catch (std::exception &e){
	}
	try {
		B & b = dynamic_cast<B &>(p);
        (void)b;
		std::cout << "class B" << std::endl;
	}
	catch (std::exception &e){
	}
	try {
		C & c = dynamic_cast<C &>(p);
        (void)c;
		std::cout << "class C" << std::endl;
	}
	catch (std::exception &e){
	}
}

int main(void)
{
	srand(time(NULL));

	Base *ptr = generate();
	Base & ref = *ptr;

	std::cout << "ptr : ";
	identify(ptr);
    std::cout << "ref : ";
	identify(ref);

	delete ptr;
	return 0;
}
