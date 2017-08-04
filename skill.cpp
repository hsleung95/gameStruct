//
//  skill.cpp
//  gameStruct
//
//  Created by Wilson Leung on 4/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "skill.hpp"

skill::skill(){}

float skill::cast(gameChar &source, gameChar &target){return 0;}
string skill::skillName(){return "skill";}
float skill::castSkill(gameChar &source, gameChar &target, float val){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	
	source.setCurrentMP(sourceMP - cost);
	float amount = effectVal*source.getIntelligence()*0.5;
	target.setCurrentHP(target.getCurrentHP() + amount);
	return amount;
}

restore_health::restore_health(){
	cost = 10;
	effectVal = 20;
}
string restore_health::skillName(){return "restore health";}
float restore_health::cast(gameChar &source, gameChar &target){
	return skill::castSkill(source, target, effectVal);
}

string magic_attack::skillName(){return "magic attack";}
magic_attack::magic_attack(){
	cost = 20;
	effectVal = -50;
}

float magic_attack::cast(gameChar &source, gameChar &target){
	return skill::castSkill(source, target, effectVal);
}
