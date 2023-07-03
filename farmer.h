#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cargo.h"
#include "pot.h"

class Farmer : public Cargo {
public:
	Farmer(std::string n,int p)
		: Cargo(n,p) {
		std::cout << this->name << "creat successful" << std::endl;
	}
	~Farmer() {
		
	}

	void load_C(Cargo * c, Pot * p) {
		p->add_Cargo(c);
	}
	void unload_C(Cargo * c, Pot * p) {
		p->del_Cargo(c);
	}
};