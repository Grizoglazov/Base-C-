#pragma once
#include"Triangle.h"

class IsoscelesTriangle : public Triangle {

public:

	IsoscelesTriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC);

	bool isValid() const override;

};