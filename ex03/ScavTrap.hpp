/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:29:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/28 16:14:39 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
        public:
                ScavTrap();
                ScavTrap(std::string name);
                ScavTrap(const ScavTrap &other);
                ScavTrap& operator=(const ScavTrap &other);
                ~ScavTrap();
            
                void attack(const std::string& target);
                void guardGate();
        protected:
                int _hitPoints;
                int _energyPoints;
                int _attackDamage;
};

#endif