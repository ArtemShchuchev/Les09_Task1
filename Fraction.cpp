#include "Fraction.h"

// ну, конечно вы правы без приведения к double работать не будет,
// я даже делал это (или видимо хотел сделать), было позно, видимо просмотрел )
double Fraction::div() { return static_cast<double>(numerator_) / denominator_; }

Fraction::Fraction(int numerator, int denominator)
{
	if (numerator == 0 && denominator == 0)
	{
		throw std::domain_error("Числитель и знаменатель = 0, решения не существует.");
	}
	if (denominator == 0) throw std::overflow_error("Делитель = 0, решение стремится к бесконечности.");
	
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