#pragma once
#include"Quadrilateral.h"

// Ромб (производный класс от класса Четырехугольник)
class Rhomb : public Quadrilateral {

public:

	Rhomb(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD);

	bool isValid() const override;
};