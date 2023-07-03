#include <iostream>
#include <string>
#include "farmer.h"
#include "fox.h"
#include "chicken.h"
#include "rice.h"
#include "pot.h"


int main() {
	std::cout << "****************************************����*****************************************" << std::endl;
	std::cout << "Hello,Welcome to the simulation program for farmers crossing the river." << std::endl;
	std::cout << "1.����ũ�����ѡ��һ�γ�ũ����ֻ��һ����Ʒ" << std::endl;
	std::cout << "2.Ŀ���ǽ�������Ʒ�˵��Ұ�" << std::endl;
	std::cout << "3.û��ũ����ʱ������Լ���������" << std::endl;
	std::cout << "*************************************************************************************" << std::endl;
	Pot* left_Bank = new Pot(1);
	Pot* right_Bank = new Pot(2);
	Pot* ship = new Pot(0);

	Farmer* farmer = new Farmer("ũ��", 1);
	Fox* fox = new Fox("����", 1);
	Chicken* chicken = new Chicken("��", 1);
	Rice* rice = new Rice("��", 1);

	std::cout << "************************************ũ���������*************************************" << std::endl << std::endl;
	speak("ũ��������ڿ�ʼ");
	while (farmer->position != 2 || fox->position != 2 || chicken->position != 2 || rice->position != 2) {

		std::cout << "***************************************׼��***********************************" << std::endl;
		
		left_Bank->add_Cargo(farmer);
	    left_Bank->add_Cargo(fox);
	    left_Bank->add_Cargo(chicken);
	    left_Bank->add_Cargo(rice);

		std::cout << "***************************************��ʼ***********************************" << std::endl;

		left_Bank->del_Cargo(farmer);
		ship->add_Cargo(farmer);
		int choice = 1;
		bool flag1 = 1;
		while (flag1) {
			std::cout << "ũ�����󰶴���һ�����1.���ꡣ2.����3.�ף�******��ѡ��" << std::endl;
			std::cin >> choice;
			if (choice == 1 || choice == 2 || choice == 3) {
				flag1 = 0;
			}
			else {
				std::cout << "���루ѡ������������ѡ��" << std::endl;
			}
		}
		if (choice == 1) {
			farmer->unload_C(fox, left_Bank);
			farmer->load_C(fox, ship);
			if (left_Bank->scarch_Cargos(chicken, rice)) {
				chicken->eat_Rice(rice);
				std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;
				speak("���¿�ʼ");
				left_Bank->clean_pot();
				right_Bank->clean_pot();
				ship->clean_pot();
				continue;
			}
		}
		else if (choice == 2) {
			farmer->unload_C(chicken, left_Bank);
			farmer->load_C(chicken, ship);
			if (left_Bank->scarch_Cargos(fox, chicken)) {
				fox->eat_Chicken(chicken);
				std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;
				speak("���¿�ʼ");
				left_Bank->clean_pot();
				right_Bank->clean_pot();
				ship->clean_pot();
				continue;
			}
			else {
				std::cout << "ship�����Ұ�" << std::endl;
				speak("�������Ұ�");
				farmer->unload_C(chicken, ship);
				farmer->load_C(chicken, right_Bank);
				if (right_Bank->scarch_Cargos(fox, chicken)) {
					fox->eat_Chicken(chicken);					
					std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;	
					speak("���¿�ʼ");
					left_Bank->clean_pot();					
					right_Bank->clean_pot();					
					ship->clean_pot();
					continue;
				}
				else if (right_Bank->scarch_Cargos(chicken, rice)) {
					chicken->eat_Rice(rice);
					std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;	
					speak("���¿�ʼ");
					left_Bank->clean_pot();					
					right_Bank->clean_pot();					
					ship->clean_pot();
					continue;
				}
				else {
					std::cout << "ship������" << std::endl;
					speak("��������");
					int choice2 = 1;
					bool flag2 = 1;
					while (flag2) {
						std::cout << "ũ�����󰶴���һ�����1.���ꡣ3.�ף�******��ѡ��" << std::endl;
						std::cin >> choice2;
						if (choice2 == 1 || choice2 == 3) {
							flag2 = 0;
						}
						else {
							std::cout << "���루ѡ������������ѡ��" << std::endl;
						}
					}
					if (choice2 == 1) {
						farmer->unload_C(fox, left_Bank);
						farmer->load_C(fox, ship);
						std::cout << "ship�����Ұ�" << std::endl;
						speak("�������Ұ�");
						farmer->unload_C(fox, ship);
						farmer->load_C(fox, right_Bank);
						if (right_Bank->scarch_Cargos(fox, chicken)) {
							std::cout << chicken->name<<"�ᱻ"<<fox->name<<"��" << std::endl;
							std::cout << "�Ƿ����Ұ�����һ����Ʒ��y/n��" << std::endl;
							std::string cho;
							bool flag3 = 1;
							while (flag3) {
								std::cin >> cho;
								if (cho == "Y" || cho == "y" || cho == "N" || cho == "n") {
									flag3 = 0;
								}
								else {
									std::cout << "���루ѡ������������ѡ��" << std::endl;
								}
							}
							if (cho == "Y" || cho == "y") {
								std::cout << "ũ�����Ұ�����һ�����1.���ꡣ2.������******��ѡ��" << std::endl;
								int cho2;
								bool flag4 = 1;
								while (flag4) {
									std::cin >> cho2;
									if (cho2 == 1 || cho2 == 2) {
										flag4 = 0;
									}
									else {
										std::cout << "���루ѡ������������ѡ��" << std::endl;
									}
								}
								//�Ұ�����
								if (cho2 == 1) {
									farmer->unload_C(fox, right_Bank);
									farmer->load_C(fox, ship);
									std::cout << "ship������" << std::endl;
									speak("��������");
									farmer->unload_C(fox, ship);
									farmer->unload_C(fox, left_Bank);
									if (left_Bank->scarch_Cargos(fox, chicken) || left_Bank->scarch_Cargos(chicken, rice)) {
										//
									}
									else {
										//******
									}
								}
								else if (cho2 == 2) {
									farmer->unload_C(chicken, right_Bank);
									farmer->load_C(chicken, ship);
									std::cout << "ship������" << std::endl;
									speak("��������");
									farmer->unload_C(chicken, ship);
									farmer->load_C(chicken, left_Bank);
									if (left_Bank->scarch_Cargos(chicken, rice)) {
										std::cout << rice->name << "�ᱻ" << chicken->name << "�Ե�" << std::endl;
										std::cout << "�Ƿ����󰶴���һ����Ʒ��y/n��" << std::endl;
										std::string cho3;
										bool flag5 = 1;
										while (flag5) {
											std::cin >> cho3;
											if (cho3 == "Y" || cho3 == "y" || cho3 == "N" || cho3 == "n") {
												flag5 = 0;
											}
											else {
												std::cout << "���루ѡ������������ѡ��" << std::endl;
											}
										}
										if (cho == "Y" || cho == "y") {
											std::cout << "ũ�����󰶴���һ�����2.����3.�ף�******��ѡ��" << std::endl;
											int cho4;
											bool flag6 = 1;
											while (flag6) {
												std::cin >> cho4;
												if (cho4 == 2 || cho4 == 3) {
													flag6 = 0;
												}
												else {
													std::cout << "���루ѡ������������ѡ��" << std::endl;
												}
											}
											if (cho4 == 2) {
												std::cout << "��ȥ�Ұ��ᱻ" << fox->name << "�Ե�" << std::endl;
												std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;
												speak("���¿�ʼ");
												left_Bank->clean_pot();
												right_Bank->clean_pot();
												ship->clean_pot();
												continue;
											}
											else if (cho4 == 3) {
												farmer->unload_C(rice, left_Bank);
												farmer->load_C(rice, ship);
												std::cout << "ship�����Ұ�" << std::endl;
												speak("�������Ұ�");
												farmer->unload_C(rice, ship);
												farmer->load_C(rice, right_Bank);
												std::cout << "ship������" << std::endl;
												speak("��������");
												farmer->unload_C(chicken, left_Bank);
												farmer->load_C(chicken, ship);
												std::cout << "ship�����Ұ�"<< std::endl;
												speak("�������Ұ�");
												farmer->unload_C(chicken, ship);
												farmer->load_C(chicken, right_Bank);
												farmer->unload_C(farmer, ship);
												farmer->load_C(farmer, right_Bank);
											}
										}
										else if (cho == "n" || cho == "N") {
											chicken->eat_Rice(rice);
											std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;
											speak("���¿�ʼ");
											left_Bank->clean_pot();
											right_Bank->clean_pot();
											ship->clean_pot();
											continue;
										}
									}
									else {
										//
									}
								}
							}
							else if (cho == "N" || cho == "n") {//�Ұ�������
								fox->eat_Chicken(chicken);
								std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;
								speak("���¿�ʼ");
								left_Bank->clean_pot();
								right_Bank->clean_pot();
								ship->clean_pot();
								continue;
							}
						}
					}
					else if (choice2 == 3) {//�󰶵ڶ���***ѡ��
						std::cout << "ѡ����ѡ���꣬�߼���ͬ��Ϊ�����ߴ����࣬�˹���******��" << std::endl;
						left_Bank->clean_pot();
						right_Bank->clean_pot();
						ship->clean_pot();
						continue;
					}
				}
			}
		}
		else if (choice == 3) {//���󰶵�һ��***ѡ��
			farmer->unload_C(rice, left_Bank);
			farmer->load_C(rice, ship);
			fox->eat_Chicken(chicken);
			std::cout << "Ŀ���޷���ɣ�����ʧ��" << std::endl;
			speak("���¿�ʼ");
			left_Bank->clean_pot();
			right_Bank->clean_pot();
			ship->clean_pot();
			continue;
		}	
	}
	std::cout << "�������" << std::endl;
	speak("��ϲ�㣬�����ũ�����");
	delete left_Bank, right_Bank, ship;
	delete farmer, fox, chicken, rice;
}