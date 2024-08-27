/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:39:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/27 19:03:56 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int ClapTrap:: _nameCounter = 1;

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    _name = _generateUniqueName(_name);
    std::cout << "ClapTrap " << _name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " created with parameterized constructor." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap " << _name << " created with copy constructor." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ClapTrap " << _name << " assigned from another ClapTrap." << std::endl;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " is destructed." << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack: it has no more hitpoints." << std::endl;
        return ;
    }
    if (_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack: it has no more energy points." << std::endl;
        return ;
    }
    if (target == this->_name) {
        std::cout << "ClapTrap can't attack himself" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
    _energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0)
        std::cout << _name << " has no more hitpoints." << std::endl;
    _hitPoints -= amount;
    std::cout << _name << " takes " << amount << " damage(s)." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    _hitPoints += amount;
    std::cout << _name << " got repaired " << amount << " hitpoints." << std::endl;
}

void    ClapTrap::getInfo(void) {
    std::cout << std::endl <<  "===Name: " << _name << "===" << std::endl;
    std::cout << "Hitpoints: " << _hitPoints << std::endl;
    std::cout << "Energy Points: " << _energyPoints << std::endl;
    std::cout << "AttackDamage: " << _attackDamage << std::endl;
    std::cout << std::endl;
}

std::string ClapTrap::_generateUniqueName(const std::string &rootName) {
    std::string uniqueName;
    uniqueName = rootName + "_"; 
    uniqueName.append(iToString(_nameCounter++));
    return uniqueName;
}

std::string iToString(const int i) {
    std::ostringstream oss;
    oss << i;
    return oss.str();
}
