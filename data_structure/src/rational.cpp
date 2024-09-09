#include "rational.hpp"



Rational& Rational::operator=(const Rational& rhs)
{
    this->nominator_ = rhs.nominator_;
    this->denominator_ = rhs.denominator_;
    return *this;
}

Numeric& Rational::operator=(const Numeric& rhs)
{
    const Rational& rhs_rational = dynamic_cast<const Rational&>(rhs);
    this->nominator_ = rhs_rational.nominator_;
    this->denominator_ = rhs_rational.denominator_;
    return *this;
}

Rational& Rational::operator+=(const Rational& rhs)
{
    this->nominator_ = this->nominator_ * rhs.denominator_+ rhs.nominator_ * this->denominator_;
    this->denominator_ *= rhs.denominator_;
    return *this;
}

Numeric& Rational::operator+=(const Numeric& rhs)
{
    const Rational& rhs_rational = dynamic_cast<const Rational&>(rhs);
    this->nominator_ = this->nominator_ * rhs_rational.denominator_+ rhs_rational.nominator_ * this->denominator_;
    this->denominator_ *= rhs_rational.denominator_;
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    this->nominator_ = this->nominator_ * rhs.denominator_ - rhs.nominator_ * this->denominator_;
    this->denominator_ *= rhs.denominator_;
    return *this;
}

Numeric& Rational::operator-=(const Numeric& rhs)
{
    const Rational& rhs_rational = dynamic_cast<const Rational&>(rhs);
    this->nominator_ = this->nominator_ * rhs_rational.denominator_ - rhs_rational.nominator_ * this->denominator_;
    this->denominator_ *= rhs_rational.denominator_;
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    this->nominator_ *= rhs.nominator_;
    this->denominator_ *= rhs.denominator_;
    return *this;
}

Numeric& Rational::operator*=(const Numeric& rhs)
{
    const Rational& rhs_rational = dynamic_cast<const Rational&>(rhs);
    this->nominator_ *= rhs_rational.nominator_;
    this->denominator_ *= rhs_rational.denominator_;
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    this->nominator_ *= rhs.denominator_;
    this->denominator_ *= rhs.nominator_;
    return *this;
}

Numeric& Rational::operator/=(const Numeric& rhs)
{
    const Rational& rhs_rational = dynamic_cast<const Rational&>(rhs);
    this->nominator_ *= rhs_rational.denominator_;
    this->denominator_ *= rhs_rational.nominator_;
    return *this;
}

const std::string Rational::str(){
    std::string result{""};
    result = std::to_string(this->nominator_) + " / " + std::to_string(this->denominator_);
    return result;
}


Rational operator+(const Rational& lhs, const Rational& rhs)
{
    
    int nominator = lhs.nominator_ * rhs.denominator_+ rhs.nominator_ * lhs.denominator_;
    int denominator = lhs.denominator_ * rhs.denominator_;
    Rational result(nominator, denominator);
    return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    
    int nominator = lhs.nominator_ * rhs.denominator_- rhs.nominator_ * lhs.denominator_;
    int denominator = lhs.denominator_ * rhs.denominator_;
    Rational result(nominator, denominator);
    return result;
}


Rational operator*(const Rational& lhs, const Rational& rhs)
{
    int nominator = lhs.nominator_ * rhs.nominator_;
    int denominator = lhs.denominator_ * rhs.denominator_;
    Rational result(nominator, denominator);
    return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    int nominator = lhs.nominator_ * rhs.denominator_;
    int denominator = lhs.denominator_ * rhs.nominator_;
    Rational result(nominator, denominator);
    return result;
}
