#pragma once
#include<string>
#include"Figure.h"
#include"Structure.h"


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
	Triangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC);

	bool isRighttriangle() const;
	bool isIsoscelesTriangle() const;
	bool isEquilateralTriangle() const;

	bool isValid() const override;

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