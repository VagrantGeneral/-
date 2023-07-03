#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "cargo.h"

class Pot {
public:
	int position;
	std::vector<Cargo*> pot;

	Pot(int p = 0)
		: position(p) {

	}
	~Pot() {}

	void add_Cargo(Cargo* c) {
		this->pot.push_back(c);
		this->set_Cargo_Position();
		c->show_Position();
	}

	void del_Cargo(Cargo* c) {
		for (auto it = this->pot.begin(); it != this->pot.end(); it++) {
			if ((*it)->name == c->name) {
				this->pot.erase(it);
				if (this->position == 0) {
					std::cout << c->name << "下了船" << std::endl;
					speak(c->name + "下了船");
				}
				else if (position == 1) {
					std::cout << c->name << "离开左岸" << std::endl;
					speak(c->name + "离开左岸");
				}
				else if (position == 2) {
					std::cout << c->name << "离开右岸" << std::endl;
					speak(c->name + "离开右岸");
				}
				break;
			}
		}
	}

	void set_Cargo_Position() {
		for (auto it = this->pot.begin(); it != this->pot.end(); it++) {
			(*it)->position = this->position;
		}
	}

	bool scarch_Cargo(Cargo* c) {
		for (auto it = this->pot.begin(); it != this->pot.end(); it++) {
			if ((*it)->name == c->name) {
				return true;
			}
		}
		return false;
	}

	bool scarch_Cargos(Cargo* c1, Cargo* c2) {
		if (this->scarch_Cargo(c1) && this->scarch_Cargo(c2)) {
			return true;
		}
		else {
			return false;
		}
	}

	void clean_pot() {
		this->pot.clear();
	}
};