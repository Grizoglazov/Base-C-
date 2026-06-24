// Задача 1. Месяцы

#include<iostream>

enum class Months {
	January = 1, February, March,
	April, May, June,
	July, August, September,
	October, November, December
};

void userMonths();

int main() {
	setlocale(LC_CTYPE, "ru.UTF-8");

	userMonths();

	return 0;
}

void userMonths() {

	bool start{true};
	while(start)
	{
		int numMonth{};
		std::cout << "Введите номер месяца:\n";
		std::cin >> numMonth;

		Months userMonths = static_cast<Months>(numMonth);

		switch (userMonths) {

		case Months::January:
			std::cout << "Январь\n";
			break;
		case Months::February:
			std::cout << "Февраль\n";
			break;
		case Months::March:
			std::cout << "Март\n";
			break;
		case Months::April:
			std::cout << "Апрель\n";
			break;
		case Months::May:
			std::cout << "Май\n";
			break;
		case Months::June:
			std::cout << "Июнь\n";
			break;
		case Months::July:
			std::cout << "Июль\n";
			break;
		case Months::August:
			std::cout << "Август\n";
			break;
		case Months::September:
			std::cout << "Сентябрь\n";
			break;
		case Months::October:
			std::cout << "Октябрь\n";
			break;
		case Months::November:
			std::cout << "Ноябрь\n";
			break;
		case Months::December:
			std::cout << "Декабрь\n";
			break;
		default:
			std::cout << "Такого месяца не существует!!\n";
			std::cout << "До свидания!\n";
			start = false;
		}
		
	}
}

