//
//  gameChar.hpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef gameChar_hpp
#define gameChar_hpp

#include <stdio.h>
#include <string>
using namespace std;

#endif /* gameChar_hpp */
class gameChar{
    float hp,mp, attack, defense;
    string charName;
    
public:
    gameChar();
    gameChar(string name, float hpVal,float mpVal,float att,float def);
    
    float getHP();
    float getMP();
    float getAttack();
    float getDefense();
    string getName();
    
    void setHP(float val);
    void setMP(float val);
    void setAttack(float val);
    void setDefense(float val);
    void setName(string name);
    void setChar(string name, float charHP, float charMP, float charAtt, float charDef);
    
    void attackChar(gameChar target);

};
