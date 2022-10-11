#include "Fraction.h"


double Fraction::div() { return numerator_ / denominator_; }

Fraction::Fraction(int numerator, int denominator)
{
	if (numerator == 0) throw std::domain_error("Числитель = 0, решени¤ не существует.");
	if (denominator == 0) throw std::overflow_error("Делитель = 0, решение стремитс¤ к бесконечности.");
	
	numerator_ = numerator;
	denominator_ = denominator;
}

bool Fraction::operator == (Fraction fr)
{
	// сравнивает отдельно каждое поле класса
	// предварительно выполнив деление
	return (div() == fr.div());
}
bool Fraction::operator != (Fraction fr)
{
	// сравнивает целиком объекты с помощью перегруженного ==
	return !(*this == fr);
}
bool Fraction::operator < (Fraction fr)
{
	return (div() < fr.div());
}
bool Fraction::operator > (Fraction fr)
{
	return (fr.div() < div());
}
bool Fraction::operator <= (Fraction fr)
{
	return !(div() > fr.div());
}
bool Fraction::operator >= (Fraction fr)
{
	return !(div() < fr.div());
}