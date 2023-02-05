/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/05 22:57:37 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>


#include <iostream>

int main()
{
   // std::vector<int> a;

   // a.push_back(9);
   // a.insert(a.begin(),22);
   // a.insert(a.begin(),22);
   // std::cout << a[0] << " size == " << a.size() << " capacity "  << a.capacity();
   // /////
   ft::vector<int> b;
   ft::vector<int>::iterator it;

   b.push_back(9);
   it = b.begin();
   // int a = *it;
   
   // b.insert(it,22);
  
   // b.insert(b.begin(),22);
   std::cout << " size == " <<  b.diff(b.begin(),it);
}