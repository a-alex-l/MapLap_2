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

#ifndef FRACTION_HPP
#define FRACTION_HPP

/**
 * Fraction class
 */
class Fraction {
private:
    // Fraction parts
    int numerator = 0, denominator = 1;
    // Euclidean algorithm for greatest common divisor
    int euclidean(int a, int b);
public:
    // Constructors
    Fraction() = default;
    Fraction(int Number);
    Fraction(double Number);
    Fraction(std::string &FractionString);
    // Destructur
    ~Fraction() = default;

    // Getter and Setter
    int getNumerator();
    int getDenominator();
    void setNumerator(int Numerator);
    void setDenominator(int Denominator);

    // Fraction functions
    bool reduce();
    void convertDoubleToFraction(double Number);
    double convertFractionToDouble();
    bool convertStringToFraction(std::string &FractionString);

    // Operator overloading functions
    bool operator<(Fraction fraction);
    bool operator<=(Fraction fraction);
    bool operator>(Fraction fraction);
    bool operator>=(Fraction fraction);
    bool operator==(Fraction fraction);
    bool operator!=(Fraction fraction);
    int operator%(Fraction fraction);

    explicit operator double();
    explicit operator float();
    explicit operator int();
    explicit operator std::string();

    Fraction operator+(Fraction fraction);
    Fraction operator+=(Fraction fraction);
    Fraction operator-=(Fraction fraction);
    Fraction operator-(Fraction fraction);
    Fraction operator*(Fraction fraction);
    Fraction operator*=(Fraction fraction);
    Fraction operator/(Fraction fraction);
    Fraction operator/=(Fraction fraction);

    Fraction operator~();
    Fraction operator++();
    Fraction operator--();
};

/**
 * FractionInputFailException class
 *
 * Exception object extending the c++ standard exceptions
 * Thrown exception can be handled like standard exceptions
*/
class FractionInputFailException: public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override { return "Incorrect Input"; }
};

/** Left Shift Operator overloading functions (need to be declared global) */
std::ostream& operator<<(std::ostream &out, const Fraction &Fraction);
/** Right Shift Operator overloading functions (need to be declared global) */
std::istream& operator>>(std::istream &in, const Fraction &Fraction);

Fraction operator+(int Number, Fraction fraction);
Fraction operator-(int Number, Fraction fraction);
Fraction operator*(int Number, Fraction fraction);
Fraction operator/(int Number, Fraction fraction);

#endif