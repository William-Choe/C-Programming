#ifndef LAB5_FRACTION_H
#define LAB5_FRACTION_H

using namespace std;

class Fraction {
    friend void invert(Fraction &f);

private:
    int m_Numerator;

    int m_Denominator;

    static double zero_tolerance;

public:
    Fraction();

    explicit Fraction(int numerator);

    Fraction(int numerator, int denominator);

    Fraction(const Fraction &fraction);

    int getNumer() const;

    int getDenom() const;

    static double getZeroTol();

    void setNumer(int n);

    bool setDenom(int d);

    static void setZeroTol(double d);

    void readin();

    void print() const;

    Fraction reciprocal();

    void unreduce(int m);

    float toDecimal();

    Fraction &operator=(const Fraction& rhs);

    Fraction &operator*=(const Fraction& rhs);

    void operator!();
};

ostream &operator<<(ostream &out, const Fraction& source);

Fraction operator*(const Fraction &lhs, const Fraction &rhs);

bool operator==(const Fraction &lhs, const Fraction &rhs);

bool operator!=(const Fraction &lhs, const Fraction &rhs);

bool operator>(const Fraction &lhs, const Fraction &rhs);

bool operator>=(const Fraction &lhs, const Fraction &rhs);

bool operator<(const Fraction &lhs, const Fraction &rhs);

bool operator<=(const Fraction &lhs, const Fraction &rhs);

Fraction multFracs(const Fraction &lhs, const Fraction &rhs);

#endif