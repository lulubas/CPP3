/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:31:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/19 00:55:11 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "ScavTrap " << _name << " created with copy constructor." << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ScavTrap " << _name << " assigned from another ScavTrap." << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " is destructed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no more hitpoints." << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no more energy points." << std::endl;
        return;
    }
    std::map<std::string, ClapTrap*>::iterator it = _clapTrapMap.find(target);
    if (it == _clapTrapMap.end()) {
        std::cout << "ScavTrap " << target << " not found." << std::endl;
        return;
    }
    ClapTrap* targetClapTrap = it->second;
    if (this == targetClapTrap) {
        std::cout << "ScavTrap can't attack himself" << std::endl;
        return;
    }
    if (targetClapTrap->getHitpoints() <= 0) {
        std::cout << "ScavTrap " << target << " has no more hitpoints" << std::endl;
        return;
    }
    ScavTrap* targetScavTrap = dynamic_cast<ScavTrap*>(targetClapTrap);
    if (targetScavTrap) {
        std::cout << "ScavTrap " << _name << " attacks ScavTrap " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
        targetScavTrap->takeDamage(_attackDamage);
    } else {
        std::cout << "ScavTrap " << _name << " attacks ClapTrap " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
        targetClapTrap->takeDamage(_attackDamage);
    }
    _energyPoints--;
}


void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in gate keeper mode." << std::endl;
}
