/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Daniel Dorndorf <dorndorf@featdd.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "detector/Fraction.hpp"

/**
 * Double-convert constructor
*/
Fraction::Fraction(int Number) {
    numerator = Number, denominator = 1;
}

/**
 * Double-convert constructor
*/
Fraction::Fraction(double Number) {
    this->convertDoubleToFraction(Number);
}

/**
 * String-convert constructor
*/
Fraction::Fraction(std::string &FractionString) {
    this->convertStringToFraction(FractionString);
}

/**
 * Recursive euclidean function for
 * the greatest common divisor
 */
int Fraction::euclidean(int a, int b){
    return b == 0 ? a : this->euclidean(b, a % b);
}

/**
 * Getter for the numerator
*/
int Fraction::getNumerator() {
    return this->numerator;
}

/**
 * Getter for the denominator
*/
int Fraction::getDenominator() {
    return this->denominator;
}

/**
 * Setter for the numerator
*/
void Fraction::setNumerator(int Numerator) {
    this->numerator = Numerator;
}

/**
 * Setter for the denominator
*/
void Fraction::setDenominator(int Denominator) {
    this->denominator = Denominator;
}

/**
 * Reduce the fraction as low as possible
*/
bool Fraction::reduce() {
    int gcd(this->euclidean(this->numerator, this->denominator));

    if (1 < gcd) {
        this->numerator /= gcd;
        this->denominator /= gcd;

        return true;
    } else {
        return false;
    }
}

/**
 * Convert function for double to fraction
 *
 * Count pre-decimal points, multiply the
 * double number with 10 to move the floating point
 * and also the denominator
*/
void Fraction::convertDoubleToFraction(double Number) {
    this->denominator = 1;

    while(((double)(int)Number) != Number) {
        Number = Number * 10;
        this->denominator = this->denominator * 10;
    }

    this->numerator = (int)Number;

    this->reduce();
}

/**
 * Convert function for fraction to double
*/
double Fraction::convertFractionToDouble() {
    return (double)this->numerator / (double)this->denominator;
}

/**
 * Convert function for string to fraction
 *
 * cut numerator and denominator out of string
*/
bool Fraction::convertStringToFraction(std::string &FractionString) {
    std::size_t pos = FractionString.find('/');

    if (pos != std::string::npos) {
        try {
            this->numerator = atol(FractionString.substr(0, pos).c_str());
            this->denominator = atol(FractionString.substr(pos + 1).c_str());
        } catch(...) {
            return false;
        }

        return !this->denominator;
    }

    return false;
}

/**
 * Smaller than operator overloading
*/
bool Fraction::operator<(Fraction fraction) {
    return (this->numerator * (this->denominator * fraction.getDenominator())) < (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Smaller than or equal operator overloading
*/
bool Fraction::operator<=(Fraction fraction) {
    return (this->numerator * (this->denominator * fraction.getDenominator())) <= (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Bigger than operator overloading
*/
bool Fraction::operator>(Fraction fraction) {
    return (this->numerator * (this->denominator * fraction.getDenominator())) > (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Bigger than or equal operator overloading
*/
bool Fraction::operator>=(Fraction fraction) {
    return (this->numerator * (this->denominator * fraction.getDenominator())) >= (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Equal operator overloading
*/
bool Fraction::operator==(Fraction fraction) {
    return (this->numerator * (this->denominator * fraction.getDenominator())) == (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Non-Equal operator overloading
*/
bool Fraction::operator!=(Fraction fraction) {
    return (this->numerator * (this->denominator * fraction.getDenominator())) != (fraction.getNumerator() * (this->denominator * fraction.getDenominator()));
}

/**
 * Modulos operator overloading (a/b % x/y = (a*y % b*x) / (b*y))
*/
int Fraction::operator%(Fraction fraction) {
    int result;

    result = ((this->numerator * fraction.getDenominator()) % (this->denominator * fraction.getNumerator())) / (this->denominator * fraction.getDenominator());

    return result;
}

/**
 * Double typecast operator overloading
*/
Fraction::operator double() {
    return this->convertFractionToDouble();
}

/**
 * Float typecast operator overloading
*/
Fraction::operator float() {
    return (float)this->convertFractionToDouble();
}

/**
 * int typecast operator overloading
*/
Fraction::operator int() {
    return (int)this->convertFractionToDouble();
}

/**
 * Std::string typecast operator overloading
*/
Fraction::operator std::string() {
    std::stringstream output;
    output << this->getNumerator() << "/" << this->getDenominator();

    return output.str();
}

/**
 * Addition operator overloading
*/
Fraction Fraction::operator+(Fraction fraction) {
    Fraction resultFraction;

    if (this->denominator == fraction.getDenominator()) {
        resultFraction.setNumerator(this->numerator + fraction.getNumerator());
        resultFraction.setDenominator(this->denominator);
    } else {
        resultFraction.setNumerator((this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator));
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());
    }

    return resultFraction;
}

/**
 * Assignment by Sum operator overloading
*/
Fraction Fraction::operator+=(Fraction fraction) {
    if (this->denominator == fraction.getDenominator()) {
        this->numerator += fraction.getNumerator();
    } else {
        this->numerator = (this->numerator * fraction.getDenominator()) + (fraction.getNumerator() * this->denominator);
        this->denominator *= fraction.getDenominator();
    }

    return *this;
}

/**
 * Subtraction operator overloading
*/
Fraction Fraction::operator-(Fraction fraction) {
    Fraction resultFraction;

    if (this->denominator == fraction.getDenominator()) {
        resultFraction.setNumerator(this->numerator - fraction.getNumerator());
        resultFraction.setDenominator(this->denominator);
    } else {
        resultFraction.setNumerator((this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator));
        resultFraction.setDenominator(this->denominator * fraction.getDenominator());
    }

    return resultFraction;
}

/**
 * Assignment by difference operator overloading
*/
Fraction Fraction::operator-=(Fraction fraction) {
    if (this->denominator == fraction.getDenominator()) {
        this->numerator -= fraction.getNumerator();
    } else {
        this->numerator = (this->numerator * fraction.getDenominator()) - (fraction.getNumerator() * this->denominator);
        this->denominator *= fraction.getDenominator();
    }

    return *this;
}

/**
 * Multiply operator overloading
*/
Fraction Fraction::operator*(Fraction fraction) {
    Fraction resultFraction;

    resultFraction.setNumerator(this->numerator * fraction.getNumerator());
    resultFraction.setDenominator(this->denominator * fraction.getDenominator());

    return resultFraction;
}

/**
 * Multiply Set operator overloading
*/
Fraction Fraction::operator*=(Fraction fraction) {
    this->denominator *= fraction.getDenominator();
    this->numerator *= fraction.getNumerator();

    return *this;
}

/**
 * Division operator overloading
*/
Fraction Fraction::operator/(Fraction fraction) {
    Fraction resultFraction;

    resultFraction.setDenominator(this->denominator * fraction.getNumerator());
    resultFraction.setNumerator(this->numerator * fraction.getDenominator());

    return resultFraction;
}

/**
 * Division Set operator overloading
*/
Fraction Fraction::operator/=(Fraction fraction) {
    this->denominator *= fraction.getNumerator();
    this->numerator *= fraction.getDenominator();

    return *this;
}

/**
 * Addition operator
*/
Fraction operator+(int Number, Fraction fraction) {
    return Fraction(Number) + fraction;
}

/**
 * Subtraction operator
*/
Fraction operator-(int Number, Fraction fraction) {
    return Fraction(Number) - fraction;
}

/**
 * Multiply operator
*/
Fraction operator*(int Number, Fraction fraction) {
    return Fraction(Number) * fraction;
}

/**
 * Division operator
*/
Fraction operator/(int Number, Fraction fraction) {
    return Fraction(Number) / fraction;
}

/**
 * Complement operator overloading
*/
Fraction Fraction::operator~() {
    Fraction resultFraction;

    if(this->numerator > this->denominator) {
        return *this;
    } else {
        resultFraction.setNumerator(this->denominator - this->numerator);
        resultFraction.setDenominator(this->denominator);

        return resultFraction;
    }
}

/**
 * Increment operator overloading
*/
Fraction Fraction::operator++() {
    this->numerator += 1;

    return *this;
}

/**
 * Decrement operator overloading
*/
Fraction Fraction::operator--() {
    this->numerator -= 1;

    return *this;
}

/**
 * Left shift operator overloading
*/
std::ostream& operator<<(std::ostream &out, Fraction &Fraction) {
    out << Fraction.getNumerator() << "/" << Fraction.getDenominator();

    return out;
}

/**
 * Right shift operator overloading
 *
 * Calls convertStringToFraction function and throws an
 * FractionInputFailException object on fail.
 *
 * (catchable as a std::exception)
*/
std::istream& operator>>(std::istream &in, Fraction &Fraction) {
    std::string input;

    in >> input;

    if (!Fraction.convertStringToFraction(input)) {
        // Throw own exception object
        throw FractionInputFailException();
    }

    return in;
}