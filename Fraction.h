#pragma once

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;
	double div();

public:
	Fraction(int numerator, int denominator);

	bool operator == (Fraction);
	bool operator != (Fraction);
	bool operator < (Fraction);
	bool operator > (Fraction);
	bool operator <= (Fraction);
	bool operator >= (Fraction);
};