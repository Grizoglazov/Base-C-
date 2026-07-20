#include"EquilateralTriangle.h"

EquilateralTriangle::EquilateralTriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
	Triangle(name, sideA, sideB, sideC, cornerA, cornerB, cornerC) {}

bool EquilateralTriangle::isValid() const {	return Triangle::isValid() && isEquilateralTriangle(); }