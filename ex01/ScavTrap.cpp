/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:31:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/06/25 23:46:01 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::map<std::string, ClapTrap*> ClapTrap::_clapTrapMap;
int ClapTrap:: _nameCounter = 1;

ScavTrap::ScavTrap() : ClapTrap::ClapTrap() {
    std::cout << "ScavTrap " << _name << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : _name( name ), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    if (_ScavTrapMap.find( _name ) != _ScavTrapMap.end()) {
        _name = _generateUniqueName( _name );
    }
    _ScavTrapMap[_name] = this;
    std::cout << "ScavTrap " << _name << " created with parameterized constructor." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    _name = _generateUniqueName( _name );
    _ScavTrapMap[_name] = this;
    std::cout << "ScavTrap " << _name << " created with copy constructor." << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &other ) {
    if (this != &other) {
        _name = _generateUniqueName( other._name );
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ScavTrap " << _name << " assigned from another ScavTrap." << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    _ScavTrapMap.erase( _name );
    std::cout << "ScavTrap " << _name << " is destructed." << std::endl;
}
