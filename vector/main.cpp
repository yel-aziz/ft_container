/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/05 21:58:33 by yel-aziz         ###   ########.fr       */
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

   b.push_back(9);
   
   // b.insert(b.begin(),22);
   std::cout << b[0] << " size == " << b.size() << " cbpbcity "  << *b.insert(b.begin(),22) ;
}