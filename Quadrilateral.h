#pragma once
#include<string>
#include "Structure.h"
#include "Figure.h"

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
		int cornerA, int cornerB, int cornerC, int cornerD);

	void printInfo() const override;
	int getSideCount() const override;
	bool isValid() const override;

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