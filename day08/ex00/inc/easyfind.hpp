#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <list>
# include <algorithm>
# include <vector>
# include <iostream>
# include <iterator>

template <typename T>
int	easyfind(T &container, int n) {
	typename T::iterator iter = std::find(container.begin(), container.end(), n);
	if (iter == container.end())
		throw (std::range_error("Occurence not found"));
	else
		return (std::distance(container.begin(), iter));
}

#endif