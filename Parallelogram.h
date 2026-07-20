#pragma once
#include"Quadrilateral.h"

// Параллелограмм (производный класс от класса Четырехугольник)
class Parallelogram : public Quadrilateral {


public:

	Parallelogram(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD);
	bool isValid() const override;
};