#include<iostream>
#include<string>


class Figure {

public:

	virtual int getSideCount() const = 0;
	virtual void printInfo() const = 0;
	virtual bool isValid() const = 0;
	virtual ~Figure() = default;
};

// Стороны фигуры Четырехугольник
struct SidesQuadrilateral {

	int SideA;
	int SideB;
	int SideC;
	int SideD;

};

// Углы фигуры Четырехугольник
struct CornersQuadrilateral {

	int CornerA;
	int CornerB;
	int CornerC;
	int CornerD;

};

// Четырехугольник (базовый класс - родитель)
class Quadrilateral :public Figure {
private:

	// Имя фигуры
	std::string mName{ "No name" };
	// Длины сторон
	SidesQuadrilateral Length{ 0,0,0,0 };
	// Углы 
	CornersQuadrilateral Data{ 0,0,0,0 };

public:

	Quadrilateral() = delete; // все объекты класса только через конструтор с параметрами  
	Quadrilateral(const std::string& name, int sideA, int sideB, int sideC, int sideD,
		int cornerA, int cornerB, int cornerC, int cornerD) : mName{ name }, Length{
		sideA, sideB, sideC, sideD }, Data{ cornerA, cornerB, cornerC, cornerD } {
	}

	void printInfo() const override;
	int getSideCount() const override;
	bool isValid() const override {

		int sumCorner = getCornerA() + getCornerB() + getCornerC() + getCornerD();
		return sumCorner == 360;
	};

	bool isRectangle() const;
	bool isRhomb() const;
	bool isSquare() const;
	bool isParallelogram() const;

	const std::string& getName() const;

	int getSideA() const;
	int getSideB() const;
	int getSideC() const;
	int getSideD() const;

	int getCornerA() const;
	int getCornerB() const;
	int getCornerC() const;
	int getCornerD() const;

};

// Прямоугольник (производный класс от класса Четырехугольник)
class Rectangle : public Quadrilateral {


public:

	Rectangle(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD)
		:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {
	}

	bool isValid() const override {

		return Quadrilateral::isValid() && isRectangle();
	}
};

// Ромб (производный класс от класса Четырехугольник)
class Rhomb : public Quadrilateral {


public:

	Rhomb(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD)
		:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {
	}

	bool isValid() const override {

		return Quadrilateral::isValid() && isRhomb();
	}
};

// Квадрат (производный класс от класса Четырехугольник)
class Square : public Quadrilateral {


public:

	Square(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD)
		:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {
	}

	bool isValid() const override {

		return Quadrilateral::isValid() && isSquare();
	}
};

// Параллелограмм (производный класс от класса Четырехугольник)
class Parallelogram : public Quadrilateral {


public:

	Parallelogram(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD)
		:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {
	}

	bool isValid() const override {

		return Quadrilateral::isValid() && isParallelogram();
	}
};

// Стороны фигуры треугольник
struct SidesTriangle {

	int SideA;
	int SideB;
	int SideC;
};

// Углы фигуры треугольник
struct CornersTriangle {

	int CornerA;
	int CornerB;
	int CornerC;
};


// Треугольник (базовый класс - родитель)
class Triangle : public Figure {
private:

	// Имя фигуры
	std::string mName{ "No name" };
	// Длины сторон
	SidesTriangle Length{ 0,0,0 };
	// Углы 
	CornersTriangle Data{ 0,0,0 };

public:

	Triangle() = delete; // все объекты класса только через конструтор с параметрами
	Triangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
		mName{ name }, Length{ sideA, sideB, sideC }, Data{ cornerA, cornerB, cornerC } {
	}

	bool isRighttriangle() const;
	bool isIsoscelesTriangle() const;
	bool isEquilateralTriangle() const;

	bool isValid() const override {
		int sumCorner = getCornerA() + getCornerB() + getCornerC();
		return sumCorner == 180;
	}

	void printInfo() const override;
	int getSideCount() const override;


	const std::string& getName() const;

	int getSideA() const;
	int getSideB() const;
	int getSideC() const;


	int getCornerA() const;
	int getCornerB() const;
	int getCornerC() const;

};

class Righttriangle : public Triangle {

public:

	Righttriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
		Triangle(name, sideA, sideB, sideC, cornerA, cornerB, cornerC) {
	}

	bool isValid() const override {

		return Triangle::isValid() && isRighttriangle();
	}
};

class IsoscelesTriangle : public Triangle {

public:

	IsoscelesTriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
		Triangle(name, sideA, sideB, sideC, cornerA, cornerB, cornerC) {
	}

	bool isValid() const override {

		return Triangle::isValid() && isIsoscelesTriangle();
	}

};

class EquilateralTriangle : public Triangle {

public:
	EquilateralTriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
		Triangle(name, sideA, sideB, sideC, cornerA, cornerB, cornerC) {
	}

	bool isValid() const override {

		return Triangle::isValid() && isEquilateralTriangle();
	}

};

void printInfo(const Figure* obj) { obj->printInfo(); }
int getSideCount(const Figure* obj) { return obj->getSideCount(); }


int main() {
	setlocale(LC_CTYPE, "ru.UTF-8");

	Quadrilateral Quadr{ "Четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80 };
	printInfo(&Quadr);

	Rectangle Rect{ "Прямоугольник", 10, 20, 10, 20, 90, 90, 90, 90 };
	printInfo(&Rect);

	Rhomb Romb{ "Ромб", 30, 30, 30, 30, 30, 40, 30, 40 };
	printInfo(&Romb);

	Square Squa{ "Квадрат", 20, 20, 20, 20, 90, 90, 90, 90 };
	printInfo(&Squa);

	Parallelogram Parall{ "Параллелограмм", 20, 30, 20, 30, 30, 40, 30, 40 };
	printInfo(&Parall);

	Triangle Trian{ "Треугольник", 40, 40, 40, 45, 45, 90 };
	printInfo(&Trian);

	Righttriangle Rtriangle{ "Прямоугольный треугольник", 60, 40, 30, 40, 20, 90 };
	printInfo(&Rtriangle);

	IsoscelesTriangle IsoTriangle{ "Равнобедренный треугольник", 40, 50, 40, 50, 30, 50 };
	printInfo(&IsoTriangle);

	EquilateralTriangle EquilTriangle{ "Равносторонний треугольник", 45, 45, 45, 60, 60, 60 };
	printInfo(&EquilTriangle);

	return 0;
}


const std::string& Quadrilateral::getName() const { return mName; }

int Quadrilateral::getSideA() const { return Length.SideA; }
int Quadrilateral::getSideB() const { return Length.SideB; }
int Quadrilateral::getSideC() const { return Length.SideC; }
int Quadrilateral::getSideD() const { return Length.SideD; }

int Quadrilateral::getCornerA() const { return Data.CornerA; }
int Quadrilateral::getCornerB() const { return Data.CornerB; }
int Quadrilateral::getCornerC() const { return Data.CornerC; }
int Quadrilateral::getCornerD() const { return Data.CornerD; }

void Quadrilateral::printInfo() const {

	std::cout << getName() << ":\n" << (isValid() ? "Правильная фигура\n" : "Не правильная фигура\n")
		<< "Количество сторон: " << getSideCount()
		<< "\nСтороны:" << " a=" << getSideA()
		<< " b=" << getSideB() << " c=" << getSideC()
		<< " d=" << getSideD() << std::endl;
	std::cout << "Углы:" << " A=" << getCornerA()
		<< " B=" << getCornerB()
		<< " C=" << getCornerC()
		<< " D=" << getCornerD() << std::endl;

}

// прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);
bool Quadrilateral::isRectangle() const {

	return ((getSideA() == getSideC() && getSideB() == getSideD()) && (getCornerA() == 90 && getCornerB() == 90 && getCornerC() == 90 && getCornerD() == 90));
}

// ромб (все стороны равны, углы A,C и B,D попарно равны).
bool Quadrilateral::isRhomb() const {

	return ((getSideA() == getSideB() && getSideB() == getSideC() && getSideC() == getSideD()) && (getCornerA() == getCornerC() && getCornerB() == getCornerD()));
}

// квадрат (все стороны равны, все углы равны 90);
bool Quadrilateral::isSquare() const {

	return ((getSideA() == getSideB() && getSideB() == getSideC() && getSideC() == getSideD()) && (getCornerA() == 90 && getCornerB() == 90 && getCornerC() == 90 && getCornerD() == 90));
}

// параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);
bool Quadrilateral::isParallelogram() const {

	return ((getSideA() == getSideC() && getSideB() == getSideD()) && (getCornerA() == getCornerC() && getCornerB() == getCornerD()));
}

const std::string& Triangle::getName() const { return mName; }

int Triangle::getSideA() const { return Length.SideA; }
int Triangle::getSideB() const { return Length.SideB; }
int Triangle::getSideC() const { return Length.SideC; }


int Triangle::getCornerA() const { return Data.CornerA; }
int Triangle::getCornerB() const { return Data.CornerB; }
int Triangle::getCornerC() const { return Data.CornerC; }

void Triangle::printInfo() const {

	std::cout << getName() << ":\n" << (isValid() ? "Правильная фигура\n" : "Не правильная фигура\n")
		<< "Количество сторон: " << getSideCount()
		<< "\nСтороны:" << " a=" << getSideA()
		<< " b=" << getSideB() << " c=" << getSideC() << std::endl;
	std::cout << "Углы:" << " A=" << getCornerA()
		<< " B=" << getCornerB()
		<< " C=" << getCornerC() << std::endl;

}

// прямоугольный треугольник (угол C всегда равен 90);
bool Triangle::isRighttriangle() const { return (Data.CornerC == 90); }

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
bool Triangle::isIsoscelesTriangle() const { return ((Length.SideA == Length.SideC) && (Data.CornerA == Data.CornerC)); }

// равносторонний треугольник (все стороны равны, все углы равны 60);
bool Triangle::isEquilateralTriangle() const { return ((Length.SideA == Length.SideB && Length.SideB == Length.SideC) && (Data.CornerA == 60 && Data.CornerB == 60 && Data.CornerC == 60)); }

int Quadrilateral::getSideCount() const {

	int countQuadrilateral{ 4 };
	return countQuadrilateral;
}

int Triangle::getSideCount() const {

	int countTriangle{ 3 };
	return countTriangle;
}