#include "Fraction.h"


double Fraction::div() { return numerator_ / denominator_; }

Fraction::Fraction(int numerator, int denominator)
{
	numerator_ = numerator;
	if (denominator == 0) throw std::overflow_error("�������� = 0");
	denominator_ = denominator;
}

bool Fraction::operator == (Fraction fr)
{
	// ���������� �������� ������ ���� ������
	// �������������� �������� �������
	return (div() == fr.div());
}
bool Fraction::operator != (Fraction fr)
{
	// ���������� ������� ������� � ������� �������������� ==
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