/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:31:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/21 12:10:24 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "DiamondTrap " << _name << " created with parameterized constructor." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap " << _name << " created with copy constructor." << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &other ) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "DiamondTrap " << _name << " assigned from another DiamondTrap." << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " is destructed." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "DiamondTrap " << _name << " has no more hitpoints." << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << "DiamondTrap " << _name << " has no more energy points." << std::endl;
        return;
    }
    std::map<std::string, ClapTrap*>::iterator it = _clapTrapMap.find(target);
    if (it == _clapTrapMap.end()) {
        std::cout << "DiamondTrap " << target << " not found." << std::endl;
        return;
    }
    ClapTrap* targetClapTrap = it->second;
    if (this == targetClapTrap) {
        std::cout << "DiamondTrap can't attack himself" << std::endl;
        return;
    }
    if (targetClapTrap->getHitpoints() <= 0) {
        std::cout << "DiamondTrap " << target << " has no more hitpoints" << std::endl;
        return;
    }
    DiamondTrap* targetDiamondTrap = dynamic_cast<DiamondTrap*>(targetClapTrap);
    if (targetDiamondTrap) {
        std::cout << "DiamondTrap " << _name << " attacks DiamondTrap " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
        targetDiamondTrap->takeDamage(_attackDamage);
    } else {
        std::cout << "DiamondTrap " << _name << " attacks ClapTrap " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
        targetClapTrap->takeDamage(_attackDamage);
    }
    _energyPoints--;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap " << _name << " is now requesting a mandatory high five." << std::endl;
}
