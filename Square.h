#pragma once
#include"Quadrilateral.h"

// Квадрат (производный класс от класса Четырехугольник)
class Square : public Quadrilateral {


public:

	Square(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD);

	bool isValid() const override;
};