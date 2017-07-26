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

void outPutCharVal(gameChar character){
    cout << endl << "character: Name: " << character.getName() << ", HP: " << character.getCurrentHP() << ", MP: " << character.getCurrentMP() << ", Attack: " << character.getAttack() << ", defense: " << character.getDefense() << endl;
}

int main() {
    string charName;
    string userInput;
    //float charHP,charMP,charAtt,charDef;
    //int charLv;
    //gameChar enemyChar;
    enemyChar enemyChar;
    string option = "y";
    cout << "welcome to the RPG world, please enter the name and the value of your character:\n";
    cout << "name: ";
    cin >> charName;
    mainChar myChar(charName, 100,50,10,10);
    outPutCharVal(myChar);
    while(option.compare("y")==0){  //ask for input after finishing a monster or defeated by monster
        do{
            string enemyName = "enemy";
            enemyName = enemyName + std::to_string(gameChar::getRandCount());
            enemyChar.setName(enemyName);
            enemyChar.randChar(1);
            enemyChar.setExpContain();
            outPutCharVal(enemyChar);
            cout << "are you sure to fight this monster?(y/n)" << endl;
            cin >> userInput;
        }
        while(userInput.compare("n")==0);
        if(userInput.compare("y") == 0){
            bool defensed = false;
            float defVal = myChar.getDefense();
            if(myChar.getCurrentHP()<=0) myChar.setCurrentHP(myChar.getMaxHP());
            while(enemyChar.getCurrentHP()>0 && myChar.getCurrentHP()>0){
                while(userInput.compare("a")!=0&&userInput.compare("b")!=0){
                    cout << "What do you want to do?\n a. attack \n b. defense \n Please enter 'a' or 'b'. ";
                    cin >> userInput;
                }
                if(userInput.compare("a")==0){
                    float damage = myChar.attackChar(enemyChar);
                    cout << "You have done " << damage << " damage to " << enemyChar.getName() << endl;
                    if(enemyChar.getCurrentHP()<=0) break;
                }
                
                else if(userInput.compare("b")==0){
                    defVal = myChar.getDefense();
                    myChar.setDefense(defVal);
                    defensed = true;
                }
                
                float enemyDamage = enemyChar.attackChar(myChar);
                cout << enemyChar.getName() << " have  done " << enemyDamage << " damage to you" << endl;
                if(myChar.getCurrentHP()<=0) break;
                if(defensed){
                    myChar.setDefense(defVal);
                }
                userInput = "";
                outPutCharVal(myChar);
                outPutCharVal(enemyChar);
                
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
            cout << "continue?(y/n)\n";
            cin >> option;
            if(option.compare("n")==0) break;
        }
    }
    
    return 0;
}


