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

bool career::addExp(float expAmount){
	if(mainChar::addExp(expAmount)){
		lvUp();
		return true;
	}
	return false;
}

bool career::lvUp(){
	mainChar::lvUp();
	return true;
}
string career::getCareer(){return "career";}

bool adventurer::addExp(float expAmount){
	if(career::addExp(expAmount)){
		lvUp();
		return true;
	}
	return false;
}
string adventurer::getCareer(){return "adventurer";}
bool adventurer::lvUp(){
	career::lvUp();
	maxHP += 10;
	maxMP +=5;
	attack += 3;
	defense += 3;
	intelligence += 1;
	expCap -= 200*lv;
	return true;
}

bool magician::addExp(float expAmount){
	if(career::addExp(expAmount)){
		lvUp();
		return true;
	}
	return false;
}
string magician::getCareer(){return "magician";}
bool magician::lvUp(){
	career::lvUp();
	maxHP += 5;
	maxMP +=10;
	attack += 2;
	defense += 2;
	intelligence += 5;
	return true;
}

bool fighter::addExp(float expAmount){
	if(career::addExp(expAmount)){
		lvUp();
		return true;
	}
	return false;
}
string fighter::getCareer(){return "fighter";}
bool fighter::lvUp(){
	career::lvUp();
	maxHP += 15;
	maxMP +=5;
	attack += 5;
	defense += 5;
	intelligence += 1;
	return true;
}
