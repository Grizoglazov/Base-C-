#pragma once
#include"Triangle.h"


class EquilateralTriangle : public Triangle {

public:
	EquilateralTriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC);

	bool isValid() const override;

};