#ifndef FRACTION_HPP
#define FRACTION_HPP

#include "opencv2/opencv.hpp"

class Fraction {
private:

    long long numerator = 0;
    long long denominator = 1;

    long long euclidean(long long a, long long b);

public:

    Fraction() = default;
    Fraction(int number);
    Fraction(double number);
    Fraction(long long number);
    Fraction(long long numerator, long long denominator);
    Fraction(std::string &fraction_string);
    ~Fraction() = default;

    [[nodiscard]] long long get_numerator() const;
    [[nodiscard]] long long get_denominator() const;

    Fraction reduce();
    Fraction make_base(Fraction base);

    void convert_string_to_fraction(std::string &FractionString);

    bool operator<(Fraction fraction) const;
    bool operator<=(Fraction fraction) const;
    bool operator>(Fraction fraction) const;
    bool operator>=(Fraction fraction) const;
    bool operator==(Fraction fraction) const;
    bool operator!=(Fraction fraction) const;

    explicit operator double() const;
    explicit operator float() const;
    explicit operator int() const;
    explicit operator long long() const;
    explicit operator std::string() const;

    Fraction operator+(Fraction fraction) const;
    Fraction operator+=(Fraction fraction);
    Fraction operator-(Fraction fraction) const;
    Fraction operator-=(Fraction fraction);
    Fraction operator*(Fraction fraction) const;
    Fraction operator*=(Fraction fraction);
    Fraction operator/(Fraction fraction) const;
    Fraction operator/=(Fraction fraction);

    Fraction operator-();
    Fraction operator++();
    Fraction operator--();
};

extern std::ostream& operator<<(std::ostream &out, const Fraction &Fraction);
extern std::istream& operator>>(std::istream &in, Fraction &Fraction);

extern Fraction operator+(long long number, Fraction fraction);
extern Fraction operator-(long long number, Fraction fraction);
extern Fraction operator*(long long number, Fraction fraction);
extern Fraction operator/(long long number, Fraction fraction);

extern bool operator<(long long number, Fraction fraction);
extern bool operator<=(long long number, Fraction fraction);
extern bool operator>(long long number, Fraction fraction);
extern bool operator>=(long long number, Fraction fraction);

Fraction abs(Fraction fraction);
double sqrt(Fraction fraction);

#endif