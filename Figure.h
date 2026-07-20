#pragma once

class Figure {

public:

	virtual int getSideCount() const = 0;
	virtual void printInfo() const = 0;
	virtual bool isValid() const = 0;
	virtual ~Figure() = default;
};
