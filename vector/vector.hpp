/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:58:22 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/12 01:34:42 by yel-aziz         ###   ########.fr       */
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
        typedef Allocator                              allocator_type;
        typedef size_t                                 size_type;
        typedef T                                      value_type;
        typedef ft::random_access_iterator<value_type> iterator;
        typedef ft::random_access_iterator<value_type> const_iterator;
        typedef ptrdiff_t                              difference_type;

        // typedef ft::reverse_iterators<iterator>             reverse_iterator;
        // typedef ft::reverse_iterators<const_iterator>       const_reverse_iterator;
        value_type *array;

        size_type size_;
        size_type capacity_;
    private:
        allocator_type ft_allocater;
        /////////////////////////////////////////// realocation methode ////////////////////////////////////////////////////////
        value_type *realocation(value_type *oldarray, size_type numbertoalocate)
        {
            value_type *tmp;
            int i;

            tmp = ft_allocater.allocate(numbertoalocate);
            i = -1;
            while (++i <= capacity_)
                tmp[i] = oldarray[i];

            this->capacity_ = numbertoalocate;
            return (tmp);
        }

    public:
        difference_type diff(iterator it1, iterator it2)
        {
            return it1 - it2;
        }
        ///////////////////////////////////////////// constructors /////////////////////////////////////////////////////////////
        vector(const allocator_type &alloc = allocator_type()) : ft_allocater(alloc), capacity_(0), size_(0) {}
        vector(const vector &x)
        {
            this->array = x.array;
            this->capacity_ = x.capacity_;
            this->size_ = x.size_;
        }
        vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : ft_allocater(alloc)
        {
            this->array = ft_allocater.allocate(n);
            for (int i = 0; i <= (n - 1); i++)
                this->array[i] = val;
        }
        ~vector() { ft_allocater.destroy(this->array); }
        ////////////////////////////////////////// operators overloding ////////////////////////////////////////////////////////
        vector &operator=(const vector &obj)
        {
            if (this == &obj)
                return *this;
            this->array = obj.array;
            return *this;
        }
        const value_type &operator[](std::size_t index) const
        {
            return this->array[index];
        }
        //////////////////////////////////////// insertion methodes ////////////////////////////////////////////////////////////
        void push_back(const value_type &val)
        {
            if (capacity_ == 0)
            {
                this->array = ft_allocater.allocate(1);
                capacity_ = 1;
            }
            else if (capacity_ == size_)
            {
                this->array = realocation(array, (capacity_ * 2));
            }
            array[size_] = val;
            size_++;
        }

        void pop_back()
        {
            ft_allocater.destroy((array + (size_ - 1)));
            size_--;
        }

        iterator insert(iterator pos, const T &value)
        {
            difference_type position = pos - begin();
            if(position > capacity_)
                return begin();
           if(position == size_)
           {
                push_back(value);
           }
    
           else if (position <= size_ && size_ + 1 <= capacity_)
           {
                printf("i'm hereeee\n");
                value_type *new_tab = ft_allocater.allocate(capacity_);
                int j = 0;
                for(int i = 0; i <= size_ ; i++)
                {
                    if(i == position){new_tab[i] = value; i++;}
                    new_tab[i] = array[j++]; 
                }
                //destroy array
                this->array = new_tab;
                this->capacity_ = capacity_ ;
                this->size_++;
           }
   
            return this->begin() + position;
        }

        void insert (iterator pos, size_type n, const value_type& value)
        {
            difference_type posi = pos - this->begin();
            value_type *new_one = ft_allocater.allocate(((capacity_ + n) * 2));
           if (posi <= this->size_ || posi >= this->size_)
           {
                int i = 0;
                int j = 0;
                int k = 0;
                while(i <= size_ + n)
                {
                    if(i == posi)
                    {
                        k = i;
                        while (k < n + i)
                        {
                            new_one[k++] = value;
                        }
                        i = k;
                }
                    new_one[i++] = this->array[j++];
                }
                this->array = new_one;
                this->size_ = (i - 1);
                this->capacity_ = ((capacity_ + n) * 2);
           }
        }
    
        template <class IT>
        void insert (iterator position, IT first, IT last)
        {
            difference_type calcule = last - first;
            if(calcule == 0){return;}
            if( this->size_ == 0 && calcule > 0){
                while (first < last)
                {
                    push_back(*first);
                    first++;
                }
            }
                difference_type posi = position - begin();
                int j = 0;
                value_type *array_new = ft_allocater.allocate((this->capacity_ + calcule) * 2);
                for(int i = 0; i < this->size_; i++){
                    array_new[i] = this->array[j++];
                    if(i == posi){
                        while (first < last)
                        {
                            array_new[i] = *first;
                            first++; i++;
                            this->size_++;
                        }
                        i--;
                        j--;
                    }
                }
                this->capacity_ = ((this->capacity_ + calcule) * 2);
                this->array = array_new;
            
        }
        void assign(size_type n, const value_type &val)
        {
            int i = -1;
            if (capacity_ <= n)
            {
                this->array = ft_allocater.allocate(n);
            }
            while (++i <= n)
                this->array[i] = val;
            size_ = (i - 1);
            capacity_ = n;
        }

        template <class IT>  
        void assign (IT first, IT last)
        {
            int i = 0;
            difference_type lenght = last - first;
            if(lenght >= this->capacity_)
            {
                this->array = ft_allocater.allocate(this->capacity_  * 2);
                this->capacity_ = this->capacity_  * 2;
            }
            while (first <= last){ this->array[i++] = *first; first++;}
            this->size_ = lenght;
        }

        iterator erase (iterator position)
        {
            int i;
            difference_type index = position - begin();
            i = index;
            if (index == this->size_){
                ft_allocater.destroy(this->array + index);
                this->size_--;
            }
            else if (position < end())
            {
                ft_allocater.destroy(this->array + index);
                while (i <= size_)
                {
                    this->array[i] = this->array[i + 1];
                    i++;
                }
                this->size_--;
            }
            return this->array + index;
        }

        iterator erase (iterator first, iterator last)
        {
            difference_type index = first - begin();
            difference_type index_end = last - begin();
            if(index_end <= index)
                return this->array + index;
            difference_type range = last - first;
            int i = index;
            while (index < index_end)
            {
               ft_allocater.destroy(this->array + index);
               index++;
            }
            if(last < end()){
                while (index_end <= this->size_)
                {
                    this->array[i] = this->array[index_end++];
                    i++;
                }
            }
            else{
            while (i <= size_)
            {
                this->array[i] = this->array[i + 1];
                i++;
            }
            }
            this->size_ -= range;
        }
        ////////////////////////////////////////////// iterators //////////////////////////////////////////////////////////////
        iterator begin() { return (iterator(array));}
        const_iterator begin() const { return (iterator(array));}
        const_iterator end() const { return (iterator(this->array + size_));}
        iterator end() { return (iterator(this->array + size_));}
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
        size_type max_size() const { return this->capacity_; }
        // void resize (size_type n, value_type val = value_type()){

        // }

        value_type operator[](size_type n){ return this->array[n];}
    };

}

#endif