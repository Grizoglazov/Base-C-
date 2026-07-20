#include<iostream>
#include<string>
#include"Figure.h"
#include"Structure.h"
#include"Quadrilateral.h"
#include"Rectangle.h"
#include"Rhomb.h"
#include"Square.h"
#include"Parallelogram.h"
#include"Triangle.h"
#include"Righttriangle.h"
#include"IsoscelesTriangle.h"
#include"EquilateralTriangle.h"
#include"Function.h"

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







