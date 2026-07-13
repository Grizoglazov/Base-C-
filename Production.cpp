#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>



class Production {

	std::string productName{};								// Название продукции
	std::string productManufacturer{};						// Изготовитель				
	unsigned productQuantity{};								// Количество
	unsigned productArticle{};								// Артикул
	double productPrice{};									// Цена

public:

	Production() = default;
	
	Production(const std::string& name, const std::string& manufactured, unsigned quantity, unsigned article) :
	productName{ name }, productManufacturer{ manufactured }, productQuantity{ quantity }, productArticle{ article } {}

	void setPrice(double);

	std::string getProductName() const;
	std::string getProductManufacturer() const;
	unsigned getProductQuantity() const;
	unsigned getProductArticle() const;
	double getPrice() const;
	double getCostProduct() const;

};

int start();

int main() {

	std::cout << std::fixed << std::setprecision(2);
	
	setlocale(LC_CTYPE, "RU.UTF-8");

	int mistake = start();
	if (mistake == 0) std::cout << "Программа выполнилась успешно!!!\n";
	else
		std::cout << "Почините файл или указанный адрес расположения!!!\n";

	return 0;
}

int start() {

	std::ifstream readIn("in.txt");
	int count{};
	std::string readN{};
	std::string readM{};
	unsigned readQ{};
	unsigned readA{};

	if (!readIn) return 1;

	readIn >> count;
	readIn.ignore();

	Production* product = new Production[count];

	for (size_t i = 0; i < count; ++i)
	{
		getline(readIn, readN);
		getline(readIn, readM);
		readIn >> readQ;
		readIn >> readA;
		readIn.ignore();
		product[i] = Production(readN, readM, readQ, readA);
	}

	readIn.close();

	std::ofstream saveOut("out.txt");
	if (!saveOut) return 1;

	saveOut << count << std::endl;
	if (count == 0) return 1;

	for (int i = count - 1; i >= 0; i--)
	{
		saveOut << product[i].getProductName() << ", ";
		saveOut << product[i].getProductManufacturer() << ", ";
		saveOut << product[i].getProductQuantity() << ", ";
		saveOut << product[i].getProductArticle() << ".\n";
	}

	saveOut.close();

	std::ifstream readPrice("price.txt");

	if (!readPrice) return 1;	

	double price{};
	for (size_t i = 0; i < count; i++)
	{
		readPrice >> price;
		product[i].setPrice(price);
	}

	readPrice.close();

	std::ofstream saveProduct("sort.txt");

	if (!saveProduct) return 1;

	for (size_t step = 0; step < count - 1; ++step)
	{
		for (size_t j = 0; j < count - 1 - step; ++j)
		{
			if (product[j].getCostProduct() < product[j + 1].getCostProduct())
			{
				Production temp = product[j];
				product[j] = product[j + 1];
				product[j + 1] = temp;
			}
		}
	}

	saveProduct << count << std::endl;
	saveProduct << std::fixed << std::setprecision(2);

	for (size_t i = 0; i < count; i++)
	{
		saveProduct << product[i].getProductName() << ", ";
		saveProduct << product[i].getProductManufacturer() << ", ";
		saveProduct << product[i].getProductQuantity() << ", ";
		saveProduct << product[i].getProductArticle() << ", ";
		saveProduct << "Стоимость: " << product[i].getCostProduct() << std::endl;
	}

	saveProduct.close();

	std::ofstream sortName("sortname.txt");
	if (!sortName) return 1;
	
	for (size_t step = 0; step < count - 1; step++)
	{
		for (size_t j = 0; j < count - 1 - step; j++)
		{
			if (product[j].getProductName() < product[j + 1].getProductName())
			{
				Production temp = product[j];
				product[j] = product[j + 1];
				product[j + 1] = temp;

			}
		}
	}

	sortName << count << std::endl;
	sortName << std::fixed << std::setprecision(2);

	for (size_t i = 0; i < count; i++)
	{
		sortName << product[i].getProductName() << ", ";
		sortName << product[i].getProductManufacturer() << ", ";
		sortName << product[i].getProductQuantity() << ", ";
		sortName << product[i].getProductArticle() << ", ";
		sortName << "Стоимость: " << product[i].getCostProduct() << std::endl;
	}

	sortName.close();

	delete[] product;

	return 0;
}



void Production::setPrice(double price) { productPrice = price; }

double Production::getPrice( ) const { return productPrice; }

std::string Production::getProductName() const { return productName; }

std::string Production::getProductManufacturer() const { return productManufacturer; }

unsigned Production::getProductQuantity() const { return productQuantity; }

unsigned Production::getProductArticle() const { return productArticle; }

double Production::getCostProduct() const { return (getProductQuantity() * getPrice()); }


