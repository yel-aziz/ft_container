/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator_acces.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:37:22 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/05 21:35:40 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCES_ITERATOR_HPP
#define RANDOM_ACCES_ITERATOR_HPP

#include <iostream>


namespace ft{
  
template<class T>
            
  
class random_access_iterator{
    
    private:
    public:
        T*                                      vector_pointer;
        typedef T                               value_type;
        typedef T&                              reference;
        typedef T*                              pointer;
        typedef ptrdiff_t                       difference_type;
        typedef std::random_access_iterator_tag iterator_category;

        /////////////////////////////////////////////////////////////////////////////constructers//////////////////////////////////////////////////////////////////
          random_access_iterator(){}
          random_access_iterator(const random_access_iterator& obj) {vector_pointer = obj.vector_pointer;}
          random_access_iterator(pointer add):vector_pointer(add){}
        
        //////////////////////////////////////////////////////////////////////////////operators////////////////////////////////////////////////////////////////////
        T& operator*() const {return(this->*vector_pointer);} 
        T& operator[](difference_type n) const { return(*(this->vector_type + n));}
        random_access_iterator& operator++() {vector_pointer++; return(*this);}
        random_access_iterator operator++(int) {random_access_iterator *oldValue = vector_pointer; vector_pointer++; return(oldValue);}
        random_access_iterator& operator--(){vector_pointer--; return(*this);}
        random_access_iterator operator--(int) { random_access_iterator *oldValue = vector_pointer; vector_pointer--; return(oldValue);}
        random_access_iterator operator+(difference_type n) const {random_access_iterator *position = (*this + n); return(position);}
        random_access_iterator operator-(difference_type n) const {random_access_iterator *position = (*this - n); return(position);}
        random_access_iterator &operator+=(int n) { (this->vector_pointer + n); return(*this);}
        random_access_iterator &operator-=(int n) { (this->vector_pointer - n); return(*this);}
};
}

        // template<typename Template1>  bool operator==(const ft::random_access_iterator<Template1> &obj1, const ft::random_access_iterator<Template2> &obj2) {return (obj1.vector_pointer == obj2.vector_pointer);}
	    //  template<typename Template1, typename Template2> bool operator!=(const ft::random_access_iterator<Template1> &obj1, const ft::random_access_iterator<Template2> &obj2) {return (obj1.vector_pointer != obj2.vector_pointer);}
	    template<typename Template1>
        bool operator<(const ft::random_access_iterator<Template1> &obj1, const ft::random_access_iterator<Template1> &obj2)  {return (obj1.vector_pointer <  obj2.vector_pointer);}
	    template<typename Template1>
        bool operator<=(const ft::random_access_iterator<Template1> &obj1, const ft::random_access_iterator<Template1> &obj2) {return (obj1.vector_pointer <= obj2.vector_pointer);}
	    template<typename Template1>
        bool operator>(const ft::random_access_iterator<Template1> &obj1, const ft::random_access_iterator<Template1> &obj2)  {return (obj1.vector_pointer >  obj2.vector_pointer);}
	    template<typename Template1>
        bool operator>=(const ft::random_access_iterator<Template1> &obj1, const ft::random_access_iterator<Template1> &obj2) {return (obj1.vector_pointer >= obj2.vector_pointer);}
  
#endif