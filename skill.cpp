//
//  skill.cpp
//  gameStruct
//
//  Created by Wilson Leung on 4/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "skill.hpp"

/********** base class of all skill class ***************/

skill::skill(){}
skill::skill(string name, float skillCost, float skillVal, char skillKey, string skillDes){
	skillName = name;
	cost = skillCost;
	effectVal = skillVal;
	key = skillKey;
	description = skillDes;
}

char skill::getKey(){return key;}
string skill::getSkillName(){return skillName;}
string skill::getDescription(){return description;}
float skill::getCost(){return cost;}
string skill::getSkillClass(){return "skill";}

float skill::cast(gameChar &source, gameChar &target, int currentRound){
	cout << "skill casted" << endl;
	return 0;
}

void skill::setTargetParam(gameChar &target, int field, int effectVal){
	switch(field){
		case 0: target.setCurrentHP(target.getCurrentHP() + effectVal); break;
		case 1: target.setCurrentMP(target.getCurrentMP() + effectVal); break;
		case 2: target.setAttMod(target.getAttMod() + effectVal); break;
		case 3: target.setDefMod(target.getDefMod() + effectVal); break;
		case 4: target.setIntMod(target.getIntMod() + effectVal); break;
	}
}

void skill::printEffect(gameChar &source, gameChar &target, float value){cout << "skill::printEffect" << endl;}

/**************** magic class code ****************/
magic::magic(){}
magic::magic(string name, float skillCost, float skillVal, char skillKey, string skillDes) : skill(name,skillCost,skillVal,skillKey,skillDes){}
float magic::cast(gameChar &source, gameChar &target, int currentRound){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	source.setCurrentMP(sourceMP - cost);
	
	float effectingVal = 0;
	float magicDef = target.getIntelligence();
	effectingVal = -(effectVal * source.getIntVal()* 1 + magicDef);
	//value = -(spellAmount * intelligence * amplifier - targetIntelligence)
	if(fabsf(effectingVal) >= target.getCurrentHP()) effectingVal = -(target.getCurrentHP());
	//if damage > current health, set difference = currentHP (currentHP - currentHP = 0)
	setTargetParam(target, 0, effectingVal);
	return -(effectingVal);		//effectingVal must be <0 and negate it
}
void magic::printEffect(gameChar &source, gameChar &target, float value){
	cout << source.getName() << "has casted " << skillName << ", dealing " << value << " damage to " << target.getName() << endl;
}
string magic::getSkillClass(){return "magic";}

/**************** physical skill class code ****************/

physical_skill::physical_skill(){}
physical_skill::physical_skill(string name, float skillCost, float skillVal, char skillKey, string skillDes) : skill(name,skillCost,skillVal,skillKey,skillDes){}
float physical_skill::cast(gameChar &source, gameChar &target, int currentRound){
	float effectingVal = 0;
	srand((int)time(NULL));
	int chance = rand() % 100;
	if(chance < 20) return 0;

	cout << "physical_skill casted" << endl;
	effectingVal = source.getAttVal() + source.getAttMod() - (target.getDefVal() + target.getDefMod() );
	effectingVal = -(effectingVal);
	//value = -(spellAmount * intelligence * amplifier - targetIntelligence)
	if(fabsf(effectingVal) >= target.getCurrentHP()) effectingVal = -(target.getCurrentHP());
	cout << "target health: " << target.getCurrentHP();
	//if damage > current health, set difference = currentHP (currentHP - currentHP = 0)
	setTargetParam(target, 0, effectingVal);
	cout << "target health: " << target.getCurrentHP() << endl;
	return -(effectingVal);		//effectingVal must be <0 and negate it
}
void physical_skill::printEffect(gameChar &source, gameChar &target, float value){
	if(value==0) cout << source.getName() << " missed." << endl;
	cout << source.getName() << " casted " << skillName << ", dealing " << value << " damage to " << target.getName() << endl;
}
string physical_skill::getSkillClass(){return "physical_skill";}

/**************** restoration skill class code ****************/

restore_health::restore_health(){}
restore_health::restore_health(string name, float skillCost, float skillVal, char skillKey, string skillDes) : skill(name,skillCost,skillVal,skillKey,skillDes){}
float restore_health::cast(gameChar &source, gameChar &target, int currentRound){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	source.setCurrentMP(sourceMP - cost);
	
	float effectingVal = 0;
	effectingVal = effectVal * source.getIntVal() * 1;
	//value = spellAmount * intelligence * amplifier
	if((target.getCurrentHP() + effectingVal) >= target.getMaxHP()) effectingVal = target.getMaxHP() - target.getCurrentHP();
	//if amount + current health > max health, set difference = max hp - current hp
	setTargetParam(target, 0, effectingVal);
	return effectingVal;		//effectingVal must be <0 and negate it
}
void restore_health::printEffect(gameChar &source, gameChar &target, float value){
	string targetName = target.getName();
	if(source.getName() == target.getName()) targetName = "self";
	cout << source.getName() << " casted " << skillName << " on " << targetName << ", restoring " << value << " hp." << endl;
}
string restore_health::getSkillClass(){return "restore_health";}

/**************** attribute modifier class code ****************/

attribute_modifier::attribute_modifier(){}
attribute_modifier::attribute_modifier(string name, float skillCost, float skillVal, char skillKey, string skillDes, int skillField) : skill(name,skillCost,skillVal,skillKey,skillDes){
	if(skillField >= 2 && skillField <= 4) field = skillField;
}
float attribute_modifier::cast(gameChar &source, gameChar &target, int currentRound){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	source.setCurrentMP(sourceMP - cost);
	
	float effectingVal = 0;
	effectingVal = effectVal * source.getIntVal() * 0.1;
	target.decreaseAttr(field, effectingVal, currentRound);
	return effectingVal;
}
void attribute_modifier::printEffect(gameChar &source, gameChar &target, float value){
	string attrName = gameChar::attrStr[field];
	cout << source.getName() << " casted " << skillName << " on " << target.getName() << " , decreasing " << value << " " << attrName << endl;
}
string attribute_modifier::getSkillClass(){return "attribute_modifier";}
/************************ code for skillNode(skill tree node) *****************/

skillNode::skillNode(){}
skillNode::skillNode(int lv, skill* in){
	unlockLv = lv;
	containSkill = in;
}

int skillNode::getUnlockLv(){return unlockLv;}
skill* skillNode::getSkill(){return containSkill;}
