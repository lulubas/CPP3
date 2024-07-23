/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:39:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/23 02:31:22 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

std::map<std::string, ClapTrap*> ClapTrap::_clapTrapMap;
int ClapTrap:: _nameCounter = 1;

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    _name = _generateUniqueName(_name);
    _clapTrapMap[_name] = this;
    std::cout << "ClapTrap " << _name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    _name = _generateUniqueName(_name);
    _clapTrapMap[_name] = this;
    std::cout << "ClapTrap " << _name << " created with parameterized constructor." << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    _name = _generateUniqueName(_name);
    _clapTrapMap[_name] = this;
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
    _clapTrapMap.erase(_name);
    std::cout << "ClapTrap " << _name << " is destructed." << std::endl;
}

int ClapTrap::getHitpoints(void) {
    return (_hitPoints);
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
    std::map<std::string, ClapTrap*>::iterator it = _clapTrapMap.find(target);
    if (it == _clapTrapMap.end()) {
        std::cout << "ClapTrap " << _name << " can't attack " << target << ": it does not exist." << std::endl;
        return ;
    }
    ClapTrap* targetClapTrap = it->second;
    if (this == targetClapTrap) {
        std::cout << "ClapTrap can't attack himself" << std::endl;
        return ;
    }
    if (targetClapTrap->_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't attack: " << target <<  " has no more hitpoints" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << _name << " attacks ClapTrap " << target << " to cause " << _attackDamage << " damage(s)." << std::endl;
    targetClapTrap->takeDamage(_attackDamage);
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
    uniqueName = rootName;
    while (_clapTrapMap.find(uniqueName) != _clapTrapMap.end()) {
        std::ostringstream oss;
        oss << uniqueName << "_" << _nameCounter++;
        uniqueName = oss.str();
    }
    return uniqueName;
}
