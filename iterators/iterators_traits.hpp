/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:02:32 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/03 20:52:54 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>

template <class traits>

class iterators_traits
{
      public:
        typedef typename traits::difference_type             difference_type;
        typedef typename traits::value_type                  value_type;
        typedef typename traits::pointer                     pointer;
        typedef typename traits::reference                   reference;
        typedef typename traits::iterators_category          iterators_category;
};

template <class T>

class iterators_traits<T *>{
    public:
        typedef std::ptrdiff_t                               difference_type;
        typedef T                                            value_type;
        typedef T*                                           pointer;
        typedef T&                                           reference;
        typedef std::random_access_iterator_tag              iterator_category;
};

template <class T>

class iterators_traits<const T *>{
    public:
        typedef std::ptrdiff_t                               difference_type;
        typedef T                                            value_type;
        typedef T*                                           pointer;
        typedef T&                                           reference;
        typedef std::random_access_iterator_tag              iterator_category;
};




#endif