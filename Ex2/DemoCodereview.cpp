#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;
using namespace std;

int main() {
    cout<<"****************************DEMO***************************************"<<endl;
    cout<<"***********************************************************************\n"<<endl;
    cout<<"constructors Fractions , and (default constructor (0,1)):"<<endl;
    Fraction a(1,3), b(14,21),c(-2,4), d(-3,-9), e(4,-8), f;
    cout<<"a: "<< a << ", b: " << b << ", c: " << c << ", d: " << d << ", e: " << e << ", f: " << f <<endl;
    cout<<"\nconstructors Floats:"<<endl;
    Fraction g(0.5), h(-0.5), i(0.345);
    cout<<"g: "<< g << ", h: " << h << ", i: " << i <<endl;
    cout<<"\nsetters & getters"<<endl;
    g.setDenominator(4);
    h.setNumerator(1);
    cout<<"g: "<< g.getDenominator() << ", h: " << h.getNumerator() <<endl;
    cout<<"\n+, -, /, * fractions operations:"<<endl;
    cout << "a: " << a << ", b: " << b << endl;
    cout << "a+b " << a+b << endl; 
    cout << "a-b " << a-b << endl; 
    cout << "a/b " << a/b << endl; 
    cout << "a*b " << a*b << endl;
    cout<<"\nzero fractions operations: "<<endl;
    Fraction z1, z2;
    cout << "z1: " << z1 << ", z2: " << z2 << endl;
    cout << "z1+z2 " << z1+z2 << endl; 
    cout << "z1-z2 " << z1-z2 << endl; 
    cout << "z1*z2 " << z1*z2 << endl;
    cout<<"\ncompare fractions operations: "<<endl;
    Fraction c1(2,6), c2(1,3), c3(3,6);
    if(c1==c2) cout<< c1 << " is eq to " << c2 <<endl;
    if(c1!=c3) cout<< c1 << " is not eq to " << c3 <<endl;
    if(c1>=c2) cout<< c1 << " is bigger or eq to " << c2 <<endl;
    if(c1<=c2) cout<< c1 << " is smaller or eq to " << c2 <<endl;
    if(c1<=c3) cout<< c1 << " is smaller or eq to " << c3 <<endl;
    if(c1<c3) cout<< c1 << " is smaller than " << c3 <<endl;
    if(c3>c2) cout<< c3 << " is bigger than " << c2 <<endl;
    cout<<"\n++, -- operations: "<<endl;
    Fraction i1(2,3);
    cout << "i1: " << i1<<endl;
    i1++;
    cout << "i1++: " << i1<<endl;
    i1--;
    cout << "i1--: " << i1<<endl;

    cout<<"\nFloat and Fractions Operations *, +, -, / :"<<endl;
    cout<<"g: "<< g << ", h: " << h <<endl;
    cout << "2.*g " << 2*g << endl; 
    cout << "2.+g " << 2+g << endl;
    cout << "2.-g " << 2-g << endl;
    cout << "2./g " << 2/g << endl;
    cout<<"\nFractions and Float Operations *, +, -, / :"<<endl;
    cout << "h*2.5 " << h*2.5 << endl;
    cout << "h/2.5 " << h/2.5 << endl;
    cout << "h+2.5 " << h+2.5 << endl;
    cout << "h-2.5 " << h-2.5 << endl;

    cout<<"\ncompare floats & fractions operations: "<<endl;
    Fraction cf1(0.5), cf2(1,2), cf3(0.2), cf4(1,5);
    cout<<"cf1: "<< cf1 << ", cf2: " << cf2 <<"cf3: "<< cf3 << ", cf4: " << cf4<<endl;
    if(cf1==cf2) cout<<cf1<< " is eq to "<< cf2 <<endl;
    if(cf1!=cf3) cout<<cf1<< " is not eq to "<< cf3 <<endl;
    if(cf1<=cf2) cout<<cf1<< " is smaller or eq to "<< cf2 <<endl;
    if(cf1>=cf2) cout<<cf1<< " is bigger or eq to "<< cf2 <<endl;
    if(cf3<cf2) cout<<cf3<< " is smaller than "<< cf2 <<endl;
    if(cf1>cf4) cout<<cf1<< " is bigger than "<< cf4 <<endl;

    cout<<"\nPrint ifs floats and fracts: "<<endl;

    if (Fraction(5,3) > 1.1) cout << " 5/3 is bigger than 1.1" << endl;
    if (Fraction(1,2) < 1.1) cout << " 1/2 a is smaller than 1.1" << endl;
    if (Fraction(1.1) == 1.1) cout << " 11/10  is eqaul to 1.1" << endl;
    if (Fraction(12/10) != 1.1) cout << " 12/10  is not eq to 1.1" << endl;

    cout<<"\n^^^^^ operator"<<endl;

    Fraction pf1(1,2);
    Fraction pf2(2,3);

    cout<<(pf1^3)<<endl;
    cout<<(pf2^3)<<endl;
    
}