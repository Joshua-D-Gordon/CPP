//header gaurd
#pragma once
//include for input and output
#include <iostream>
//using namespace std
using namespace std;
//in name space ariel
namespace ariel
{
    class Fraction
    {   
    private:
        //private members
        int numerator, denominator;

    public:
        //constructor
        Fraction(int num, int denom);

        //constructor for float value
        Fraction(float);

        //default constructor (set to 0)
        Fraction() : numerator(0), denominator(1) {}

        //getters & setters
        const int& getNumerator() const;
        void setNumerator(int);
        const int& getDenominator() const;
        void setDenominator(int);

        Fraction operator+(const Fraction&) const;
        // Fraction operator+(float f) const;
        Fraction operator-(const Fraction&) const;
        // Fraction operator-(float f) const;
        Fraction operator*(const Fraction&) const;
        // Fraction operator*(float f) const;
        Fraction operator/(const Fraction&) const;
        // Fraction operator/(float f) const;
        Fraction operator^(const int& pow) const{
            Fraction f1(1);
            for(int i = 0; i<pow;i++){
                f1=f1*(*this);
            }
            return f1.reduce();
        }

        // bool functions
        bool operator==(const Fraction&) const;
        bool operator>(const Fraction&) const;
        bool operator<(const Fraction&) const;
        bool operator>=(const Fraction&) const;
        bool operator<=(const Fraction&) const;

        Fraction& operator++();   // pre-increment
        Fraction operator++(int); // post-increment
        Fraction& operator--();   // pre-decrement
        Fraction operator--(int); // post-decrement

        // float operators
        Fraction operator+(float);
        Fraction operator-(float);
        Fraction operator*(float);
        Fraction operator/(float);

        // float bool operators
        bool operator==(float fNum);
        bool operator>(float fNum);
        bool operator<(float fNum);
        bool operator>=(float fNum);
        bool operator<=(float fNum);

        // Helper functions
        // Fraction reduce form
        Fraction& reduce();
        //float to fraction converter function
        Fraction floatToFraction(float);
        //gcd helper function for float to fraction
        int gcd(int, int) const;
        //cheeckoverflow function for tests
        void cheeckOverFlow(long int ,long int) const;
        
        //friend functions
        //for input and printing
        friend std::ostream &operator<<(std::ostream &outstream, const Fraction&);
        friend std::istream &operator>>(std::istream &instream, Fraction&);
        //for non unary , binaray -- (this, x, y)
        
        friend Fraction operator+(float, const Fraction&);
        friend Fraction operator-(float, const Fraction&);
        friend Fraction operator*(float, const Fraction&);
        friend Fraction operator/(float, const Fraction&);
        friend bool operator==(float, const Fraction&);
        friend bool operator>(float, const Fraction&);
        friend bool operator>=(float, const Fraction&);
        friend bool operator<(float, const Fraction&);
        friend bool operator<=(float, const Fraction&);
    };

}
