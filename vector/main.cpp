/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/06 19:01:28 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>


#include <iostream>

int main()
{
   
   ft::vector<int> b;
   ft::vector<int>::iterator it;
   ft::vector<int>::iterator it_end;
   ft::vector<int>::iterator::difference_type a;

   b.push_back(9);
   b.push_back(9);
   b.push_back(9);
   b.push_back(9);
   b.push_back(9);
   b.push_back(9);

   it = b.begin();
   it_end = b.end();
   // int a = b.diff(it_end,it);
   // std::cout << &(*it_end) - &(*it) << std::endl;
   // std::cout <<  it_end - it  << std::endl;
   a = it_end - it;

   std::cout <<  " iterator position == " << a << std::endl;

   // std::cout << " 0 ==  == " << b[0] << "\n";
   // std::cout << " 1 ==  " << b[1]<< "\n";
   // std::cout << " 2 ==  " << b[2]<< "\n";
   // std::cout << " 3 ==  " << b[3]<< "\n";

}