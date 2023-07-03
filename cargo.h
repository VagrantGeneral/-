#pragma once
#include <iostream>
#include <string>
#include "pronunciation.h"
class Cargo {
public:
	int position;
	std::string name;
	Cargo(std::string n = "����",int p = 1) 
		: position(p), name(n) {

	}
	virtual ~Cargo() {

	}

	void show_Position() {
		if (position == 0) {
			std::cout << this->name << "���˴�" << std::endl;
			speak(this->name + "���˴�");
		}
		else if (position == 1) {
			std::cout << this->name << "������" << std::endl;
			speak(this->name + "������");
		}
		else if (position == 2) {
			std::cout << this->name << "�����Ұ�" << std::endl;
			speak(this->name + "�����Ұ�");
		}
	}
};