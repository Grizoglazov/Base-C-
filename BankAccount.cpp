// Задача 2. Счета

#include<iostream>
#include<string>
#include <iomanip>

struct BankAccount {

	unsigned account{};
	std::string nameOwner{};
	double deposit{};
};

void setBalance(BankAccount*, int);
void showBalance(BankAccount*, int);

int main() {
	setlocale(LC_CTYPE, "ru.UTF-8");
	std::cout << std::fixed << std::setprecision(2);

	int amountUser{ 3 };
	BankAccount* user = new BankAccount[amountUser];

	for (size_t i = 0; i < amountUser; ++i)
	{
		std::cout << "Введите номер счёта:\n";
		std::cin >> user[i].account;
		std::cout << "Введите имя владельца:\n";
		std::cin >> user[i].nameOwner;
		std::cout << "Введите баланс:\n";
		std::cin >> user[i].deposit;
	}

	setBalance(user, amountUser);
	showBalance(user, amountUser);

	delete[] user;
	user = nullptr;

	return 0;
}

void setBalance(BankAccount* x, int num) {

	for (size_t i = 0; i < num; ++i)
	{
		std::cout << "Владелец: " << x[i].nameOwner << ", на вашем счету: "
			<< x[i].account << ", текущий баланс составляет - "
			<< x[i].deposit << std::endl;
		std::cout << "Введите новый баланс:\n";
		std::cin >> x[i].deposit;
	}
}

void showBalance(BankAccount* x, int num) {

	for (size_t i = 0; i < num; ++i)
	{
		std::cout << i << ". " << x[i].nameOwner << " ваш новый баланс: " << x[i].deposit << std::endl;
	}

}