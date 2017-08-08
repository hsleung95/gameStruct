//
//  fightScene.cpp
//  gameStruct
//
//  Created by Wilson Leung on 3/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "fightScene.hpp"

enemyChar fightScene::createEnemy(int lv){
	enemyChar enemyChar;
	string enemyName = "enemy";
	enemyName = enemyName + to_string(gameChar::getRandCount());
	enemyChar.randChar(enemyName, lv);
	return enemyChar;
}

bool fightScene::attackChar(gameChar &source, gameChar &target){
	float damage = source.attackChar(target);
	target.setCurrentHP((target.getCurrentHP()-damage));
	cout << source.getName() << " have done " << damage << " damage to " << target.getName() << endl;
	source.printStat();
	target.printStat();
	return true;
}

gameChar& fightScene::selectTarget(list<gameChar*> charList){		//loop through charList and ask user for target
	gameChar* target = new gameChar();
	int charCount = 0;
	char targetCount = 'x';
	cout << "choose a target: " << endl;
	for(list<gameChar*>::iterator charIt=charList.begin();charIt!=charList.end();charIt++,charCount++){
		cout << charCount << "." << (*charIt)->getName() << endl;	//loop through character list
	}
	while((targetCount-'0') < 0 || (targetCount-'0') > charCount){
		cout << "please enter the id of character" << endl;
		cin >> targetCount;	//ask for target
	}
	int userTarget = targetCount-'0';
	int charNum = 0;
	for(list<gameChar*>::iterator charIt=charList.begin();charIt!=charList.end();charIt++,charNum++){
		if(charNum == userTarget){
			target = (*charIt);
		}
	}
	return *target;
}


void fightScene::fightFunction(mainChar &myChar){	//function handling fight, pass player character in main n generate monsters here

	bool exit = false;

	while(!exit){
		if(myChar.getCurrentHP()<=0) myChar.setCurrentHP(myChar.getMaxHP());	//refill charater health if defeated
		char userInput = 'x';
		
		enemyChar enemyChar;
		list<gameChar*> charList;		//list containing all characters
		gameChar *myCharPtr = &myChar;
		charList.push_back(myCharPtr);		//push player into list
		list<skill*> skillList = myChar.getSkillList();
		int roundCount = 0;
		int defensedRound = -1;
		float lastDef = 0;
		float defVal = 0;
		
		myChar.printStat();	//print current player status
		
		do{					//do while loop: keep generating monster until player agree to fight this one
			enemyChar = fightScene::createEnemy(myChar.getLV());
			enemyChar.printStat();
			enemyChar.printEq();
			cout << "are you sure to fight this monster?(y/n), or exit(e)?" << endl;
			cin >> userInput;
		}
		while(userInput=='n'|| (userInput!='y' && userInput!='e'));	//user entered n or not entering y
		
		if(userInput == 'e') break;
		
		gameChar *enemyCharPtr = &enemyChar;
		charList.push_back(enemyCharPtr);		//push enemy into list
		bool defensed = false;
		for(list<gameChar*>::iterator it=charList.begin();it!=charList.end();it++,roundCount++){
			cout << "round:" << roundCount << endl;
			cout << "defensedRound:" << defensedRound << endl;
			lastDef = defVal;
			defVal = myChar.getDefense();
			if(defensed&&(defensedRound-roundCount==2)){
				myChar.setDefense(lastDef);			//defend for one round
			}
			bool isMoved = false;
			if((*it)->getCurrentHP()<=0) break;
			
			string charType = (*it)->getType();
			
			if(charType.compare("mainChar")==0){	//check current character type
				while(isMoved!=true){	//turn of player, set moved flag as false allowing player change option
					if(userInput!='a'&&userInput!='b'&&userInput!='c'){
						cout << endl << "What do you want to do?" << endl;
						cout << "a. Attack" << endl;
						cout << "b. Defense" << endl;
						cout << "c. Cast Magic" << endl;
						cin >> userInput;
					}
					if(userInput=='a'){		//attack, deal basic damage to enemy, print, then check if enemy health is <=0
						fightScene::attackChar(myChar, enemyChar);
						isMoved = true;
						if(enemyChar.getCurrentHP()<=0) break;	//enemy defeated by player, break the loop
					}
					else if(userInput=='b'){		//defense, get current defense, double it, raise the flag
						defVal = myChar.getDefense();
						myChar.setDefense(defVal*2);
						defensedRound = roundCount;
						defensed = true;
						isMoved = true;
					}
				
					else if(userInput=='c'){		//magic menu, list all skill and ask for user input
						myChar.printSkill();
						char userCast = '0';		//user input, default '0'
						do{
							cout << "Enter the key to cast the magic or 'x' to choose other action: " << endl;
							cin >> userCast;
						}
						while(myChar.checkMagicKey(userCast) == false && userCast != 'x');	//if no match magic key and not back to action menu
						
						if(userCast == 'x'){		//user entered 'x', clear userInput and back to action menu
							isMoved = false;
							userInput = '0';
							continue;
						}
						else{						//user entered a magic key, loop through the list and cast the magic
							float amount = 0;
							for(list<skill*>::iterator it=skillList.begin();it!=skillList.end();it++){
								if(userCast == (*it)->getKey()){		//match the key, get the target
									gameChar& target = fightScene::selectTarget(charList);
									amount = (*it)->cast(myChar, target);
									cout << "You casted " << (*it)->skillName() << " on " << target.getName() << ", dealing " << amount << " points." << endl;
									/*
									int charCount = 0;
									char targetCount = 'x';
									cout << "choose a target: " << endl;
									for(list<gameChar*>::iterator charIt=charList.begin();charIt!=charList.end();charIt++,charCount++){
										cout << charCount << "." << (*charIt)->getName() << endl;	//loop through character list
									}
									while((targetCount-'0') < 0 || (targetCount-'0') > charCount) cin >> targetCount;	//ask for target
									int userTarget = targetCount-'0';
									int charNum = 0;
									for(list<gameChar*>::iterator charIt=charList.begin();charIt!=charList.end();charIt++,charNum++){
										if(charNum == userTarget){
											amount = (*it)->cast(myChar, *(*charIt));
											cout << "You casted " << (*it)->skillName() << " on " << (*charIt)->getName() << ", dealing " << amount << " points. " << endl;
										}
									}
									*/
								}
								isMoved = true;
							}
						}
					}
				}
				//myCharPtr = &myChar;
				charList.push_back((*it));			//finished current move, push character to end of list
			}
			
			else if(charType.compare("enemyChar")==0){		//enemy's round, do basic attack to player, print data, push character to end of list
				
				fightScene::attackChar(enemyChar, myChar);
				if(myChar.getCurrentHP()<=0) break;
				
				charList.push_back((*it));
			}
			
			if(myChar.getCurrentHP()<=0) break;		//enemy defeated character, break the loop
			
			userInput = 'x';				//reset input for the loop condition
			charList.pop_front();
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
			userInput = '0';
			cout << "continue or back to menu?" << endl;
			cout << "y. Continue" << endl;
			cout << "n. Back to menu" << endl;
			cin >> userInput;
		}
		if(userInput == 'n') break;
	}
}
