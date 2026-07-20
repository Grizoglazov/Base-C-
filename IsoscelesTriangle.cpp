#include"IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle(const std::string& name, int sideA, int sideB, int sideC, int cornerA, int cornerB, int cornerC) :
	Triangle(name, sideA, sideB, sideC, cornerA, cornerB, cornerC) {}

bool IsoscelesTriangle::isValid() const { return Triangle::isValid() && isIsoscelesTriangle(); }