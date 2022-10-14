#include "Fraction.h"

void Fraction::fracToIntInt(const Fraction& f, int& num1, int& num2)
{
	// сравнивать буду числители
	// предварительно проверю знаменатели на равенство
	num1 = this->numerator_;
	num2 = f.numerator_;

	// приведение к общ. знаменателю
	if (this->denominator_ != f.denominator_)
	{
		num1 *= f.denominator_;
		num2 *= this->denominator_;
		// с этого момента, знаменатели считаю равными
		// вычислять не буду
	}
}

Fraction::Fraction(int numerator, int denominator)
{
	if (numerator == 0 && denominator == 0)
	{
		throw std::domain_error("Числитель и знаменатель = 0, решения не существует.");
	}
	if (denominator == 0) throw std::overflow_error("Делитель = 0, решение стремится к бесконечности.");
	
	numerator_ = numerator;
	denominator_ = denominator;
	
	if (denominator_ < 0) // проверка/правка знаков
	{
		denominator_ *= -1;
		numerator_ *= -1;
	}
}

bool Fraction::operator == (const Fraction& fr)
{
	// числитель 1 и числитель 2
	int numer1 = 0;
	int numer2 = 0;

	// приводит к общ. знаменателю, возвращает числители
	fracToIntInt(fr, numer1, numer2);

	// сравниваю
	return (numer1 == numer2);
}
// сравнивает целиком объекты с помощью перегруженного ==
bool Fraction::operator != (Fraction& fr) { return !(*this == fr); }
bool Fraction::operator < (Fraction& fr)
{
	// числитель 1 и числитель 2
	int numer1 = 0;
	int numer2 = 0;

	// приводит к общ. знаменателю, возвращает числители
	fracToIntInt(fr, numer1, numer2);

	// сравниваю
	return (numer1 < numer2);
}
bool Fraction::operator > (Fraction& fr) { return (fr < *this); }
bool Fraction::operator <= (Fraction& fr) { return !(*this > fr); }
bool Fraction::operator >= (Fraction& fr) { return !(*this < fr); }