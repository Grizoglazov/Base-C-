#include<iostream>
#include"Counter.h"


Counter::Counter() :count(1) {}
Counter::Counter(int x) :count(x) {}

void Counter::showCount() const { std::cout << getCount() << std::endl; }

void Counter::add() { ++count; }

void Counter::subtract() { --count; }

int Counter::getCount() const { return count; }