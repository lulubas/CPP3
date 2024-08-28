/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:29:53 by lbastien          #+#    #+#             */
/*   Updated: 2024/08/28 16:14:21 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
        public:
                FragTrap();
                FragTrap(std::string name);
                FragTrap(const FragTrap &other);
                FragTrap& operator=(const FragTrap &other);
                ~FragTrap();
            
                void attack(const std::string& target);
                void highFivesGuys();
        protected:
                int _hitPoints;
                int _energyPoints;
                int _attackDamage;
};

#endif