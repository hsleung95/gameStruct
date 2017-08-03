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
#include "enemyChar.hpp"
#include "mainChar.hpp"
#include "equipment.hpp"
#include <stdlib.h>
#include <list>
using namespace std;


/************************************ start of fight function *******************************************************/
/*
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
	bool exit = false;
	while(!exit){
		if(myChar.getCurrentHP()<=0) myChar.setCurrentHP(myChar.getMaxHP());	//refill charater health if defeated
		char userInput = 'x';

		enemyChar enemyChar;
		list<gameChar*> charList;		//list containing all characters
		gameChar *myCharPtr = &myChar;
		charList.push_back(myCharPtr);		//push player into list
	
		myChar.printStat();	//print current player status
	
		do{					//do while loop: keep generating monster until player agree to fight this one
			enemyChar = createEnemy(myChar.getLV());
			enemyChar.printStat();
			enemyChar.printEq();
			cout << "are you sure to fight this monster?(y/n), or exit(e)?" << endl;
			cin >> userInput;
		}
		while(userInput=='n'|| (userInput!='y' && userInput!='e'));	//user entered n or not entering y
	
		if(userInput == 'e') break;
	
		gameChar *enemyCharPtr = &enemyChar;
		charList.push_back(enemyCharPtr);		//push enemy into list
	
		for(list<gameChar*>::iterator it=charList.begin();it!=charList.end();it++){
			float defVal = myChar.getDefense();
			bool defensed = false;
			if((*it)->getCurrentHP()<=0) break;
			
			string charType = (*it)->getType();
	
			if(charType.compare("mainChar")==0){	//check current character type
		
				while(userInput!='a'&&userInput!='b'){	//turn of player
					cout << endl << "What do you want to do?" << endl;
					cout << "a. Attack" << endl;
					cout << "b. Defense" << endl;
					cin >> userInput;
				}
				if(userInput=='a'){		//attack, deal basic damage to enemy, print, then check if enemy health is <=0
					float damage = (*it)->attackChar(enemyChar);
					enemyChar.setCurrentHP((enemyChar.getCurrentHP()-damage));
					cout << "You have done " << damage << " damage to " << enemyChar.getName() << endl;
					myChar.printStat();
					enemyChar.printStat();
					if(enemyChar.getCurrentHP()<=0) break;	//enemy defeated by player, break the loop
				}
			
				else if(userInput=='b'){		//defense, get current defense, double it, raise the flag
					defVal = myChar.getDefense();
					myChar.setDefense(defVal*2);
					defensed = true;
				}
			
				//myCharPtr = &myChar;
				charList.push_back((*it));			//finished current move, push character to end of list
			}
			
			else if(charType.compare("enemyChar")==0){		//enemy's round, do basic attack to player, print data, push character to end of list
				float enemyDamage = enemyChar.attackChar(myChar);
				myChar.setCurrentHP((myChar.getCurrentHP()-enemyDamage));
				cout << enemyChar.getName() << " have  done " << enemyDamage << " damage to you" << endl;
				myChar.printStat();
				enemyChar.printStat();
				charList.push_back((*it));
			}
		
			if(myChar.getCurrentHP()<=0) break;		//enemy defeated character, break the loop
		
			if(defensed){
				myChar.setDefense(defVal);			//defend for one round
			}
			userInput = 'x';				//reset input for the loop condition
			
		}
	
		if(enemyChar.getCurrentHP() <= 0){		//enemy is defeated, get exp and equipment from enemy
			cout << "You defeated " << enemyChar.getName();
			cout << ", getting " << enemyChar.getExpContain() << "exp.";
			if(!enemyChar.getEquipment().isNull()){
				equipment treasure = enemyChar.getEquipment();
				bool isGetItem = myChar.addEquipment(treasure);
				if(isGetItem){
					cout << "you get equipment from " << enemyChar.getName() << endl;
					treasure.printEq();
				}
			}
			bool isLvUp = myChar.addExp(enemyChar.getExpContain());
			if(isLvUp){
				cout << "You gained 1 lv!" << endl;
			}
		}

		else if(myChar.getCurrentHP()<=0){
			cout << "You defeated by " << enemyChar.getName() << endl;
		}

		cout << endl;
	
		while(userInput != 'y' && userInput != 'n'){
			cout << "continue or back to menu?" << endl;
			cout << "y. Continue" << endl;
			cout << "n. Back to menu" << endl;
			cin >> userInput;
		}
		if(userInput == 'n') break;
	}
}
*/
/************************************ end of fight function *******************************************************/
/************************************ start of equipment function *************************************************/
/*
void equipmentFunction(mainChar myChar){

	//char userInput = 'x';		//get userInput
	string userInput = "";
	int userInputNum = -1;	//input integer for equipment id
	
	while(userInput.compare("exit")!=0){	//main loop
		myChar.printStat();
		cout << endl;
		equipment* ownedArr = myChar.getOwnedArr();		//get owned and wearing list from character
		equipment* wearing = myChar.getWearingArr();
		cout << "wearing: " << endl;
		for(int i=0;i<myChar.wearingNum;i++){			// print equipments from wearing and then owned list
			cout << i << ": ";
			cout << "type:" << equipment::eqTypeStr[i];
			if(!wearing[i].isNull()){
				cout << ", name:" << wearing[i].getEqName();
				cout << ", +" << wearing[i].getEqVal() << equipment::attrStr[wearing[i].getAttribute()];
			}
			cout << endl;
		}
		cout << "owned: " << endl;
		for(int i=0;i<myChar.ownedNum;i++){
			cout << i+myChar.wearingNum << ": ";
			if(!ownedArr[i].isNull()){
				cout << "type:" << equipment::eqTypeStr[i];
				cout << ", name:" << ownedArr[i].getEqName();
				cout << ", +" << ownedArr[i].getEqVal() << equipment::attrStr[ownedArr[i].getAttribute()];
			}
			cout << endl;
		}
		
		do{			//do while loop of checking userInput, break the loop if user inputed 'exit' or number between 0 and wearingNum+ownedNum
			cout << "Enter the equipment number for detail or enter 'exit' and back to menu: ";
			cin >> userInput;
			if(userInput.compare("exit")!=0)
				userInputNum = stoi(userInput);
		}
		while(userInput.compare("exit")!=0 && (userInputNum < 0 || userInputNum > (myChar.wearingNum+myChar.ownedNum)) );
		
		if(userInput.compare("exit")==0){		//user entered "exit"
			break;
		}
		
		else{		//user entered number between 0 and wearingNum+ownedNum
			if(userInputNum < myChar.wearingNum && !wearing[userInputNum].isNull()){	//wearing equipment id
				wearing[userInputNum].printEq();
				char eqInput = 'x';
				do{
					cout << "what do you want to do? " << endl;
					cout << "a. unequip equipment" << endl;
					cout << "b. drop equipment" << endl;
					cout << "c. browse other equipment" << endl;
					cin >> eqInput;
				}
				while(eqInput!='a' && eqInput!='b' && eqInput !='c');
				if(eqInput == 'a'){
					wearing[userInputNum].unEquipChar(myChar);
					myChar.addEquipment(wearing[userInputNum]);
					wearing[userInputNum] = equipment();
				}
				else if(eqInput == 'b'){
					wearing[userInputNum].unEquipChar(myChar);
					wearing[userInputNum] = equipment();
				}
				else if(eqInput == 'c'){
					   
				}
			}
		
			else if(userInputNum < (myChar.wearingNum+myChar.ownedNum) && !ownedArr[userInputNum - myChar.wearingNum].isNull()){	//owned equipment id
				int index = userInputNum - myChar.wearingNum;
				ownedArr[index].printEq();
				char eqInput = 'x';
				do{
					cout << "what do you want to do? " << endl;
					cout << "a. equip equipment" << endl;
					cout << "b. drop equipment" << endl;
					cout << "c. browse other equipment" << endl;
					cin >> eqInput;
				}
				while(eqInput!='a' && eqInput!='b' && eqInput !='c');
				if(eqInput == 'a'){
					myChar.changeEquipment(ownedArr[index]);
					ownedArr[index] = equipment();
				}
				else if(eqInput == 'b'){
					wearing[userInputNum].unEquipChar(myChar);
					wearing[userInputNum] = equipment();
				}
				else if(eqInput == 'c'){
					
				}
			}
			else{	//no equipment in the slot
				cout << "no equipment in this slot" << endl;
			}
		}
	}
}
*/
/************************************ end of equipment function ***************************************************/

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
	
		//while(option.compare("y")==0){  //ask for input after killed or defeated by monster, first time must be yes
		if(option == 'a'){
			//fightFunction(myChar);
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

