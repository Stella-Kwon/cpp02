/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:06:18 by skwon2            #+#    #+#             */
/*   Updated: 2024/12/30 11:22:23 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
# include <iostream>


class Fixed{
        private:
            int _fixedPoint;
            static const int fractional_bits = 8;
        public:
            Fixed();
            Fixed(const int intNum);
            Fixed(const float floatNum);
            Fixed(const Fixed& oldFixed); // copy constructor
            
            ~Fixed();
            Fixed& operator=(const Fixed& newFixed);//copy assignment operator overload.
            //need to return the new one on the old place
            //so which means with '=' will allow the modifiying the current object(*this).
            // so the return value has to be set in reference.

            // but this does not ned Fixed& return.
            // this will give you the new object with changed value.
            Fixed operator*(const Fixed& next);
            Fixed operator-(const Fixed& next);
            Fixed operator+(const Fixed& next);
            Fixed operator/(const Fixed& next);

            bool operator>(const Fixed& next);
            bool operator<(const Fixed& next);
            bool operator>=(const Fixed& next);
            bool operator<=(const Fixed& next);
            bool operator==(const Fixed& next);
            bool operator!=(const Fixed& next);

            Fixed operator--(const Fixed& next);
            Fixed operator++(const Fixed& next);
            int getRawBits( void ) const;
            void setRawBits( int const raw );
            float toFloat( void ) const;
            int toInt( void ) const;
};

//not related in maniplating  fixed point
// stream insertion related.

std::ostream& operator<<(std::ostream& out, const Fixed& object);//copy assignment operator overload.
#endif