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
	enemyChar.setName(enemyName);
	enemyChar.randChar(lv);
	enemyChar.setExpContain();
	return enemyChar;
}

bool fightScene::attackChar(gameChar &source, gameChar &target){
	float damage = source.attackChar(target);
	target.setCurrentHP((target.getCurrentHP()-damage));
	cout << source.getName() << " have done " << damage << " damage to " << target.getName() << endl;
	source.printStat();
	target.printStat();
	return false;
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
		
		for(list<gameChar*>::iterator it=charList.begin();it!=charList.end();it++){
			float defVal = myChar.getDefense();
			bool defensed = false;
			bool isMoved = false;
			if((*it)->getCurrentHP()<=0) break;
			
			string charType = (*it)->getType();
			
			if(charType.compare("mainChar")==0){	//check current character type
				while(isMoved == false){
					if(userInput!='a'&&userInput!='b'&&userInput!='c'){	//turn of player
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
						defensed = true;
						isMoved = true;
					}
				
					else if(userInput=='c'){
						myChar.printSkill();
						char userCast = '0';
						do{
							cout << "Enter the key to cast the magic or 'x' to choose other action: " << endl;
							cin >> userCast;
						}
						while(myChar.checkMagicKey(userCast) == false && userCast != 'x');
						if(userCast == 'x'){
							isMoved = false;
							continue;
						}
						else{
							float amount = 0;
							for(list<skill*>::iterator it=skillList.begin();it!=skillList.end();it++){
								if(userCast == (*it)->getKey()){
									cout << "cast on self(s) or cast on enemy(e)? " << endl;
									cin >> userCast;
									if(userCast == 's'){
										amount = (*it)->cast(myChar, myChar);
									}
									else{
										amount = (*it)->cast(myChar, enemyChar);
									}
								}
							}
							isMoved = true;
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
