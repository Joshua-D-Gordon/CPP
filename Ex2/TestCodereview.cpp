#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <limits>
#include <vector>

using namespace ariel;
using namespace std;

TEST_SUITE("Fraction constructors tests") {

    TEST_CASE("Parameterized constructor with zero numerator") {
        CHECK_NOTHROW(Fraction frac{0, 4});
        CHECK_NOTHROW(Fraction frac{0, -4});

    }

    TEST_CASE("Parameterized constructor with zero denominator") {
        CHECK_THROWS_AS(Fraction frac(3, 0), std::invalid_argument);
        CHECK_THROWS_AS(Fraction frac(-4, 0), std::invalid_argument);
    }


    TEST_CASE("Parameterized constructor with regular arguments") {
        Fraction frac1{3, 4};
        CHECK_EQ(frac1, Fraction{3, 4});

        Fraction frac2{30, -60};
        CHECK_EQ(frac2, Fraction{-1, 2});
    }
}

TEST_SUITE("Fraction constructors tests") {
    TEST_CASE("Fraction constructor") {
        Fraction fract1(0.5);
        CHECK_EQ(fract1, Fraction{1,2});

        Fraction fract2(-0.5);
        CHECK_EQ(fract2, Fraction{-1,2});
        
    }
}

TEST_SUITE("default constructor") {
    Fraction frac1;
    TEST_CASE("default construct") {
        
        CHECK_EQ(frac1, Fraction{0,1});
    }
}

TEST_SUITE("getters and setters") {
    Fraction frac1(1,2);
    TEST_CASE("default check") {
        
        CHECK_EQ(frac1, Fraction(0.5));
    }

    TEST_CASE("getter check"){
        CHECK(frac1.getNumerator() == 1);
        CHECK(frac1.getDenominator() == 2);
    }

    TEST_CASE("setter check"){
        frac1.setNumerator(3);
        frac1.setDenominator(5);
        CHECK(frac1.getNumerator() == 3);
        CHECK(frac1.getDenominator() == 5);

    }

    TEST_CASE("set denom to 0"){
        CHECK_THROWS_AS(frac1.setDenominator(0), std::invalid_argument);
    }



}



TEST_SUITE("divide by 0") {
    Fraction frac1;
    TEST_CASE("div by 0") {
        
        CHECK_THROWS_AS(frac1/0, std::runtime_error);
        CHECK_THROWS_AS(frac1/Fraction(), std::runtime_error);
    }
}

TEST_SUITE("comps and 0's") {
    Fraction frac1(0,1);
    Fraction frac2(0,2);
    TEST_CASE("div by 0") {
        
        CHECK_EQ(frac1, frac2);
        CHECK_EQ(frac1 == frac2, 1);
        CHECK_EQ(frac1 >= frac2, 1);
        CHECK_EQ(frac1 <= frac2, 1);
        CHECK_EQ(frac1 > frac2, 0);
        CHECK_EQ(frac1 < frac2, 0);
    }
}