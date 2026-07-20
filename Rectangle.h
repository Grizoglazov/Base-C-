#pragma once
#include"Quadrilateral.h"

// Прямоугольник (производный класс от класса Четырехугольник)
class Rectangle : public Quadrilateral {

public:

	Rectangle(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD);

	bool isValid() const override;

};