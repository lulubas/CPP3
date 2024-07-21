/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:32:51 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/21 12:30:04 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<map>

class ClapTrap {
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap &other );
        ClapTrap& operator=( const ClapTrap &other );
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void getInfo( void );
        
    protected:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
        static int _nameCounter;
        static std::map<std::string, ClapTrap*> _clapTrapMap;

        std::string _generateUniqueName( const std::string &rootName );
};

#endif