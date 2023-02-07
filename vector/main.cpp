/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/08 00:36:19 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>


#include <iostream>

int main()
{
  ft::vector<int> a;
  ft::vector<int>::iterator it;
   
   a.push_back(55);
   a.push_back(55);
   a.push_back(55);



   // std::cout <<"capayity == " << a.capacity() << std::endl;

   it = a.begin();
   ++it;
   // ++it;

   a.insert(it , 10, 9);

   // std::cout << "size== " << a.size() << std::endl;

   for(int i = 0; i < a.size(); i++){
   std::cout << a[i] << std::endl;
   }
}