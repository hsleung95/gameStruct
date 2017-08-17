//
//  main.cpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include <iostream>
#include <string>
#include "fightScene.hpp"
#include "equipmentScene.hpp"
#include "mainChar.hpp"
#include "career.hpp"
using namespace std;


int main() {
	career* myChar;
    string charName;
    string userInput;
	char careerOption = 'x';
	bool exit = false;
	
    char option = 'x';
    cout << "welcome to the RPG world, please enter the name and the value of your character:\n";
    cout << "name: ";
    cin >> charName;
	cout << "choose a career:" << endl;
	cout << "1. adventurer, lower stat but can level up faster than others." << endl;
	cout << "2. magician, more mp and intelligence but lower hp, attack and defense." << endl;
	cout << "3. fighter, solve everything with brute force, may suffer from magic attack" << endl;
	while(careerOption != '1' && careerOption != '2' && careerOption !='3'){
		cout << "enter your option. " << endl;
		cin >> careerOption;
	}
	if(careerOption == '2') myChar = new magician(charName, 60,80,5,5,10);
	else if(careerOption == '3') myChar = new fighter(charName, 120,50,10,10,5);
	else myChar = new adventurer(charName, 80,50,8,8,6);
	
	myChar->printStat();
	myChar->printSkill();
	while(!exit){
		cout << "What do you want to do?" << endl;
		cout << "a. Fight enemy" << endl;
		cout << "b. Check equipment" << endl;
		cout << "c. Exit" << endl;
		cin >> option;

		if(option == 'a'){
			fightScene::fightFunction(*myChar);
		}
		else if(option == 'b'){
			equipmentScene::equipmentFunction(*myChar);
		}
		
		else if(option == 'c') {
			exit = true;
		}
	}
    
    return 0;
}

