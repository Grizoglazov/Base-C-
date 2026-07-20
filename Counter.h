#ifndef COUNTER_H
#define COUNTER_H

class Counter {

	int count{};

public:

	void add();
	void subtract();
	void showCount() const;
	int getCount() const;
	Counter();
	Counter(int x);
};

#endif