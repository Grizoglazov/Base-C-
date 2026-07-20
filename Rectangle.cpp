#include"Rectangle.h"
#include<string>

Rectangle::Rectangle(const std::string& name, int sideA, int sideB, int sideC, int sideD, 
	int cornerA, int cornerB, int cornerC, int cornerD)
	:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {}

bool Rectangle::isValid() const { return Quadrilateral::isValid() && isRectangle();}