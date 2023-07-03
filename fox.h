#pragma once
#include <iostream>
#include <string>
#include "cargo.h"

class Fox : public Cargo {
public:
	Fox(std::string n, int p)
		: Cargo(n, p) {
		std::cout << this->name << "creat successful" << std::endl;
	}
	~Fox() {
		
	}

	void eat_Chicken(Cargo * c) {
		std::cout << this->name << "Ётак" << c->name << std::endl;
		speak(this->name + "Ётак" + c->name);
	}
};