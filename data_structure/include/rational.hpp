#pragma once

#include <string>

class Numeric
{
    private:

    protected:

        Numeric() = default;
        virtual ~Numeric() = default;

        virtual Numeric& operator=(const Numeric&) = 0;
        virtual Numeric& operator+=(const Numeric&) = 0;
        virtual Numeric& operator-=(const Numeric&) = 0;
        virtual Numeric& operator*=(const Numeric&) = 0;
        virtual Numeric& operator/=(const Numeric&) = 0;

        virtual const std::string str() = 0;

    public:
};

class Rational: public Numeric
{
    private:

        int nominator_{0};
        int denominator_{1};

    protected:
        Rational() = delete;

    public:
        Rational(const int numinator = 0, const int denominator = 1)
        :nominator_{numinator}, denominator_{denominator}
        {

        }

        virtual ~Rational() = default;

        Rational(const Rational& rhs)
        :nominator_{rhs.nominator_},
         denominator_{rhs.denominator_}
        {}

        Rational(Rational&& rhs)
        :nominator_{rhs.nominator_},
         denominator_{rhs.denominator_}
        {
            rhs.nominator_ = 0;
            rhs.denominator_ = 1;
        }

        Rational& operator=(const Rational& rhs);

        virtual Numeric& operator=(const Numeric& rhs) override final;

        Rational& operator+=(const Rational& rhs);

        virtual Numeric& operator+=(const Numeric& rhs) override final;

        Rational& operator-=(const Rational& rhs);

        virtual Numeric& operator-=(const Numeric& rhs) override final;

        Rational& operator*=(const Rational& rhs);

        virtual Numeric& operator*=(const Numeric& rhs) override final;

        Rational& operator/=(const Rational& rhs);

        virtual Numeric& operator/=(const Numeric& rhs) override final;

        virtual const std::string str() final;

        friend Rational operator+(const Rational& lhs, const Rational& rhs);
        friend Rational operator-(const Rational& lhs, const Rational& rhs);
        friend Rational operator/(const Rational& lhs, const Rational& rhs);
        friend Rational operator*(const Rational& lhs, const Rational& rhs);

};

