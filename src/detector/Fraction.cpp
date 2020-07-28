#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <exception>
#include "detector/Fraction.hpp"

Fraction::Fraction(int number) : numerator(number), denominator(1) {}
Fraction::Fraction(long long number) : numerator(number), denominator(1) {}

Fraction::Fraction(long long numerator, long long denominator) :
    numerator(numerator), denominator(denominator) {}

Fraction::Fraction(double number) {
    static const int accuracy = 6;
    static Fraction basis[accuracy] =
            {Fraction(1), Fraction(1, 10),
             Fraction(1, 100), Fraction(1, 1000),
             Fraction(1, 10000), Fraction(1, 100000)}; // It`s more than enough for my purposes.
    *this = 0;
    for (auto bas : basis)
        if (int(number / double(bas)) != 0) {
            *this  += bas * int(number / double(bas));
            number -= int(number / double(bas)) * double(bas);
        }
    this->reduce();
}

Fraction::Fraction(std::string &fraction_string) {
    convert_string_to_fraction(fraction_string);
}

long long Fraction::euclidean(long long a, long long b){
    return b ? euclidean(b, a % b) : a;
}

long long Fraction::get_numerator() const {
    return numerator;
}

long long Fraction::get_denominator() const {
    return denominator;
}

Fraction Fraction::reduce() {
    if (numerator < 0 && denominator < 0)
        numerator *= -1, denominator *= -1;
    long long gcd(euclidean(numerator, denominator));
    numerator /= gcd;
    denominator /= gcd;
    return *this;
}

Fraction Fraction::make_base(Fraction base) {
    return *this = Fraction(int(*this * base)) / base;
}

void Fraction::convert_string_to_fraction(std::string &fraction_string) {
    std::size_t pos = fraction_string.find('/');
    if (pos != std::string::npos) {
        numerator = atol(fraction_string.substr(0, pos).c_str());
        denominator = atol(fraction_string.substr(pos + 1).c_str());
    }
}

bool Fraction::operator<(Fraction fraction) const {
    return numerator * fraction.get_denominator() < fraction.get_numerator() * denominator;
}

bool Fraction::operator<=(Fraction fraction) const {
    return (numerator * fraction.get_denominator()) <= (fraction.get_numerator() * denominator);
}

bool Fraction::operator>(Fraction fraction) const {
    return (numerator * fraction.get_denominator()) > (fraction.get_numerator() * denominator);
}

bool Fraction::operator>=(Fraction fraction) const {
    return (numerator * fraction.get_denominator()) >= (fraction.get_numerator() * denominator);
}

bool Fraction::operator==(Fraction fraction) const {
    return (numerator * fraction.get_denominator()) == (fraction.get_numerator() * denominator);
}

bool Fraction::operator!=(Fraction fraction) const {
    return (numerator * fraction.get_denominator()) != (fraction.get_numerator() * denominator);
}

Fraction::operator double() const {
    return (double)numerator / (double)denominator;
}

Fraction::operator float() const {
    return (float)numerator / (float)denominator;
}

Fraction::operator long long() const {
    return numerator / denominator + bool(numerator % denominator > denominator / 2);
}

Fraction::operator int() const {
    return int(numerator / denominator + bool(numerator % denominator > denominator / 2));
}

Fraction::operator std::string() const {
    std::stringstream output;
    output << get_numerator() << "/" << get_denominator();
    return output.str();
}

Fraction Fraction::operator+(Fraction fraction) const {
    if (this->denominator == fraction.denominator)
        return Fraction(this->numerator + fraction.numerator, this->denominator).reduce();
    else
        return Fraction(this->numerator * fraction.denominator +
        fraction.numerator * this->denominator,
        this->denominator * fraction.get_denominator()).reduce();
}

Fraction Fraction::operator-(Fraction fraction) const {
    return *this + (-1 * fraction);
}

Fraction Fraction::operator+=(Fraction fraction) {
    return *this = *this + fraction;
}

Fraction Fraction::operator-=(Fraction fraction) {
    return *this - fraction;
}

Fraction Fraction::operator*(Fraction fraction) const {
    return Fraction(numerator * fraction.get_numerator(),
                    denominator * fraction.get_denominator()).reduce();
}

Fraction Fraction::operator*=(Fraction fraction) {
    return *this = *this * fraction;
}

Fraction Fraction::operator/(Fraction fraction) const {
    return Fraction(numerator * fraction.get_denominator(),
                    denominator * fraction.get_numerator()).reduce();
}

Fraction Fraction::operator/=(Fraction fraction) {
    return *this = *this / fraction;
}

Fraction operator+(long long Number, Fraction fraction) {
    return Fraction(Number) + fraction;
}

Fraction operator-(long long Number, Fraction fraction) {
    return Fraction(Number) - fraction;
}

Fraction operator*(long long Number, Fraction fraction) {
    return Fraction(Number) * fraction;
}

Fraction operator/(long long Number, Fraction fraction) {
    return Fraction(Number) / fraction;
}

Fraction Fraction::operator-() {
    numerator *= -1;
    return *this;
}

Fraction Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Fraction &Fraction) {
    return out << Fraction.get_numerator() << "/" << Fraction.get_denominator();
}

std::istream& operator>>(std::istream &in, Fraction &Fraction) {
    std::string input;
    in >> input;
    Fraction.convert_string_to_fraction(input);
    return in;
}

bool operator<(long long Number, Fraction fraction) {
    return Fraction(Number) < fraction;
}

bool operator<=(long long Number, Fraction fraction) {
    return Fraction(Number) <= fraction;
}

bool operator>(long long Number, Fraction fraction) {
    return Fraction(Number) > fraction;
}

bool operator>=(long long Number, Fraction fraction) {
    return Fraction(Number) >= fraction;
}

Fraction abs(Fraction fraction) {
    return Fraction(abs(fraction.get_numerator()), abs(fraction.get_denominator()));
}

double sqrt(Fraction fraction) {
    return sqrt(double(fraction));
}