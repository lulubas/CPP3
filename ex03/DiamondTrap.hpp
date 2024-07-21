/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:29:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/19 01:55:45 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMOND_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap {
        public:
                DiamondTrap();
                DiamondTrap( std::string name );
                DiamondTrap( const DiamondTrap &other );
                DiamondTrap& operator=( const DiamondTrap &other );
                ~DiamondTrap();
            
                void attack(const std::string& target);
                void whoAmI();
        private:
                std::string _name;          
};

#endif