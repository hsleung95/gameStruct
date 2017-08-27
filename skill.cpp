//
//  skill.cpp
//  gameStruct
//
//  Created by Wilson Leung on 4/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "skill.hpp"

skill::skill(){}
skill::skill(string name, float skillCost, float skillVal, char skillKey, string skillDes){
	skillName = name;
	cost = skillCost;
	effectVal = skillVal;
	key = skillKey;
	description = skillDes;
	skillLv = 1;
}

char skill::getKey(){return key;}
string skill::getSkillName(){return skillName;}
string skill::getDescription(){return description;}
float skill::getCost(){return cost;}
int skill::getSKillLv(){return skillLv;}

float skill::cast(gameChar &source, gameChar &target){return castSkill(source, target, effectVal);}

float skill::castSkill(gameChar &source, gameChar &target, float val){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	source.setCurrentMP(sourceMP - cost);
	
	float magicDef = target.getIntelligence();
	if(effectVal > 1) magicDef = 0;
	float amount = effectVal * source.getIntelligence()* 1 + magicDef;	//value = -(spellAmount * intelligence - targetIntelligence)
	float effectingVal = amount;
	if(effectingVal > target.getMaxHP()) effectingVal = target.getMaxHP() - target.getCurrentHP();	//restoring health n amount > maxHP, set difference = maxHP - currentHP
	else if(fabsf(effectingVal) >= target.getCurrentHP()) effectingVal = -(target.getCurrentHP());	//dealing damage n value > current health, set difference = currentHP (currentHP - currentHP = 0)
	target.setCurrentHP(target.getCurrentHP() + effectingVal);
	return fabsf(effectingVal);
}
