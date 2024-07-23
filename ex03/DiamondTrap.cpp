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

DiamondTrap::DiamondTrap() : ClapTrap() {
    this->_name = ClapTrap::_name;
    ClapTrap::_name = _name + "_clap_name";
    _energyPoints = 50;
    std::cout << "DiamondTrap " << _name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
    _name = name;
    ClapTrap::_name = _name + "_clap_name";
    _energyPoints = 50;
    std::cout << "DiamondTrap " << _name << " created with parameterized constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    _name = ClapTrap::_name;
    ClapTrap::_name = _name + "_clap_name";
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    std::cout << "DiamondTrap " << _name << " created with copy constructor." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        _name=other._name;
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

void DiamondTrap::getInfo(void) {
    std::cout << std::endl <<  "===Name: " << this->_name << "===" << std::endl;
    std::cout << "Hitpoints: " << _hitPoints << std::endl;
    std::cout << "Energy Points: " << _energyPoints << std::endl;
    std::cout << "AttackDamage: " << _attackDamage << std::endl;
    std::cout << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is "  << _name << std::endl;
    std::cout << "My Claptrap name is "  << ClapTrap::_name << std::endl;   
    std::cout << std::endl;
}
