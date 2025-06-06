/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:01:58 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/28 15:03:57 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include "iostream"
#include "ostream"
#include "template.tpp"


class Example {
    private:
        int _value;
    public :

    int getValue() const  {return this->_value;}
    Example(void) : _value(0) {}
    Example(int n) : _value(n) {}
    Example & operator= (Example & a) { this->_value = a._value; return *this; }
    bool operator==( Example const & instance ) const { return (this->_value == instance._value); }
    bool operator!=( Example const & instance ) const{ return (this->_value != instance._value); }
    bool operator>( Example const & instance ) const { return (this->_value > instance._value); }
    bool operator<( Example const & instance ) const { return (this->_value < instance._value); }
    bool operator>=( Example const & instance ) const { return (this->_value >= instance._value); }
    bool operator<=( Example const & instance ) const { return (this->_value <= instance._value); }
    int get_value() const { return _value; }
};

std::ostream & operator<<(std::ostream & out, const Example &a) { out << a.getValue(); return out; }

#endif
