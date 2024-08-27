/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:31:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/27 19:05:00 by lbastien         ###   ########.fr       */
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
    if (target == this->_name) {
        std::cout << "FragTrap can't attack himself" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << _name << " attacks " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
    _energyPoints--;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " is now requesting the highest of five." << std::endl;
}