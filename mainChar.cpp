//
//  mainChar.cpp
//  gameStruct
//
//  Created by Wilson Leung on 25/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "mainChar.hpp"
#include <iostream>

mainChar::mainChar(){
    exp = 0;
    expCap = setExpCap(1);
}

mainChar::mainChar(string name, float hpVal,float mpVal,float att,float def,float intl) : gameChar(name,hpVal,mpVal,att,def, intl){
    exp = 0;
    expCap = setExpCap(lv);		// expCap = (x^2)/2 + 125x
}

bool mainChar::addExp(float expAmount){
    exp += expAmount;
    if(exp >= expCap){
        lvUp();
        return true;
    }
    return false;
}

void mainChar::lvUp(){
	lv += 1;
    maxHP += 100;
    maxMP += 50;
    attack += 10;
    defense += 10;
	intelligence += 10;
    expCap += setExpCap(lv);
}

float mainChar::setExpCap(int lv){
	return (lv * lv)/2 + (125 * lv);
}

void mainChar::printStat(){
	cout << "Your character value: "<< endl;
    gameChar::printStat();
	std::cout << " LV: " << lv << " Current EXP: " << exp << "/" << expCap << std::endl << endl;
}

string mainChar::getType(){ return "mainChar";}
