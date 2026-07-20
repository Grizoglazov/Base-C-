#include<iostream>
#include"Function.h"

void menu();

int main() {

	menu();
	
	return 0;
}

void menu() {

	bool start{ true };
	do {
	
		std::cout << "Введите первое число:";
		int num1;
		std::cin >> num1;
		std::cout << "Введите второе число:";
		int num2;
		std::cin >> num2;

		std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень):";
		int select;
		std::cin >> select;

		switch (select)
		{
		case 1:
			std::cout << num1 << " + " << num2 << " = " << addition(num1, num2);
			break;
		case 2:
			std::cout << num1 << " - " << num2 << " = " << subtraction(num1, num2);
			break;
		case 3:
			std::cout << num1 << " * " << num2 << " = " << multiplication(num1, num2);
			break;
		case 4:
		{
			if (num2 != 0) {

				std::cout << num1 << " / " << num2 << " = " << division(static_cast<double>(num1), static_cast<double>(num2));
				break;
			}
			else
				std::cout << "Делить на 0 нельзя!!!!\n";
			break;
		}
		case 5:
			std::cout << "Число " << num1 << " в степени " << num2 << " = " << exponent(num1, num2);
			break;
		}

		std::cout << "\nДля выхода из программы нажми 0 или другую цифру что бы продолжить:\n";
		std::cin >> select;
		(select != 0)? start :start = false;

	} while (start);
	
}