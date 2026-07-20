#include"Function.h"


// сумма
int addition(int x, int y) {			

	return x + y;
}

// вычитание
int subtraction(int x, int y) {			

	return x - y;
}

// умножение
int multiplication(int x, int y) {		

	return x * y;
}

// деление
double division(double x, double y) {

	if (y != 0) return x / y;
	else return 0;
}

// возведение в степень
int exponent(int x, int y) {

	if (x == 0) return 0;			
	int degree{ 1 };
	while (y > 0) {
	
		degree *= x;
		--y;
	}
	return degree;
}