/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/07/19 02:06:40 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
    
    std::cout << std::endl;
    
    ClapTrap Louis("Louis");
    ClapTrap Tom("Tom");
    ClapTrap Henry;
    ClapTrap Paul = Henry;

    Louis.getInfo();
    Tom.getInfo();
    Tom.attack( "Default_1" );
    Paul.getInfo();
    
    return 0;
}