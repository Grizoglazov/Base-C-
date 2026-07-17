#include<iostream>
#include<locale>

class Figure {

private:

	int mSide{0};
	std::string mName{"Фигура"};

public:

	Figure() = default;
	Figure(int side, const std::string& name) : mSide{ side }, mName{name} {};
	
	int getType() const;
	const std::string& getName() const;
	void showType() const;

};

class Triangle: public Figure {

public:

	Triangle(): Figure(3, "Треугольник") {}
};

class Quadrilateral : public Figure {

public:

	Quadrilateral() :Figure(4, "Четырёхугольник") {}
};


int main() {

	std::locale::global(std::locale("RU.UTF-8"));

	Figure myFigure;
	Triangle myTriangle;
	Quadrilateral myQuadrilateral;
	std::cout << "Количество сторон:\n";

	myFigure.showType();
	myTriangle.showType();
	myQuadrilateral.showType();

	return 0;
}

void Figure::showType() const { std::cout << getName() << ": " << getType() << std::endl; }

int Figure::getType() const { return mSide; }

const std::string& Figure::getName() const { return mName; }