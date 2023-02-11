/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/11 20:48:12 by yel-aziz         ###   ########.fr       */
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

  a.push_back(-4944565);
  a.push_back(4);
  
  b.push_back(11);
  b.push_back(19);
  b.push_back(18);
  b.push_back(133);
  std::cout << "capacity b ===== " << b.capacity() << std::endl;
  std::cout << "size b ==== " << b.size() << std::endl;
  it = b.end();

  b.erase(it);

    
  // b.assign(a.begin(),a.end());
  // b.insert(b.begin(),a.begin(),a.end());
  // a.insert(it,10);
  
  std::cout << "capacity " << b.capacity() << std::endl;
  std::cout << "size " << b.size() << std::endl;
  
   for(int i = 0; i < b.size(); i++){
   std::cout << b[i] << std::endl;
   }
}