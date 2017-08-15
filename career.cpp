//
//  career.cpp
//  gameStruct
//
//  Created by Wilson Leung on 9/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "career.hpp"
career::career(){}
career::career(string name, float hpVal,float mpVal,float att,float def,float intl) : mainChar(name,hpVal,mpVal,att,def,intl){}
adventurer::adventurer(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){}
magician::magician(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){}
fighter::fighter(string name, float hpVal,float mpVal,float att,float def,float intl) : career(name,hpVal,mpVal,att,def,intl){}

string career::getCareer(){return "career";}

string adventurer::getCareer(){return "adventurer";}
bool adventurer::lvUp(){
	mainChar::lvUp();
	maxHP += 10;
	maxMP +=5;
	attack += 3;
	defense += 3;
	intelligence += 1;
	expCap -= 200*lv;
	return true;
}

string magician::getCareer(){return "magician";}
bool magician::lvUp(){
	mainChar::lvUp();
	maxHP += 5;
	maxMP +=10;
	attack += 2;
	defense += 2;
	intelligence += 5;
	return true;
}

string fighter::getCareer(){return "fighter";}
bool fighter::lvUp(){
	mainChar::lvUp();
	maxHP += 15;
	maxMP +=5;
	attack += 5;
	defense += 5;
	intelligence += 1;
	return true;
}
