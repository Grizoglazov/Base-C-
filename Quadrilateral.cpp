#include"Quadrilateral.h"
#include<string>
#include<iostream>

Quadrilateral::Quadrilateral(const std::string& name, int sideA, int sideB, int sideC, int sideD,
	int cornerA, int cornerB, int cornerC, int cornerD) : mName{ name }, Length{
	sideA, sideB, sideC, sideD }, Data{ cornerA, cornerB, cornerC, cornerD } {}



bool Quadrilateral::isValid() const {

	int sumCorner = getCornerA() + getCornerB() + getCornerC() + getCornerD();
	return sumCorner == 360;
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
		<< " D=" << getCornerD() << std::endl << std::endl;

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

int Quadrilateral::getSideCount() const {

	int countQuadrilateral{ 4 };
	return countQuadrilateral;
}

