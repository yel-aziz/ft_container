/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/12 01:33:48 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>


#include <iostream>

int main()
{
  std::vector<char> a;
  std::vector<char>::iterator it;
  std::vector<char>::iterator it_end;
  std::vector<char> b;

  // a.push_back(-4944565);
  // a.push_back(4);
  
  b.push_back('a');
  b.push_back('f');
  b.push_back('e');
  b.push_back('d');
  b.push_back('c');
  b.push_back('b');

  // std::cout << "capacity b ===== " << b.capacity() << std::endl;
  // std::cout << "size b ==== " << b.size() << std::endl;
  it = b.begin();
  it_end = b.end();

  // it++;
  // it_end--;
  // it_end--;
  it_end--;

  b.erase(it,it_end);

    
  // b.assign(a.begin(),a.end());
  // b.insert(b.begin(),a.begin(),a.end());
  // a.insert(it,10);
  
  std::cout << "capacity " << b.capacity() << std::endl;
  std::cout << "size " << b.size() << std::endl;
  
   for(int i = 0; i < b.size(); i++){
   std::cout << b[i] << std::endl;
   }
}