/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/06 00:32:29 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>


#include <iostream>

int main()
{
   // std::vector<int> a;
   // std::vector<int>::iterator it;

   //  a.push_back(9);
   // a.push_back(9);
   // it = a.begin();

   // std::cout << " size == " <<  a.diff(a.end(),it) << "\n";


   // a.push_back(9);
   // a.insert(a.begin(),22);
   // a.insert(a.begin(),22);
   // std::cout << a[0] << " size == " << a.size() << " capacity "  << a.capacity();
   // /////
   ft::vector<int> b;
   ft::vector<int>::iterator it;

   b.push_back(9);
   b.push_back(9);
   it = b.begin();
   
   b.insert(it,555);
   // int a = *it;
   
   // b.insert(it,22);
  
   // b.insert(b.begin(),22);
   std::cout << " size == " << b[0];
   // std::cout << " size == " <<  b[2];
}