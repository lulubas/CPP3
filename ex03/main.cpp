/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/19 02:06:14 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    
    std::cout << std::endl;
    
    ScavTrap Louis( "Louis" );
    ClapTrap Tom( "Tom" );
    FragTrap Lucy( "Lucy" );
    ScavTrap Paul = Louis;

    Paul.getInfo();
    Tom.getInfo();
    Lucy.getInfo();
    Tom.attack( "Louis_1" );
    Paul.attack( "Lucy" );
    Lucy.attack( "Louis_1" );
    Paul.getInfo();
    Tom.getInfo();
    Lucy.getInfo();
    
    return 0;
}