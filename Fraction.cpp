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

/*
//	Привожу к правильной дроби
//		105		  3		  1
//		---	->	17-	->	17-
//		 6		  6		  2
void Fraction::toProperFract(Fraction& f)
{
	exception(f); // проверка исключений

	if (f.numerator_ / f.denominator_)	// если дробь неправильная
	{
		int znak = 1;	// предположу, что число положительное
		if (f.whole_ < 0)
		{
			f.whole_ *= -1;		// модуль числа
			znak = -1;			// число отрицательное
		}
		if (f.numerator_ < 0)
		{
			f.numerator_ *= -1;	// модуль числа
			znak = -1;			// число отрицательное
		}

		f.whole_ += f.numerator_ / f.denominator_;
		f.numerator_ %= f.denominator_;
		f.whole_ *= znak;		// вернул знак
	}

	// упрощаю дробь (ищу общий множитель)
	int multiplier = f.numerator_ < 0 ? f.numerator_ * -1 : f.numerator_;
	while (multiplier > 1)
	{
		// если знаменатель делится на multiplier без остатка
		// и числитель делится на multiplier без остатка
		if (!(f.denominator_ % multiplier) && !(f.numerator_ % multiplier))
		{
			f.numerator_ /= multiplier;
			f.denominator_ /= multiplier;
			break;
		}
		--multiplier;
	};
}

//	Привожу к НЕправильной дроби
//		 1		7
//		2-	->	-
//		 3		3
void Fraction::toImproperFract(Fraction& f)
{
	if (f.whole_)	// если дробь правильная
	{
		int znak = 1;	// предположу, что число положительное
		if (f.whole_ < 0)
		{
			f.whole_ *= -1;		// модуль числа
			znak = -1;			// число отрицательное
		}
		if (f.numerator_ < 0)
		{
			f.numerator_ *= -1;	// модуль числа
			znak = -1;			// число отрицательное
		}

		f.numerator_ += f.whole_ * f.denominator_;
		f.whole_ = 0;
		f.numerator_ *= znak;	// вернул знак
	}
}
*/

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