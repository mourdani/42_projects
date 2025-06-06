#ifndef RANDOMITE_DECL_CLASS_HPP
# define RANDOMITE_DECL_CLASS_HPP

# include "base.hpp"

namespace ft {

	template <typename Spe>
	class RandIte {
		protected:
		Spe									*_value;

		public:
		typedef Spe						value_type;
		typedef ptrdiff_t				difference_type;

		RandIte(void) : _value(NULL) { return ;};
		RandIte(Spe *src) : _value(src) {	return ;};
		RandIte(const RandIte &src) {	*this = src;};
		virtual ~RandIte(void) {	return ;};
		RandIte	&operator=(RandIte const &rhs) {
			if (this == &rhs)
				return (*this);
			this->_value = rhs._value;
			return (*this);
		};

		bool	operator==(const RandIte &rhs) const {	return (this->_value == rhs._value);};
		bool	operator!=(const RandIte &rhs) const{	return (this->_value != rhs._value);};
		bool	operator<(const RandIte &rhs) const{	return (this->_value < rhs._value);};
		bool	operator<=(const RandIte &rhs) const{	return (this->_value <= rhs._value);};
		bool	operator>(const RandIte &rhs) const{	return (this->_value > rhs._value);};
		bool	operator>=(const RandIte &rhs) const{	return (this->_value >= rhs._value);};

		RandIte<Spe>	&operator++(void) {
			++this->_value;
			return (*this);
		};
		RandIte<Spe>	operator++(int) {
			RandIte<Spe>	tmp(*this);
			++this->_value;
			return (tmp);
		};
		RandIte<Spe>	&operator--(void) {
			--this->_value;
			return (*this);
		};
		RandIte<Spe>	operator--(int) {
			RandIte<Spe>	tmp(*this);
			--this->_value;
			return (tmp);
		};

		difference_type				operator-(const RandIte &rhs) const  {
			return (this->_value - rhs._value);
		};
		RandIte<Spe>			operator+(difference_type n) const {
			return (RandIte(this->_value + n));
		};
		RandIte<Spe>			operator-(difference_type n) const {
			return (RandIte(this->_value - n));
		};
		friend RandIte<Spe>	operator+(difference_type n, const RandIte &rhs)
			{ return rhs.operator+(n); };

		/* Cannnot do reversed subtraction
		friend RandIte<Spe>	operator-(difference_type n, const RandIte &rhs)
			{ return (RandIte(rhs._value - n)); };
		*/

		/* Declared in sub-classes:
		reference	operator*(void) const;
		pointer		operator->(void) const;
		reference			operator+=(difference_type n);
		reference			operator-=(difference_type n);
		reference			operator[](difference_type n);
		*/

	};

}

#endif
