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

int main() {
    string charName;
    string userInput;
    float charHP,charMP,charAtt,charDef;
    gameChar enemyChar;
    int option = 1;
    cout << "welcome to the RPG world, please enter the name and the value of your character:\n";
    cout << "name: ";
    cin >> charName;
    gameChar myChar(charName, 100,10,10,10);
    cout << endl << "your character: Name: " << myChar.getName() << ", HP: " << myChar.getHP() << ", MP: " << myChar.getMP() << ", Attack: " << myChar.getAttack() << ", defense: " << myChar.getDefense() << endl;
    while(option == 1){
        while(userInput.compare("y")!=0&&userInput.compare("n")!=0){
            cout << "You want to create monsters by yourself or computer generate monsters for you?(y/n)" << endl;
            cin >> userInput;
            cout << "Please enter 'y' if you want to create a monster by yourself or 'n' if you want computer generate them for you" << endl;
        }
        if(userInput.compare("y")==0){
            cout << "name: ";
            cin >> charName;
            cout << endl << "HP, MP, attack, defense of your character: ";
            cin >> charHP >> charMP >> charAtt >> charDef;
            enemyChar.setChar(charName, charHP,charMP,charAtt,charDef);
        }
        else if(userInput.compare("n")==0){
            enemyChar.setChar("enemy1", rand()%100, rand()%10, rand()%10, rand()%10);
        }
        cout << endl << "enemy character: Name: " << enemyChar.getName() << ", HP: " << enemyChar.getHP() << ", MP: " << enemyChar.getMP() << ", Attack: " << enemyChar.getAttack() << ", defense: " << enemyChar.getDefense() << endl;
    }
    return 0;
}
