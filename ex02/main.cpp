/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/27 18:41:52 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main(void) {
    
    std::cout << std::endl;
    
    std::cout << "==============" << std::endl;
    std::cout << "CREATING PAUL" << std::endl;
    std::cout << "==============" << std::endl;
    FragTrap Paul;
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING LOUIS" << std::endl;
    std::cout << "==============" << std::endl;
    FragTrap Louis("Louis");

    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING HENRY" << std::endl;    
    std::cout << "==============" << std::endl;
    FragTrap Henry(Paul);
   
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "CREATING MAX" << std::endl;    
    std::cout << "==============" << std::endl;
    ScavTrap Max;

    Paul.getInfo();
    Louis.getInfo();
    Henry.getInfo();
    Max.getInfo();
    
    Paul.attack("FragTrap");
    Louis.attack("Max");
    Louis.beRepaired(15);
    Louis.takeDamage(25);

    Paul.getInfo();
    Louis.getInfo();
    
    std::cout << std::endl;
    Paul.highFivesGuys();
    Max.guardGate();
    
    std::cout << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << "DESTRUCTORS" << std::endl;    
    std::cout << "==============" << std::endl;
    
    return 0;
}