#pragma once
#include <iostream>
#include <string>
#include "cargo.h"

class Rice : public Cargo {
public:
	Rice(std::string n, int p)
		: Cargo(n, p) {
		std::cout << this->name << "creat successful" << std::endl;
	}
	~Rice() {
		
	}
};