// Karol Stanski
// Student ID: 20038816
// Net ID: 16ks34

#ifndef FRACTION_16KS34_H_
#define FRACTION_16KS34_H_

#include <iostream>
#include <string>

using namespace std;

class Fraction {
private:
	int num; // numerator
	int den; // denominator
	int gcd(int, int); // greatest common divisor
public:
	Fraction(); // constructor (returns "0/1")
	Fraction(int); // constructor (numerator = 1)
	Fraction(int, int); // constructor (setting numerator and denominator to the inputted numbers)

	int numerator() const; // getter
	int denominator() const; // getter

	// Unary operators:
	Fraction operator-(); // - operator (negative sign)
	Fraction& operator++(); // ++ operator (post increment)
	Fraction operator++(int); // ++ operator (pre-increment)

	// Binary operators:
	friend Fraction operator+(const Fraction& e1, const Fraction& e2); // + operator
	friend Fraction operator-(const Fraction& e1, const Fraction& e2); // - operator
	friend Fraction operator*(const Fraction& e1, const Fraction& e2); // * operator
	friend Fraction operator/(const Fraction& e1, const Fraction& e2); // / operator
	Fraction& operator+=(const Fraction& e); // += operator

	friend bool operator<(const Fraction& e1, const Fraction& e2); // < comparison operator
	friend bool operator<=(const Fraction& e1, const Fraction& e2); // <= comparison operator
	friend bool operator==(const Fraction& e1, const Fraction& e2); // == comparison operator
	friend bool operator!=(const Fraction& e1, const Fraction& e2); // != comparison operator
	friend bool operator>=(const Fraction& e1, const Fraction& e2); // >= comparison operator
	friend bool operator>(const Fraction& e1, const Fraction& e2); // > comparison operator

	friend ostream& operator<<(ostream& out, const Fraction& e); // << operator
	friend istream& operator>>(istream& in, Fraction& retFrac); // >> operator
};

class FractionException {
private:
	string errorMsg; // error message
public:
	FractionException(const string& msg); // constructor
	string what(); // returns error message
};

#endif /* FRACTION_16KS34_H_ */
