//
//  skill.cpp
//  gameStruct
//
//  Created by Wilson Leung on 4/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "skill.hpp"

skill::skill(){}

char skill::getKey(){return 's';}
string skill::skillName(){return "skill";}
string skill::getDescription(){return "skill description";}
float skill::cast(gameChar &source, gameChar &target){return 0;}
float skill::getCost(){return cost;}
float skill::castSkill(gameChar &source, gameChar &target, float val){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	source.setCurrentMP(sourceMP - cost);
	
	float magicDef = target.getIntelligence();
	if(effectVal > 1) magicDef = 0;
	float amount = effectVal*source.getIntelligence()*0.5 + magicDef;
	float effectingVal = target.getCurrentHP() + amount;
	if(effectingVal > target.getMaxHP()) effectingVal = target.getMaxHP() - target.getCurrentHP();	//restoring health n amount > maxHP, set difference = maxHP - currentHP
	else if(effectingVal <= 0) effectingVal = -(target.getCurrentHP());	//dealing damage n value > current health, set difference = currentHP (currentHP - currentHP = 0)
	target.setCurrentHP(target.getCurrentHP() + effectingVal);
	return fabsf(effectingVal);
}

restore_health::restore_health(){
	cost = 6;
	effectVal = 2;
	key = 'r';
	description = "Restore health based on intelligence";
}
char restore_health::getKey(){return key;}
string restore_health::skillName(){return "restore health";}
string restore_health::getDescription(){return description;}
float restore_health::getCost(){return cost;}
float restore_health::cast(gameChar &source, gameChar &target){
	float result =  skill::castSkill(source, target, effectVal);
	cout << "You restored " << result << " points to " << target.getName();
	cout << endl;
	return result;
}

magic_attack::magic_attack(){
	cost = 5;
	effectVal = -2;
	key = 'm';
	description = "Damage enemy for based on intelligence";
}
char magic_attack::getKey(){return key;}
string magic_attack::skillName(){return "magic attack";}
string magic_attack::getDescription(){return description;}
float magic_attack::getCost(){return cost;}
float magic_attack::cast(gameChar &source, gameChar &target){
	float result =  skill::castSkill(source, target, effectVal);
	cout << "You have done " << result << " damage to " << target.getName();
	cout << endl;
	return result;
}
