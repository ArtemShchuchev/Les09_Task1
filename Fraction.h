#pragma once

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	void fracToIntInt(const Fraction&, int&, int&);

public:
	Fraction(int numerator, int denominator);

	bool operator == (const Fraction&);
	bool operator != (Fraction&);
	bool operator < (Fraction&);
	bool operator > (Fraction&);
	bool operator <= (Fraction&);
	bool operator >= (Fraction&);
};