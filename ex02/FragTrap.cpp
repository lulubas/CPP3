/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:31:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/23 02:19:10 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " created with parameterized constructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "FragTrap " << _name << " created with copy constructor." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "FragTrap " << _name << " assigned from another FragTrap." << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " is destructed." << std::endl;
}

void    FragTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "FragTrap " << _name << " can't attack: it has no more hitpoints." << std::endl;
        return ;
    }
    if (_energyPoints <= 0) {
        std::cout << "FragTrap " << _name << " can't attack: it has no more energy points." << std::endl;
        return ;
    }
    std::map<std::string, ClapTrap*>::iterator it = _clapTrapMap.find(target);
    if (it == _clapTrapMap.end()) {
        std::cout << "FragTrap " << _name << " can't attack " << target << ": it does not exist." << std::endl;
        return ;
    }
    ClapTrap* targetClapTrap = it->second;
    if (this == targetClapTrap) {
        std::cout << "FragTrap can't attack himself" << std::endl;
        return ;
    }
    if (targetClapTrap->getHitpoints() <= 0) {
        std::cout << "FragTrap " << _name << " can't attack: " << target <<  " has no more hitpoints" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
    targetClapTrap->takeDamage(_attackDamage);
    _energyPoints--;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " is now requesting the highest of five." << std::endl;
}
