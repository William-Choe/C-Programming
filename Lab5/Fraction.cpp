#include <iostream>
#include "Fraction.h"

#define ABS(x) ((x>0)?x:-x)

double Fraction::zero_tolerance = 0.0001;

Fraction::Fraction() {
    this->m_Numerator = 0;
    this->m_Denominator = 1;
}

Fraction::Fraction(int numerator) {
    this->m_Numerator = numerator;
    this->m_Denominator = 1;
}

Fraction::Fraction(int numerator, int denominator){
    if ((numerator >= 0 && denominator > 0) || (numerator <= 0 && denominator < 0)) {

        this->m_Numerator = ABS(numerator);
        this->m_Denominator = ABS(denominator);
    } else if ((numerator >= 0 && denominator < 0) || (numerator <= 0 && denominator > 0)) {
        this->m_Numerator = -ABS(numerator);
        this->m_Denominator = ABS(denominator);
    } else {
        this->m_Numerator = numerator;
        this->m_Denominator = 1;
    }
}

Fraction::Fraction(const Fraction &fraction){
    this->m_Numerator = fraction.getNumer();
    this->m_Denominator = fraction.getDenom();
}

void Fraction::readin() {
    int numerator, denominator;
    cout << "Please enter numerator:";
    cin >> numerator;
    cout << "Please enter denominator:";
    cin >> denominator;

    if (denominator == 0) {
        cout << "\nError input denominator! Please enter again." << endl;
        readin();
    } else {
        this->m_Numerator = numerator;
        this->m_Denominator = denominator;
    }
}

int Fraction::getNumer() const {
    return this->m_Numerator;
}

int Fraction::getDenom() const {
    return this->m_Denominator;
}

double Fraction::getZeroTol() {
    return zero_tolerance;
}

void Fraction::setNumer(int n){
    this->m_Numerator = n;
}

bool Fraction::setDenom(int d){
    if (d != 0) {
        this->m_Denominator = d;
        return true;
    } else {
        return false;
    }
}

void Fraction::setZeroTol(double d){
    zero_tolerance = d;
}

void Fraction::print() const{
    if (m_Denominator == 1) {
        cout << m_Numerator << endl;
    } else {
        cout << m_Numerator << "/" << m_Denominator << endl;
    }
}

Fraction Fraction::reciprocal(){
    Fraction fraction(m_Denominator, m_Numerator);

    return fraction;
}

void Fraction::unreduce(int m){
    if (m != 0) {
        this->m_Numerator *= m;
        this->m_Denominator *= m;
    } else {
        return;
    }
}

float Fraction::toDecimal() {
    return (float) this->m_Numerator / this->m_Denominator;
}

Fraction &Fraction::operator=(const Fraction& rhs) {
    m_Numerator = rhs.getNumer();
    m_Denominator = rhs.getDenom();

    return *this;
}

Fraction &Fraction::operator*=(const Fraction& rhs) {
    m_Numerator = m_Numerator * rhs.getNumer();
    m_Denominator = m_Denominator * rhs.getDenom();

    return *this;
}

void invert(Fraction &f) {
    int tempN = f.getNumer();
    int tempD = f.getDenom();

    if (f.getNumer() == 0) {
        f.setNumer(tempD);
        f.setDenom(1);
    } else {
        f.setNumer(tempD);
        f.setDenom(tempN);
    }
}

void Fraction::operator!() {
    invert(*this);
}

ostream &operator<<(ostream &out, const Fraction& source){
    out << source.getNumer() << "/" << source.getDenom();

    return out;
}

Fraction operator*(const Fraction &lhs, const Fraction &rhs) {
    Fraction a = Fraction(lhs.getNumer() * rhs.getNumer(), lhs.getDenom() * lhs.getDenom());

    return a;
}

bool operator==(const Fraction &lhs, const Fraction &rhs){
    return lhs.getNumer() * rhs.getDenom() == lhs.getDenom() * rhs.getNumer();
}

bool operator!=(const Fraction &lhs, const Fraction &rhs){
    return lhs.getNumer() * rhs.getDenom() != lhs.getDenom() * rhs.getNumer();
}

bool operator>(const Fraction &lhs, const Fraction &rhs){
    return lhs.getNumer() * rhs.getDenom() > lhs.getDenom() * rhs.getNumer();
}

bool operator>=(const Fraction &lhs, const Fraction &rhs){
    return lhs.getNumer() * rhs.getDenom() >= lhs.getDenom() * rhs.getNumer();
}

bool operator<(const Fraction &lhs, const Fraction &rhs){
    return lhs.getNumer() * rhs.getDenom() < lhs.getDenom() * rhs.getNumer();
}

bool operator<=(const Fraction &lhs, const Fraction &rhs){
    return lhs.getNumer() * rhs.getDenom() <= lhs.getDenom() * rhs.getNumer();
}

Fraction multFracs(const Fraction &lhs, const Fraction &rhs) {
    Fraction fraction(lhs.getNumer() * rhs.getDenom(), lhs.getDenom() * rhs.getNumer());

    return fraction;
}