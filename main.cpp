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
using namespace std;


int main() {
    string charName;
    string userInput;
	bool exit = false;
	
    char option = 'x';
    cout << "welcome to the RPG world, please enter the name and the value of your character:\n";
    cout << "name: ";
    cin >> charName;
    mainChar myChar(charName, 100,50,10,10,10);

	while(!exit){
		cout << "What do you want to do?" << endl;
		cout << "a. Fight enemy" << endl;
		cout << "b. Check equipment" << endl;
		cout << "c. Exit" << endl;
		cin >> option;

		if(option == 'a'){
			fightScene::fightFunction(myChar);
		}
		else if(option == 'b'){
			equipmentScene::equipmentFunction(myChar);
		}
		
		else if(option == 'c') {
			exit = true;
		}
	}
    
    return 0;
}

