/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/23 02:35:48 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    
    std::cout << std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "CREATING PAUL" << std::endl;
    std::cout << "==============" << std::endl;
    DiamondTrap Paul;
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING LOUIS" << std::endl;
    std::cout << "==============" << std::endl;
    DiamondTrap Louis("Louis");

    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING HENRY" << std::endl;    
    std::cout << "==============" << std::endl;
    DiamondTrap Henry(Paul);
   
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING MAX" << std::endl;    
    std::cout << "==============" << std::endl;
    DiamondTrap Max; 
    Max = Louis;

    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING EVA" << std::endl;    
    std::cout << "==============" << std::endl;
    FragTrap Eva("Eva"); 

    Paul.getInfo();
    Louis.getInfo();
    Henry.getInfo();
    Max.getInfo();
    Eva.getInfo();
    
    Paul.attack("Louis");
    Louis.attack("Default_1");
    Louis.beRepaired(3);
    Louis.takeDamage(100);

    Louis.getInfo();
    Henry.getInfo();

    Paul.attack("Eva");
    Eva.beRepaired(100);    
    Eva.attack("Default");

    Paul.getInfo();
    Eva.getInfo();
    
    Paul.attack("Louis");
    Louis.attack("Louis");
    Max.attack("Random");

    std::cout << std::endl;
    Paul.guardGate();
    Paul.highFivesGuys();
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;    
    std::cout << "==============" << std::endl;
    
    return 0;
}