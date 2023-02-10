/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/10 20:30:00 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>


#include <iostream>

int main()
{
  ft::vector<int> a;
  ft::vector<int>::iterator it;
  ft::vector<int> b;

  // a.push_back(4);




b.push_back(11);


  
  std::cout << "capacity b ===== " << b.capacity() << std::endl;
  std::cout << "size b ==== " << b.size() << std::endl;
  
  //  for(int i = 0; i < a.size(); i++){
  //  std::cout << a[i] << std::endl;
  //  }
  b.insert(b.begin(),a.begin(),a.end());
  // a.insert(it,10);
  
  std::cout << "capacity " << b.capacity() << std::endl;
  std::cout << "size " << b.size() << std::endl;
  
   for(int i = 0; i < b.size(); i++){
   std::cout << b[i] << std::endl;
   }
}