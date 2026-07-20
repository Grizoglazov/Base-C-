#include"Square.h"

Square::Square(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD)
	:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {}

bool Square::isValid() const { return Quadrilateral::isValid() && isSquare(); }