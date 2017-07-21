//
//  main.cpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include <iostream>
#include "gameChar.hpp"
#include <stdlib.h>

void outPutCharVal(gameChar character){
    cout << endl << "character: Name: " << character.getName() << ", HP: " << character.getHP() << ", MP: " << character.getMP() << ", Attack: " << character.getAttack() << ", defense: " << character.getDefense() << endl;
}

int main() {
    string charName;
    string userInput;
    float charHP,charMP,charAtt,charDef;
    int charLv;
    gameChar enemyChar;
    string option = "y";
    cout << "welcome to the RPG world, please enter the name and the value of your character:\n";
    cout << "name: ";
    cin >> charName;
    gameChar myChar(charName, 100,50,10,10);
    outPutCharVal(myChar);
    while(option.compare("y")==0){
        while(userInput.compare("y")!=0&&userInput.compare("n")!=0){
            cout << "You want to create monsters by yourself or computer generate monsters for you?(y/n)" << endl;
            cin >> userInput;
            cout << "Please enter 'y' if you want to create a monster by yourself or 'n' if you want computer generate them for you" << endl;
        }
        if(userInput.compare("y")==0){
            cout << "name: ";
            cin >> charName;
            cout << endl << "HP, MP, attack, defense, lv of your character: ";
            cin >> charHP >> charMP >> charAtt >> charDef >> charLv;
            enemyChar.setChar(charName, charHP,charMP,charAtt,charDef, charLv);
        }
        else if(userInput.compare("n")==0){
            enemyChar.setName("Enemy1");
            enemyChar.randChar(1);
        }
        outPutCharVal(enemyChar);
        cout << "are you sure to fight this monster?(y/n)" << endl;
        cin >> userInput;
        if(userInput.compare("y") == 0){
            bool defensed = false;
            float defVal = myChar.getDefense();
            while(enemyChar.getHP()>0 && myChar.getHP()>0){
                while(userInput.compare("a")!=0&&userInput.compare("b")!=0){
                    cout << "What do you want to do?\n a. attack \n b. defense \n Please enter 'a' or 'b'. ";
                    cin >> userInput;
                }
                if(userInput.compare("a")==0){
                    float damage = myChar.attackChar(enemyChar);
                    cout << "You have done " << damage << " damage to " << enemyChar.getName() << endl;
                }
                else if(userInput.compare("b")==0){
                    defVal = myChar.getDefense();
                    myChar.setDefense(defVal*2);
                    defensed=true;
                }
                float enemyDamage = enemyChar.attackChar(myChar);
                cout << enemyChar.getName() << " have  done " << enemyDamage << " damage to you" << endl;
                if(defensed){
                    myChar.setDefense(defVal);
                }
                userInput = "";
                outPutCharVal(myChar);
                outPutCharVal(enemyChar);
                
            }
            if(enemyChar.getHP() <=0){
                cout << "You defeated " << enemyChar.getName() << ", continue?(y/n)\n";
                cin >> option;
            }
            else{
                cout << "You defeated by " << enemyChar.getName() << ", continue?(y/n)\n";
                cin >> option;
            }
            if(option.compare("n")==0) break;
        }
    }
    
    return 0;
}


