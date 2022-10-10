#include <iostream> // консоль - cout
#include "Fraction.h"


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

    std::cout << "Задача 1. Сравнения в дробях\n";
    std::cout << "----------------------------\n" << std::endl;

	try
	{
		Fraction f1(4, 3);
		Fraction f2(6, 11);

		std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
		std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
		std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
		std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
		std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
		std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	}
	catch (std::overflow_error& err)
	{
		std::cout << "Ошибка: " << err.what() << std::endl;
	}

    return 0;
}

/*
Задача 1. Сравнения в дробях
В этом задании вы переопределите операторы сравнения для дробей.

Дан код на C++...


Ваша задача — дописать класс Fraction так, чтобы программа компилировалась и работала корректно.

Пример работы программы
Консоль
f1 not == f2
f1 != f2
f1 not < f2
f1 > f2
f1 not <= f2
f1 >= f2
*/