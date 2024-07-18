/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/19 01:14:34 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
    
    std::cout << std::endl;
    
    ScavTrap Louis("Louis");
    ClapTrap Tom("Tom");
    ScavTrap Paul = Louis;

    Paul.getInfo();
    Tom.getInfo();
    Tom.attack( "Louis_1" );
    Paul.attack( "Tom" );
    Paul.getInfo();
    Tom.getInfo();
    
    return 0;
}