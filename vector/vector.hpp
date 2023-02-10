/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:58:22 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/10 20:30:51 by yel-aziz         ###   ########.fr       */
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
        allocator_type myallocator;
        /////////////////////////////////////////// realocation methode ////////////////////////////////////////////////////////
        value_type *realocation(value_type *oldarray, size_type numbertoalocate)
        {
            value_type *tmp;
            int i;

            tmp = myallocator.allocate(numbertoalocate);
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
        vector(const allocator_type &alloc = allocator_type()) : myallocator(alloc), capacity_(0), size_(0) {}
        vector(const vector &x)
        {
            this->array = x.array;
            this->capacity_ = x.capacity_;
            this->size_ = x.size_;
        }
        vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : myallocator(alloc)
        {
            this->array = myallocator.allocate(n);
            for (int i = 0; i <= (n - 1); i++)
                this->array[i] = val;
        }
        ~vector() { myallocator.destroy(this->array); }
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
                this->array = myallocator.allocate(1);
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
            myallocator.destroy((array + (size_ - 1)));
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
                value_type *new_tab = myallocator.allocate(capacity_);
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
            value_type *new_one = myallocator.allocate(((capacity_ + n) * 2));
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
    
        template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last)
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
                value_type *array_new = myallocator.allocate((this->capacity_ + calcule) * 2);
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
                this->capacity_ *= 2;
                this->array = array_new;
            
        }
        void assign(size_type n, const value_type &val)
        {
            int i = -1;
            if (capacity_ <= n)
            {
                this->array = myallocator.allocate(n);
            }
            while (++i <= n)
                this->array[i] = val;
            size_ = (i - 1);
            capacity_ = n;
        }
        /////////////////////////////////////////////// iterators //////////////////////////////////////////////////////////////
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