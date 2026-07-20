#include<iostream>
#include"Triangle.h"


Triangle::Triangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
	mName{ name }, Length{ sideA, sideB, sideC }, Data{ cornerA, cornerB, cornerC } {}

bool Triangle::isValid() const {
	int sumCorner = getCornerA() + getCornerB() + getCornerC();
	return sumCorner == 180;
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
		<< " C=" << getCornerC() << std::endl << std::endl;

}


// прямоугольный треугольник (угол C всегда равен 90);
bool Triangle::isRighttriangle() const { return (Data.CornerC == 90); }

// равнобедренный треугольник (стороны a и c равны, углы A и C равны);
bool Triangle::isIsoscelesTriangle() const { return ((Length.SideA == Length.SideC) && (Data.CornerA == Data.CornerC)); }

// равносторонний треугольник (все стороны равны, все углы равны 60);
bool Triangle::isEquilateralTriangle() const { return ((Length.SideA == Length.SideB && Length.SideB == Length.SideC) && (Data.CornerA == 60 && Data.CornerB == 60 && Data.CornerC == 60)); }

int Triangle::getSideCount() const {

	int countTriangle{ 3 };
	return countTriangle;
}