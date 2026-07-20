#include"Parallelogram.h"

Parallelogram::Parallelogram(const std::string& name, int sideA, int sideB, int sideC, int sideD, int cornerA, int cornerB, int cornerC, int cornerD)
	:Quadrilateral(name, sideA, sideB, sideC, sideD, cornerA, cornerB, cornerC, cornerD) {}

bool Parallelogram::isValid() const { return Quadrilateral::isValid() && isParallelogram(); }