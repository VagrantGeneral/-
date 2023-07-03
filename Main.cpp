#include <iostream>
#include <string>
#include "farmer.h"
#include "fox.h"
#include "chicken.h"
#include "rice.h"
#include "pot.h"


int main() {
	std::cout << "****************************************规则*****************************************" << std::endl;
	std::cout << "Hello,Welcome to the simulation program for farmers crossing the river." << std::endl;
	std::cout << "1.扮演农民进行选择，一次除农民外只运一个物品" << std::endl;
	std::cout << "2.目的是将所有物品运到右岸" << std::endl;
	std::cout << "3.没有农民在时，狐狸吃鸡，鸡吃米" << std::endl;
	std::cout << "*************************************************************************************" << std::endl;
	Pot* left_Bank = new Pot(1);
	Pot* right_Bank = new Pot(2);
	Pot* ship = new Pot(0);

	Farmer* farmer = new Farmer("农民", 1);
	Fox* fox = new Fox("狐狸", 1);
	Chicken* chicken = new Chicken("鸡", 1);
	Rice* rice = new Rice("米", 1);

	std::cout << "************************************农夫过河问题*************************************" << std::endl << std::endl;
	speak("农夫过河现在开始");
	while (farmer->position != 2 || fox->position != 2 || chicken->position != 2 || rice->position != 2) {

		std::cout << "***************************************准备***********************************" << std::endl;
		
		left_Bank->add_Cargo(farmer);
	    left_Bank->add_Cargo(fox);
	    left_Bank->add_Cargo(chicken);
	    left_Bank->add_Cargo(rice);

		std::cout << "***************************************开始***********************************" << std::endl;

		left_Bank->del_Cargo(farmer);
		ship->add_Cargo(farmer);
		int choice = 1;
		bool flag1 = 1;
		while (flag1) {
			std::cout << "农民在左岸带走一个货物（1.狐狸。2.鸡。3.米）******请选择" << std::endl;
			std::cin >> choice;
			if (choice == 1 || choice == 2 || choice == 3) {
				flag1 = 0;
			}
			else {
				std::cout << "输入（选择）有误！请重新选择。" << std::endl;
			}
		}
		if (choice == 1) {
			farmer->unload_C(fox, left_Bank);
			farmer->load_C(fox, ship);
			if (left_Bank->scarch_Cargos(chicken, rice)) {
				chicken->eat_Rice(rice);
				std::cout << "目标无法完成，任务失败" << std::endl;
				speak("重新开始");
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
				std::cout << "目标无法完成，任务失败" << std::endl;
				speak("重新开始");
				left_Bank->clean_pot();
				right_Bank->clean_pot();
				ship->clean_pot();
				continue;
			}
			else {
				std::cout << "ship走向右岸" << std::endl;
				speak("船走向右岸");
				farmer->unload_C(chicken, ship);
				farmer->load_C(chicken, right_Bank);
				if (right_Bank->scarch_Cargos(fox, chicken)) {
					fox->eat_Chicken(chicken);					
					std::cout << "目标无法完成，任务失败" << std::endl;	
					speak("重新开始");
					left_Bank->clean_pot();					
					right_Bank->clean_pot();					
					ship->clean_pot();
					continue;
				}
				else if (right_Bank->scarch_Cargos(chicken, rice)) {
					chicken->eat_Rice(rice);
					std::cout << "目标无法完成，任务失败" << std::endl;	
					speak("重新开始");
					left_Bank->clean_pot();					
					right_Bank->clean_pot();					
					ship->clean_pot();
					continue;
				}
				else {
					std::cout << "ship走向左岸" << std::endl;
					speak("船走向左岸");
					int choice2 = 1;
					bool flag2 = 1;
					while (flag2) {
						std::cout << "农民在左岸带走一个货物（1.狐狸。3.米）******请选择" << std::endl;
						std::cin >> choice2;
						if (choice2 == 1 || choice2 == 3) {
							flag2 = 0;
						}
						else {
							std::cout << "输入（选择）有误！请重新选择。" << std::endl;
						}
					}
					if (choice2 == 1) {
						farmer->unload_C(fox, left_Bank);
						farmer->load_C(fox, ship);
						std::cout << "ship走向右岸" << std::endl;
						speak("船走向右岸");
						farmer->unload_C(fox, ship);
						farmer->load_C(fox, right_Bank);
						if (right_Bank->scarch_Cargos(fox, chicken)) {
							std::cout << chicken->name<<"会被"<<fox->name<<"吃" << std::endl;
							std::cout << "是否在右岸带走一个物品（y/n）" << std::endl;
							std::string cho;
							bool flag3 = 1;
							while (flag3) {
								std::cin >> cho;
								if (cho == "Y" || cho == "y" || cho == "N" || cho == "n") {
									flag3 = 0;
								}
								else {
									std::cout << "输入（选择）有误！请重新选择。" << std::endl;
								}
							}
							if (cho == "Y" || cho == "y") {
								std::cout << "农民在右岸带走一个货物（1.狐狸。2.鸡。）******请选择" << std::endl;
								int cho2;
								bool flag4 = 1;
								while (flag4) {
									std::cin >> cho2;
									if (cho2 == 1 || cho2 == 2) {
										flag4 = 0;
									}
									else {
										std::cout << "输入（选择）有误！请重新选择。" << std::endl;
									}
								}
								//右岸带走
								if (cho2 == 1) {
									farmer->unload_C(fox, right_Bank);
									farmer->load_C(fox, ship);
									std::cout << "ship走向左岸" << std::endl;
									speak("船走向左岸");
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
									std::cout << "ship走向左岸" << std::endl;
									speak("船走向左岸");
									farmer->unload_C(chicken, ship);
									farmer->load_C(chicken, left_Bank);
									if (left_Bank->scarch_Cargos(chicken, rice)) {
										std::cout << rice->name << "会被" << chicken->name << "吃掉" << std::endl;
										std::cout << "是否在左岸带走一个物品（y/n）" << std::endl;
										std::string cho3;
										bool flag5 = 1;
										while (flag5) {
											std::cin >> cho3;
											if (cho3 == "Y" || cho3 == "y" || cho3 == "N" || cho3 == "n") {
												flag5 = 0;
											}
											else {
												std::cout << "输入（选择）有误！请重新选择。" << std::endl;
											}
										}
										if (cho == "Y" || cho == "y") {
											std::cout << "农民在左岸带走一个货物（2.鸡。3.米）******请选择" << std::endl;
											int cho4;
											bool flag6 = 1;
											while (flag6) {
												std::cin >> cho4;
												if (cho4 == 2 || cho4 == 3) {
													flag6 = 0;
												}
												else {
													std::cout << "输入（选择）有误！请重新选择。" << std::endl;
												}
											}
											if (cho4 == 2) {
												std::cout << "鸡去右岸会被" << fox->name << "吃掉" << std::endl;
												std::cout << "目标无法完成，任务失败" << std::endl;
												speak("重新开始");
												left_Bank->clean_pot();
												right_Bank->clean_pot();
												ship->clean_pot();
												continue;
											}
											else if (cho4 == 3) {
												farmer->unload_C(rice, left_Bank);
												farmer->load_C(rice, ship);
												std::cout << "ship走向右岸" << std::endl;
												speak("船走向右岸");
												farmer->unload_C(rice, ship);
												farmer->load_C(rice, right_Bank);
												std::cout << "ship走向左岸" << std::endl;
												speak("船走向左岸");
												farmer->unload_C(chicken, left_Bank);
												farmer->load_C(chicken, ship);
												std::cout << "ship走向右岸"<< std::endl;
												speak("船走向右岸");
												farmer->unload_C(chicken, ship);
												farmer->load_C(chicken, right_Bank);
												farmer->unload_C(farmer, ship);
												farmer->load_C(farmer, right_Bank);
											}
										}
										else if (cho == "n" || cho == "N") {
											chicken->eat_Rice(rice);
											std::cout << "目标无法完成，任务失败" << std::endl;
											speak("重新开始");
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
							else if (cho == "N" || cho == "n") {//右岸不带走
								fox->eat_Chicken(chicken);
								std::cout << "目标无法完成，任务失败" << std::endl;
								speak("重新开始");
								left_Bank->clean_pot();
								right_Bank->clean_pot();
								ship->clean_pot();
								continue;
							}
						}
					}
					else if (choice2 == 3) {//左岸第二次***选米
						std::cout << "选米与选狐狸，逻辑相同，为避免冗代码余，此过程******略" << std::endl;
						left_Bank->clean_pot();
						right_Bank->clean_pot();
						ship->clean_pot();
						continue;
					}
				}
			}
		}
		else if (choice == 3) {//在左岸第一次***选米
			farmer->unload_C(rice, left_Bank);
			farmer->load_C(rice, ship);
			fox->eat_Chicken(chicken);
			std::cout << "目标无法完成，任务失败" << std::endl;
			speak("重新开始");
			left_Bank->clean_pot();
			right_Bank->clean_pot();
			ship->clean_pot();
			continue;
		}	
	}
	std::cout << "任务完成" << std::endl;
	speak("恭喜你，完成了农夫过河");
	delete left_Bank, right_Bank, ship;
	delete farmer, fox, chicken, rice;
}