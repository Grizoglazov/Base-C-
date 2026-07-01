#include<iostream>
#include<iomanip>

class Calculator {

	double num1;
	double num2;

public:

	void setNum() {
		std::cout << "Введите num1:";
		std::cin >> num1;
		while (set_num1(num1) != true) {

			std::cout << "В условии используется операция деления, использование 0 не допустимо!!!\n"
				<< "Повторите ввод с корректными значениями!! Введите num1:\n";
			std::cin >> num1;
		}

		std::cout << "Введите num2:";
		std::cin >> num2;
		while (set_num2(num2) != true) {

			std::cout << "В условии используется операция деления, использование 0 не допустимо!!!\n"
				<< "Повторите ввод с корректными значениями!! Введите num2:\n";
			std::cin >> num2;
		}

	}

	void showNum() const {

		std::cout << num1 << std::endl;
		std::cout << num2 << std::endl;
	}

	double add() const;						// метод должен возвращать результат сложения num1 и num2
	double multiply() const;				// метод должен возвращать результат перемножения num1 и num2
	double subtract_1_2() const;			// метод должен возвращать результат вычитания num2 из num1
	double subtract_2_1() const;			// метод должен возвращать результат вычитания num1 из num2
	double divide_1_2() const;				// метод должен возвращать результат деления num1 на num2
	double divide_2_1() const;				// метод должен возвращать результат деления num2 на num1
	bool set_num1(double num1) {

		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		else
			return false;
	}

	bool set_num2(double num2) {

		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		else
			return false;
	}

};

void printData();

int main() {

	setlocale(LC_CTYPE, "RU.UTF-8");
	std::cout << std::fixed << std::setprecision(2);
	printData();

	return 0;
}

double Calculator::add() const { return num1 + num2; }

double Calculator::multiply() const { return num1 * num2; }

double Calculator::subtract_1_2() const { return num1 - num2; }

double Calculator::subtract_2_1() const { return num2 - num1; }

double Calculator::divide_1_2() const { return num1 / num2; }

double Calculator::divide_2_1() const { return num2 / num1; }

void printData() {

	bool resume{ true };
	Calculator numbers;
	do
	{
		numbers.setNum();
		numbers.showNum();

		double addNums = numbers.add();
		double subtractNums_1_2 = numbers.subtract_1_2();
		double subtractNums_2_1 = numbers.subtract_2_1();
		double multiplyNums = numbers.multiply();
		double divideNums_1_2 = numbers.divide_1_2();
		double divideNums_2_1 = numbers.divide_2_1();

		std::cout << "num1 " << " + " << " num2 = " << addNums << std::endl;
		std::cout << "num1 " << " - " << " num2 = " << subtractNums_1_2 << std::endl;
		std::cout << "num2 " << " - " << " num1 = " << subtractNums_2_1 << std::endl;
		std::cout << "num1 " << " * " << " num2 = " << multiplyNums << std::endl;
		std::cout << "num1 " << " / " << " num2 = " << divideNums_1_2 << std::endl;
		std::cout << "num2 " << " / " << " num1 = " << divideNums_2_1 << std::endl;
		std::cout << "******************************\n";
		std::cout << "Продолжить нажми 1 или выйти 0\n";
		int exit;
		std::cin >> exit;
		if (exit != 1)
			resume = false;
	} while (resume);

}