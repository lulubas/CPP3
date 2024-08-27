/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/27 18:02:16 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
    
    std::cout << std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "CREATING PAUL" << std::endl;
    std::cout << "==============" << std::endl;
    ClapTrap Paul;
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING LOUIS" << std::endl;
    std::cout << "==============" << std::endl;
    ClapTrap Louis("Louis");

    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING HENRY" << std::endl;    
    std::cout << "==============" << std::endl;
    ClapTrap Henry(Paul);
   
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING MAX" << std::endl;    
    std::cout << "==============" << std::endl;
    ClapTrap Max; 
    Max = Louis;

    Paul.getInfo();
    Louis.getInfo();
    Henry.getInfo();
    Max.getInfo();
    
    Paul.attack("another");
    Louis.attack("Default");
    Louis.beRepaired(3);
    Louis.takeDamage(100);

    Louis.getInfo();
    
    Paul.attack("Another Claptrap");
    Louis.attack("Paul");
    
    std::cout << std::endl;

    std::cout << "==============" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;    
    std::cout << "==============" << std::endl;
    
    return 0;
}