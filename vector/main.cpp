/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:12:47 by yel-aziz          #+#    #+#             */
/*   Updated: 2023/02/02 16:27:56 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"


int main()
{
    ft::vector<int> a(5000000,51000000);
    ft::vector<int> b(a);
    // a.push_back(55);
    // a.push_back(7);
    // a.push_back(8);
    // a.push_back(81);
    // a.push_back(88);
    // a.assign(10,'g');
    // a.assign(10,5);

    std::cout << "value of a == " << a.array[0] << std::endl;
    std::cout << "value of b == " << b.array[0] << std::endl;
    std::cout << "value of a == " << a.array[1] << std::endl;
    std::cout << "value of a == " << a.array[2] << std::endl;
    std::cout << "value of a == " << a.array[3] << std::endl;

    // std::cout << "value of a == " << a.array[3] << std::endl;
    // std::cout << a.array[1] << std::endl;
}