/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:01:58 by mourdani          #+#    #+#             */
/*   Updated: 2022/12/28 15:02:05 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_TPP
#define TEMPLATE_TPP

template <typename T>
T swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
  return (temp);
}

template <typename T>
T max(T a, T b) {
  return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
  return (a > b ? b : a);
}

#endif

