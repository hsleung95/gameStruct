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
#include <stdlib.h>

/*
void outPutCharVal(gameChar character){
    cout << endl << "character: Name: " << character.getName() << ", HP: " << character.getCurrentHP() << ", MP: " << character.getCurrentMP() << ", Attack: " << character.getAttack() << ", defense: " << character.getDefense() << endl;
}
*/

enemyChar createEnemy(int lv){
	enemyChar enemyChar;
	string enemyName = "enemy";
	enemyName = enemyName + std::to_string(gameChar::getRandCount());
	enemyChar.setName(enemyName);
	enemyChar.randChar(lv);
	enemyChar.setExpContain();
	return enemyChar;
}

int main() {
    string charName;
    string userInput;
    enemyChar enemyChar;
    string option = "y";
    cout << "welcome to the RPG world, please enter the name and the value of your character:\n";
    cout << "name: ";
    cin >> charName;
    mainChar myChar(charName, 100,50,10,10);
    while(option.compare("y")==0){  //ask for input after finishing a monster or defeated by monster
		myChar.printStat();
        do{					//do while loop: keep generating monster until player agree to fight this one
			enemyChar = createEnemy(myChar.getLV());
			enemyChar.printStat();
            cout << "are you sure to fight this monster?(y/n)" << endl;
            cin >> userInput;
        }
        while(userInput.compare("n")==0);
		
        if(userInput.compare("y") == 0){
			
            bool defensed = false;		//get character defense
            float defVal = myChar.getDefense();
			
            if(myChar.getCurrentHP()<=0) myChar.setCurrentHP(myChar.getMaxHP());	//refill charater health if defeated
			
            while(enemyChar.getCurrentHP()>0 && myChar.getCurrentHP()>0){
                while(userInput.compare("a")!=0&&userInput.compare("b")!=0){
                    cout << endl << "What do you want to do?\n a. attack \n b. defense ";
                    cin >> userInput;
                }
                if(userInput.compare("a")==0){
                    float damage = myChar.attackChar(enemyChar);
                    cout << "You have done " << damage << " damage to " << enemyChar.getName() << endl;
                    myChar.printStat();
                    enemyChar.printStat();
                    if(enemyChar.getCurrentHP()<=0) break;	//enemy defeated by player, break the loop
                }
                
                else if(userInput.compare("b")==0){
                    defVal = myChar.getDefense();
                    myChar.setDefense(defVal);
                    defensed = true;
                }
                
                float enemyDamage = enemyChar.attackChar(myChar);
                cout << enemyChar.getName() << " have  done " << enemyDamage << " damage to you" << endl;
				
                myChar.printStat();
                enemyChar.printStat();
				
                if(myChar.getCurrentHP()<=0) break;	//enemy defeated character, break the loop
				
                if(defensed){
                    myChar.setDefense(defVal);		//defend for one round
                }
                userInput = "";		//reset input for the loop condition
                
            }
			
            if(enemyChar.getCurrentHP() <=0){
                cout << "You defeated " << enemyChar.getName();
                cout << ", getting " << enemyChar.getExpContain() << "exp.";
                bool isLvUp = myChar.addExp(enemyChar.getExpContain());
                if(isLvUp){
                    cout << "You gained 1 lv!" << endl;
                }
            }
            else{
                cout << "You defeated by " << enemyChar.getName() << endl;
            }
			cout << endl;
			
			option = "";		//reset input for the loop condition
			
            while(option.compare("y")!=0&&option.compare("n")!=0){
                cout << "continue?(y/n)\n";
                cin >> option;
                if(option.compare("n")==0) break;
            }
        }
    }
    
    return 0;
}


