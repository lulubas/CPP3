/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/28 17:04:56 by lbastien         ###   ########.fr       */
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
    ScavTrap Max; 

    Paul.getInfo();
    Louis.getInfo();
    Henry.getInfo();
    Max.getInfo();
    
    Paul.attack("Another Diamond Trap");
    Max.attack("Alexis");

    Paul.whoAmI();
    Louis.whoAmI();

    std::cout << std::endl;
    Paul.guardGate();
    Paul.highFivesGuys();
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;    
    std::cout << "==============" << std::endl;
    
    return 0;
}