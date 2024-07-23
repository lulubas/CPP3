/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/23 02:27:39 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
    
    std::cout << std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "CREATING PAUL" << std::endl;
    std::cout << "==============" << std::endl;
    ScavTrap Paul;
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING LOUIS" << std::endl;
    std::cout << "==============" << std::endl;
    ScavTrap Louis("Louis");

    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING HENRY" << std::endl;    
    std::cout << "==============" << std::endl;
    ScavTrap Henry(Paul);
   
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING MAX" << std::endl;    
    std::cout << "==============" << std::endl;
    ScavTrap Max; 
    Max = Louis;

    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING EVA" << std::endl;    
    std::cout << "==============" << std::endl;
    ClapTrap Eva("Eva"); 

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
    Max.guardGate();
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;    
    std::cout << "==============" << std::endl;
    
    return 0;
}