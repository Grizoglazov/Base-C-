#pragma once
#include"Triangle.h"

class Righttriangle : public Triangle {

public:

	Righttriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC);

	bool isValid() const override;
};