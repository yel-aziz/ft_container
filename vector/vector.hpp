/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:58:22 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/05 21:57:38 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterators/random_iterator_acces.hpp"
namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
class vector
{
    public:
        typedef Allocator                                   allocator_type;
        typedef size_t                                      size_type;
        typedef T                                           value_type;
        typedef ft::random_access_iterator<value_type>      iterator;
        typedef ft::random_access_iterator<value_type>      const_iterator;
        // typedef ft::reverse_iterators<iterator>             reverse_iterator;
        // typedef ft::reverse_iterators<const_iterator>       const_reverse_iterator;
        value_type      *array;
    private:
        allocator_type  myallocator;
        size_type       capacity_;
        size_type       size_;
        /////////////////////////////////////////// realocation methode ////////////////////////////////////////////////////////
        value_type *realocation(value_type *oldarray, size_type numbertoalocate)
        {
            value_type  *tmp;
            int         i;

            tmp = myallocator.allocate(numbertoalocate);
            i = -1;
            while (++i <= capacity_)
                tmp[i] = oldarray[i];
                
            this->capacity_ = numbertoalocate;
            return (tmp);
        }
    public:
    ///////////////////////////////////////////// constructors /////////////////////////////////////////////////////////////
        vector (const allocator_type& alloc = allocator_type()): myallocator(alloc), capacity_(0), size_(0){}
        vector (const vector& x){ this->array = x.array; this->capacity_ = x.capacity_; this->size_ = x.size_;}
        vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): myallocator(alloc)
        {
            this->array = myallocator.allocate(n);
            for(int i = 0; i <= (n - 1); i++)
                this->array[i] = val;
        }
        ~vector(){myallocator.destroy(this->array);}
    ////////////////////////////////////////// operators overloding ////////////////////////////////////////////////////////
        vector &operator=(const vector &obj)
        {
            if (this == &obj)
                return *this;
            this->array = obj.array;
            return *this;
        }
        const value_type& operator[](std::size_t index) const
        {
            return this->array[index];
        }
    //////////////////////////////////////// insertion methodes ////////////////////////////////////////////////////////////
        void push_back (const value_type& val)
        {
            if (capacity_ == 0) { array = myallocator.allocate(1); capacity_ = 1;}
            else if (capacity_ == size_){ array = realocation(array, (capacity_ * 2));}
            array[size_] = val; size_++;
        }
        
        void pop_back()
        {
            myallocator.destroy((array + (size_ - 1)));
            size_--;
        }

        iterator insert( const_iterator pos, const T& value )
        {
            // if( pos < 0) {return ;}
            if(pos >= this->end()) { this->array = realocation(this->array,(capacity_ * 2));
                *(this->array + pos ) =  value;
                }
            // else if(pos < this->end())
            // {
            //     *(this->array + pos ) =  value;
            // }
            return end() - pos;
        }
        
        void assign (size_type n, const value_type& val)
        {
            int i = -1;
            if(capacity_ <= n) {this->array = myallocator.allocate(n);}
            while (++i <= n)
                this->array[i] = val;
            size_ = (i - 1);
            capacity_ = n;
        }
    /////////////////////////////////////////////// iterators //////////////////////////////////////////////////////////////
        iterator begin(){ return(iterator(array));}
        const_iterator begin() const {return(iterator(array));}
        const_iterator end() const{return(iterator(array + size_));}
        iterator end(){return(iterator(array + size_));}
        // reverse_iterator rbegin(){return(this->array[size_]);}
        // const_reverse_iterator rbegin() const {return(this->array[size_]);}
        // reverse_iterator rend(){return(this->array[0]);}
        // const_reverse_iterator rend() const{return(this->array[0]);}
    ///////////////////////////////////////////// size /////////////////////////////////////////////////////////////////////
        size_type size() const
        {
            return this->size_;
        }
        size_type capacity() const
        {
            return this->capacity_;
        }
        size_type max_size() const { return this->capacity_;}
        // void resize (size_type n, value_type val = value_type()){
            
        // }
        
    // value_type operator[](size_type n){ return this->array[n];}
};

}


#endif