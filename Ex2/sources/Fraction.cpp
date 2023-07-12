//includes
#include "Fraction.hpp"
#include <cmath>
#include <limits>
#include <typeinfo>
//using namespaces
using namespace ariel;
using namespace std;

// fraction constructor
Fraction::Fraction(int num, int denom)
{   
    //denominator cant be 0
    if (denom == 0)
    {
        throw invalid_argument("denominator cant be 0");
    }
    //types must be int
    if ((typeid(num)) != typeid(int))
    {
        throw invalid_argument("nominator must be of type int");
    }
    if ((typeid(denom)) != typeid(int))
    {
        throw invalid_argument("denominator must be of type int");
    }
    // if number has two negative numbers change to positive or if denom sign is - switch signs
    // -1/-2 --> 1/2 , 1/-2 --> -1/2
    if (denom < 0)
    {
        num*=-1;
        denom*=-1;
    }
    //set attributes of fraction
    this->numerator = num;
    this->denominator = denom;
    //reduce fraction
    // 2/4 --> 1/2 , -2/4 --> -1/2
    this->reduce();
}
//constructor for float
Fraction::Fraction(float frac)
{   //if not a float throw error
    if (typeid(frac) != typeid(float))
    {
        throw invalid_argument("Error: frac must be a float");
    }

    // turn float frac into fraction of up to 3 dec accuracy (1000)
    int intF = (frac * 1000);
    int denom = 1000;
    //set attributes 
    this->numerator = intF;
    this->denominator = denom;
    //reduce fraction
    this->reduce();
}

// getters and setters
void Fraction::setNumerator(int num)
{
    this->numerator = num;
}
void Fraction::setDenominator(int denom)
{
    if(denom == 0){
        throw invalid_argument("Error: denom cant be 0");
    }
    this->denominator = denom;
}
const int &Fraction::getNumerator() const
{
    return this->numerator;
}
const int &Fraction::getDenominator() const
{
    return this->denominator;
}
//cheeck for overflow
void Fraction::cheeckOverFlow(long int num, long int denom) const{
    //max and min int values
    int MAX_INT = numeric_limits<int>::max();
    int MIN_INT = numeric_limits<int>::min();
    //if num is out of range
    if (num > MAX_INT || num < MIN_INT)
    {
        throw overflow_error("The value of the numerator has exceeded the limit");
    }
    //if denom is out of range
    if (denom > MAX_INT || denom < MIN_INT)
    {
        throw overflow_error("The value of the denominator has exceeded the limit");
    }
}

//binary operations:
//+
Fraction Fraction::operator+(const Fraction &other) const
{
    //if 0 + 0 return 0
    if (other.numerator == 0 && other.numerator == 0)
    {
        return (*this);
    }
    // a/b + c/d = (a*d + c*b)/b*d
    long int num = (static_cast<long int>(this->numerator) * other.denominator) + (static_cast<long int>(other.numerator) * this->denominator);
    long int denom = static_cast<long int>(this->denominator) * other.denominator;
    // check for overflow of int value
    cheeckOverFlow(num, denom);
    //return reduced fraction
    return Fraction(num, denom).reduce();
}
//-
Fraction Fraction::operator-(const Fraction &other) const
{
    //if 0 - 0 return 0
    if (this->getNumerator() == 0 && other.numerator == 0)
    {
        return (*this);
    }
    // a/b + c/d = (a*d - c*b)/b*d
    long int num = (static_cast<long int>(this->numerator) * other.denominator) - (static_cast<long int>(other.numerator) * this->denominator);
    long int denom = static_cast<long int>(this->denominator) * other.denominator;
    // check for overflow of int value
    cheeckOverFlow(num, denom);
    //return reduced fraction
    return Fraction(num, denom).reduce();
}

Fraction Fraction::operator*(const Fraction &other) const
{
    // a/b*c/d = a*c/b*d
    long int num = static_cast<long int>(this->numerator) * other.numerator;
    long int denom = static_cast<long int>(this->denominator) * other.denominator;
    //cheeck for over flow of int value
    cheeckOverFlow(num, denom);
    //return reduced fraction
    return Fraction(num, denom).reduce();
}

Fraction Fraction::operator/(const Fraction &other) const
{   
    // a/b/c/d = a/d*d/c
    //cant divide by zero
    if (other.numerator == 0){
        throw runtime_error("cant divide by 0");
    }
    return operator*(Fraction{other.denominator, other.numerator});
}

bool Fraction::operator==(const Fraction &other) const
{
    // if both 0 hence  0 = 0 return true
    if (numerator == 0 && other.numerator == 0)
    {
        return true;
    }
    float frac = (numerator + 0.0) / (denominator + 0.0);
    float otherF = (other.numerator + 0.0) / (other.denominator + 0.0);
    //return true when rounded to accuracy of 3 dec points // from geek.com
    return ((numerator == other.numerator) && (denominator == other.denominator)) || (round(frac * 1000.0) / 1000.0) == (round(otherF * 1000.0) / 1000.0);
}

bool Fraction::operator>(const Fraction &other) const
{
    // a/b ? c/d => ad ? bc
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<(const Fraction &other) const
{
    //if == or > false else must be < true
    if(operator==(other) || operator>(other)){
        return false;
    }
    return true;
}

bool Fraction::operator>=(const Fraction &other) const
{
    // if < false else == or > must be true
    if(operator<(other)){
        return false;
    }
    return true;
}

bool Fraction::operator<=(const Fraction &other) const
{
    // if > false else == or < must be true
    if(operator>(other)){
        return false;
    }
    return true;
}

Fraction &Fraction::operator++()
{
    // a+b/b => a/b + b/b => a/b + 1
    numerator += denominator;
    // return reference to the updates object so you can carry on working with it updated
    return *this;
}

Fraction Fraction::operator++(int)
{
    // temp for current version
    Fraction temp = *this;

    // add 1 => a+b/b => a/b + b/b => a/b + 1
    numerator += denominator;

    // return temp version
    return temp;
}

Fraction &Fraction::operator--()
{
    // a-b/b => a/b - b/b => a/b - 1
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int)
{
    // temp for current verison
    Fraction temp = *this;
    // a-b/b => a/b - b/b => a/b - 1
    numerator -= denominator;
    // return temp version
    return temp;
}

Fraction Fraction::operator+(const float frac)
{
    // return this frac + frac of float
    return (*this) + floatToFraction(frac);
}

Fraction Fraction::operator-(const float frac)
{
    // return this frac - frac of float
    return (*this) - floatToFraction(frac);
}

Fraction Fraction::operator*(const float frac)
{
    // return this frac * frac of float
    return (*this) * floatToFraction(frac);
}

Fraction Fraction::operator/(const float frac)
{
    // if float is 0 we cant divide
    if (frac == 0)
    {
        throw runtime_error("can't divide by zero");
    }
    // return this frac / frac of float
    return (*this) / floatToFraction(frac);
}

bool Fraction::operator==(const float frac)
{
    // return true or false of rounded version of frac and float to up to 3 dec points (1000)
    return (round(((numerator + 0.0) / (denominator + 0.0)) * 1000.0) / 1000.0) == round(frac * 1000.0) / 1000.0;
}

bool Fraction::operator>(const float frac)
{
    // return this frac > frac of float
    return (*this) > floatToFraction(frac);
}

bool Fraction::operator<(const float frac)
{
    // return this frac < frac of float
    return (*this) < floatToFraction(frac);
}

bool Fraction::operator>=(const float frac)
{
    // return this frac >= frac of float
    return (*this) >= floatToFraction(frac);
}

bool Fraction::operator<=(const float frac)
{
    // return this frac <= frac of float
    return (*this) <= floatToFraction(frac);
}

ostream &ariel::operator<<(std::ostream &outs, const Fraction &f)
{
    //returns printed version of frac : (a,b) => 'a/b'
    outs << f.numerator << "/" << f.denominator;
    return outs;
}

istream &ariel::operator>>(std::istream &ins, Fraction &f)
{
    
    int num, denom;
    if (ins >> num >> denom)
    {
        //denominatior is zero
        if (denom == 0)
        {
            throw runtime_error("denominator cant be 0");
        }
        //whole fraction is 0
        if (num == 0)
        {
            f.numerator = 0;
            f.denominator = denom;
        }
        else if ( denom < 0)
        {

            num *= -1;
            denom *= -1;
        }
        //asign f num and denom after if changes 
        f.numerator = num;
        f.denominator = denom;
        
    }
    else
    {
        throw runtime_error("error occured: ins needs to have num and den");
    }
    return ins;
}

// // Helper function to reduce a fraction to its simplest form
Fraction& Fraction::reduce()
{
    int gcdVal = gcd(this->getNumerator(), this->getDenominator()); // GCD standard function
    // num / gcd
    int num = numerator / gcdVal; 
    // denom / gcd            
    int denom = denominator / gcdVal;           
    //asign reduced num and denom
    this->denominator = denom;
    this->numerator = num;
    return *this;               
}

Fraction Fraction::floatToFraction(const float frac)
{
    // up to 3 dec points accuracy (1000)
    int denom = 1000;
    //float value rounded
    int intF = static_cast<int>(std::round(frac * 1000));
    
    return Fraction(intF, denom).reduce();
}

Fraction floatToFraction(const float frac)
{
    // up to 3 dec points accuracy (1000)
    int denom = 1000;
    //float value rounded
    int intF = static_cast<int>(std::round(frac * 1000));
    
    return Fraction(intF, denom).reduce();
}

// Helper function to calculate the greatest common divisor (GCD) of two integers
int Fraction::gcd(int num1, int num2) const
{
    //from geeks.com
    num1 = abs(num1);
    num2 = abs(num2);
    // euclidean algo for finding gcd(num1, num2) recursivly
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, (num1 % num2));
    }
}

Fraction ariel::operator+(const float fNum, const Fraction &frac)
{
    //return float to fraction + fraction
    return floatToFraction(fNum) + frac;
}

Fraction ariel::operator-(const float fNum, const Fraction &frac)
{
    //return float to fraction - fraction 
    return floatToFraction(fNum) - frac;
}

Fraction ariel::operator*(const float fNum, const Fraction &frac)
{
    //return float to fraction * fraction
    return floatToFraction(fNum) * frac;
}

Fraction ariel::operator/(const float fNum, const Fraction &frac)
{
    //return float to fraction / fraction
    return floatToFraction(fNum) / frac;
}

bool ariel::operator==(const float fNum, const Fraction &frac)
{
    Fraction floatToFract = floatToFraction(fNum);
    
    float fNum1 = round(fNum * 1000.0) / 1000.0;
    float fractionD = round(((frac.getNumerator() + 0.0) / (frac.getDenominator() + 0.0)) * 1000.0) / 1000.0;

    return ((floatToFract.getNumerator() == frac.getNumerator()) && (floatToFract.getDenominator() == frac.getDenominator())) || fNum1 == fractionD;
}

bool ariel::operator>(const float fNum, const Fraction &frac)
{
    // return Fraction1 == frac;
    return floatToFraction(fNum) > frac;
}

bool ariel::operator<(const float fNum, const Fraction &frac)
{
    // if > or == then false else must be true
    if(operator>(fNum,frac) || operator==(fNum, frac)){
        return false;
    }
    return true;

}

bool ariel::operator>=(const float fNum, const Fraction &frac)
{
    // if < then false else must be true
    if(operator<(fNum, frac)){
        return false;
    }
    return true;
}

bool ariel::operator<=(const float fNum, const Fraction &frac)
{
    // if > then false else must be true
    if(operator>(fNum, frac)){
        return false;
    }
    return true;
}
