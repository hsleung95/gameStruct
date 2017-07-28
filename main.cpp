//
//  main.cpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include <iostream>
#include <string>
#include "enemyChar.hpp"
#include "mainChar.hpp"
#include "equipment.hpp"
#include <stdlib.h>
#include <list>
using namespace std;

enemyChar createEnemy(int lv){
	enemyChar enemyChar;
	string enemyName = "enemy";
	enemyName = enemyName + to_string(gameChar::getRandCount());
	enemyChar.setName(enemyName);
	enemyChar.randChar(lv);
	enemyChar.setExpContain();
	return enemyChar;
}

void fightFunction(mainChar &myChar){	//function handling fight, pass player character in main n generate monsters here
	
	if(myChar.getCurrentHP()<=0) myChar.setCurrentHP(myChar.getMaxHP());	//refill charater health if defeated
	string userInput = "";

	enemyChar enemyChar;
	list<gameChar*> charList;		//list containing all characters
	gameChar *myCharPtr = &myChar;
	charList.push_back(myCharPtr);		//push player into list
	
	myChar.printStat();	//print current player status
	
	do{					//do while loop: keep generating monster until player agree to fight this one
		enemyChar = createEnemy(myChar.getLV());
		enemyChar.printStat();
		cout << "are you sure to fight this monster?(y/n)" << endl;
		cin >> userInput;
	}
	while(userInput.compare("n")==0||userInput.compare("y")!=0);	//user entered n or not entering y
	
	gameChar *enemyCharPtr = &enemyChar;
	charList.push_back(enemyCharPtr);		//push enemy into list
	
	for(list<gameChar*>::iterator it=charList.begin();it!=charList.end();it++){
		float defVal = myChar.getDefense();
		bool defensed = false;
		if((*it)->getCurrentHP()<=0) break;
	
		string charType = (*it)->getType();
	
		if(charType.compare("mainChar")==0){
		
			while(userInput.compare("a")!=0&&userInput.compare("b")!=0){
				cout << endl << "What do you want to do?" << endl;
				cout << "a. Attack" << endl;
				cout << "b. Defense" << endl;
				cin >> userInput;
			}
			if(userInput.compare("a")==0){
				float damage = (*it)->attackChar(enemyChar);
				enemyChar.setCurrentHP((enemyChar.getCurrentHP()-damage));
				cout << "You have done " << damage << " damage to " << enemyChar.getName() << endl;
				myChar.printStat();
				enemyChar.printStat();
				if(enemyChar.getCurrentHP()<=0) break;	//enemy defeated by player, break the loop
			}
			
			else if(userInput.compare("b")==0){
				defVal = myChar.getDefense();
				myChar.setDefense(defVal*2);
				defensed = true;
			}
			
			//myCharPtr = &myChar;
			charList.push_back((*it));
		}
			
		else if(charType.compare("enemyChar")==0){
			float enemyDamage = enemyChar.attackChar(myChar);
			myChar.setCurrentHP((myChar.getCurrentHP()-enemyDamage));
			cout << enemyChar.getName() << " have  done " << enemyDamage << " damage to you" << endl;
			myChar.printStat();
			enemyChar.printStat();
			//enemyCharPtr = &enemyChar;
			charList.push_back((*it));
		}
		
		if(myChar.getCurrentHP()<=0) break;	//enemy defeated character, break the loop
		
		if(defensed){
			myChar.setDefense(defVal);		//defend for one round
		}
		userInput = "";		//reset input for the loop condition
			
	}
	
	if(enemyChar.getCurrentHP() <= 0){
		cout << "You defeated " << enemyChar.getName();
		cout << ", getting " << enemyChar.getExpContain() << "exp.";
		bool isLvUp = myChar.addExp(enemyChar.getExpContain());
		if(isLvUp){
			cout << "You gained 1 lv!" << endl;
		}
	}
	else if(myChar.getCurrentHP()<=0){
		cout << "You defeated by " << enemyChar.getName() << endl;
	}
	cout << endl;
}

int main() {
    string charName;
    string userInput;
	bool exit = false;
	
    string option = "y";
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
	
		//while(option.compare("y")==0){  //ask for input after killed or defeated by monster, first time must be yes
		if(option.compare("a")==0){

			fightFunction(myChar);
			option = "";		//reset input for the loop condition
			
			while(option.compare("y")!=0&&option.compare("n")!=0){
				cout << "continue or back to menu?" << endl;
				cout << "y. Continue" << endl;
				cout << "n. Back to menu" << endl;
				cin >> option;
				if(option.compare("n")==0) break;
			}
		}
		else if(option.compare("b")==0){
		
		}
		
		else if(option.compare("c")==0) {
			exit = true;
		}
	}
    
    return 0;
}

