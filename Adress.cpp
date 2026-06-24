// Задача 3. Вывод структуры
#include<iostream>
#include<string>
#include<random>

struct Adress {

	std::string nameTown{};
	std::string nameStreet{};
	unsigned short numberHome = 0;
	unsigned short numberFlat = 0;
	unsigned numberIndex = 0;
};

void setAdress(Adress*, int);
void showAdress(Adress*, int);

int main() {
	setlocale(LC_CTYPE, "ru.UTF-8");

	int totalCount{ 5 };
	Adress* newAdress = new Adress[totalCount];

	setAdress(newAdress, totalCount);
	showAdress(newAdress, totalCount);

	delete[] newAdress;
	newAdress = nullptr;

	return 0;
}

void setAdress(Adress* x, int num) {

	std::string nameOfTown[]{ "Moscow", "Samara", "Sochi", "Tomsk", "Vladivostok" };
	std::string nameOfStreet[]{ "Arbatskaya", "Kuibysheva", "Navaginskaya", "Lenina", "Svetlanskaya" };
	unsigned massIndex[]{ 119010, 443019, 354015, 634021, 690105 };

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution countStreet(1, 50);
	std::uniform_int_distribution countHome(1, 100);

	for (size_t i = 0; i < num; ++i)
	{
		x[i].nameTown = nameOfTown[i];
		x[i].nameStreet = nameOfStreet[i];
		x[i].numberHome = countHome(gen);
		x[i].numberFlat = countStreet(gen);
		x[i].numberIndex = massIndex[i];
	}
}

void showAdress(Adress* x, int num) {

	for (size_t i = 0; i < num; ++i)
	{
		std::cout << "Город: " << x[i].nameTown << std::endl;
		std::cout << "Улица: " << x[i].nameStreet << std::endl;
		std::cout << "Номер дома: " << x[i].numberHome << std::endl;
		std::cout << "Номер квартиры: " << x[i].numberFlat << std::endl;
		std::cout << "Индекс: " << x[i].numberIndex << std::endl;
		std::cout << "----------------------------\n";
	}
}