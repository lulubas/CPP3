/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:31:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/06/26 16:08:26 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::map<std::string, ClapTrap*> ClapTrap::_clapTrapMap;
int ClapTrap:: _nameCounter = 1;

ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created with parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
    std::cout << "ScavTrap " << _name << " created with copy constructor." << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap " << _name << " assigned from another ScavTrap." << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " is destructed." << std::endl;
}
