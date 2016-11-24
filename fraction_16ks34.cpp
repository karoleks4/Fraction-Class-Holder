// Karol Stanski
// Student ID: 20038816
// Net ID: 16ks34

#include "fraction_16ks34.h"

#include <iostream>
#include <cstdlib>


using namespace std;

// For Fraction:
int Fraction :: gcd (int n, int m) {
	if (m <= n && n % m == 0) {
		return m;
	} else if (n < m) {
		return gcd(m, n);
	} else {
		return gcd(m, n % m);
	}
}

Fraction :: Fraction() : num(0), den(1) {
}
Fraction :: Fraction(int e1) : num(e1), den(1) {
}
Fraction :: Fraction(int e1, int e2) {
	if (e2 == 0) {
		throw FractionException("Error!!! Denominator cannot be equal to 0!!!");
	}
	int divisor = gcd(abs(e1), abs(e2));
	if (e2 < 0) {
		num = -(e1 / divisor);
		den = -(e2 / divisor);
	} else {
		num = e1 / divisor;
		den = e2 / divisor;
	}
}
int Fraction :: numerator() const {
	return num;
}
int Fraction :: denominator() const {
	return den;
}
Fraction Fraction :: operator-() {
	return Fraction(-num, den);
}
Fraction& Fraction :: operator++() {
	num += den;
	return *this;
}
Fraction Fraction :: operator++(int e) {
	Fraction f(num,den);
	num += den;
	return f;
}
Fraction operator+ (const Fraction& e1, const Fraction& e2) {
	if (e1.denominator() == e2.denominator()) {
		return Fraction((e1.numerator() + e2.numerator()) , e1.denominator());
	} else {
		return Fraction(((e1.numerator() * e2.denominator()) + (e2.numerator() * e1.denominator())), (e1.denominator() * e2.denominator()));
	}
}
Fraction operator- (const Fraction& e1, const Fraction& e2) {
	if (e1.denominator() == e2.denominator()) {
		return Fraction((e1.numerator() - e2.numerator()) , e1.denominator());
	} else {
		return Fraction(((e1.numerator() * e2.denominator()) - (e2.numerator() * e1.denominator())), (e1.denominator() * e2.denominator()));
	}
}
Fraction operator* (const Fraction& e1, const Fraction& e2) {
	return Fraction ((e1.numerator() * e2.numerator()), (e1.denominator() * e2.denominator()));
}
Fraction operator/ (const Fraction& e1, const Fraction& e2) {
	return Fraction((e1.numerator() * e2.denominator()), (e1.denominator() * e2.numerator()));
}
Fraction& Fraction :: operator+=(const Fraction& e) {
	Fraction f = Fraction(num, den) + e;
	num = f.num;
	den = f.den;
	return *this;
}
bool operator<(const Fraction& e1, const Fraction& e2) {
	return (e1.numerator() * e2.denominator()) < (e2.numerator() * e1.denominator());
}
bool operator<=(const Fraction& e1, const Fraction& e2) {
	return (e1.numerator() * e2.denominator()) <= (e2.numerator() * e1.denominator());
}
bool operator==(const Fraction& e1, const Fraction& e2) {
	return (e1.numerator() == e2.numerator()) && (e1.denominator() == e2.denominator());
}
bool operator!=(const Fraction& e1, const Fraction& e2) {
	return (e1.numerator() != e2.numerator()) || (e1.denominator() != e2.denominator());
}
bool operator>=(const Fraction& e1, const Fraction& e2) {
	return (e1.numerator() * e2.denominator()) >= (e2.numerator() * e1.denominator());
}
bool operator>(const Fraction& e1, const Fraction& e2) {
	return (e1.numerator() * e2.denominator()) > (e2.numerator() * e1.denominator());
}
ostream& operator<<(ostream& out, const Fraction& e) {
   out << e.numerator() << "/" << e.denominator();
   return out;
}
istream& operator>>(istream& in, Fraction& retFrac) {
   int top, bottom;
   // Read the top
   in >> top;
   // If there more than just an enter key, read the next number
   // after skipping the / sign.
   if (in.peek() != 10) {
	   char nextChar;
	   in >> nextChar;
	   if (nextChar == '/')
		  in >> bottom;
	   else
		   bottom = 1;
	   retFrac = Fraction(top, bottom);
   } else
	   retFrac = Fraction(top);
   return in;
}

// For FractionException:
FractionException :: FractionException(const string& msg) : errorMsg(msg) {
}
string FractionException :: what() {
	return errorMsg;
}
