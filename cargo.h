#pragma once
#include <iostream>
#include <string>
#include "pronunciation.h"
class Cargo {
public:
	int position;
	std::string name;
	Cargo(std::string n = "货物",int p = 1) 
		: position(p), name(n) {

	}
	virtual ~Cargo() {

	}

	void show_Position() {
		if (position == 0) {
			std::cout << this->name << "上了船" << std::endl;
			speak(this->name + "上了船");
		}
		else if (position == 1) {
			std::cout << this->name << "上了左岸" << std::endl;
			speak(this->name + "上了左岸");
		}
		else if (position == 2) {
			std::cout << this->name << "上了右岸" << std::endl;
			speak(this->name + "上了右岸");
		}
	}
};