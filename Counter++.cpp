#include<iostream>
#include<string>

enum class Simbol { plus = '+', minus = '-', equal = '=', exit = 'x' };

class Counter {

	int count;

public:

	void add();
	void subtract();
	void showCountConsole() const;
	int getCount() const;
	Counter() :count(1) {}
	Counter(int x) :count(x) {}
};

void start();

int main() {

	setlocale(LC_CTYPE, "RU.UTF-8");
	start();

	return 0;
}

void start() {

	bool start{ true };
	Counter count;

	std::cout << "Вы хотите указать начальное значение счётчика? "
		<< "Введите Yes или No: ";
	std::string choose;
	std::cin >> choose;

	if (choose == "Yes" || choose == "yes") {

		std::cout << "Введите начальное значение счётчика: ";
		int numCount;
		std::cin >> numCount;
		count = Counter(numCount);
	}

	do
	{
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		char select;
		std::cin >> select;

		Simbol userSelect = static_cast<Simbol>(select);

		switch (userSelect)
		{
		case Simbol::plus:
			count.add();
			break;
		case Simbol::minus:
			count.subtract();
			break;
		case Simbol::equal:
			count.showCountConsole();
			break;
		case Simbol::exit:
			std::cout << "\nДо свидания!";
			start = false;
		}

	} while (start);

}

void Counter::showCountConsole() const { std::cout << count << std::endl; }

void Counter::add() { ++count; }

void Counter::subtract() { --count; }

int Counter::getCount() const { return count; }