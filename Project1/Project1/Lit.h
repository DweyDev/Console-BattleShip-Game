#pragma once
#include <iostream>

class Lit {
private:
	char first;
	char second;
public:
	void setFirst(char set) {
		this->first = set;

	}
	void setSecond(char set) {
		this->second = set;

	}
	char getFirst() {
		return this->first;
	}
	char getSecond() {
		return this->second;
	}


};