#pragma once
#include <iostream>
#include <string>
#include "cargo.h"

class Chicken : public Cargo {
public:
	Chicken(std::string n, int p)
		: Cargo(n, p) {
		std::cout << this->name << "creat successful" << std::endl;
	}
	~Chicken() {
		
	}

	void eat_Rice(Cargo * c) {
		std::cout << this->name << "Ётак" << c->name << std::endl;
		speak(this->name + "Ётак" + c->name);
	}
};