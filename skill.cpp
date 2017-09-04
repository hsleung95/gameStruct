//
//  skill.cpp
//  gameStruct
//
//  Created by Wilson Leung on 4/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "skill.hpp"

const string skill::skillTypeArr[skillTypeNum] = {"damage","healing","modifier"};

skill::skill(){}
skill::skill(string name, float skillCost, float skillVal, char skillKey, string skillDes, int type, int field){
	skillName = name;
	cost = skillCost;
	effectVal = skillVal;
	key = skillKey;
	description = skillDes;
	skillType = type;
	skillField = field;
}

char skill::getKey(){return key;}
string skill::getSkillName(){return skillName;}
string skill::getDescription(){return description;}
float skill::getCost(){return cost;}

//float skill::cast(gameChar &source, gameChar &target){return castSkill(source, target, effectVal);}

float skill::cast(gameChar &source, gameChar &target){
	float sourceMP = source.getCurrentMP();
	if(sourceMP < cost) return -1;
	source.setCurrentMP(sourceMP - cost);
	float effectingVal = 0;
	
	if(skillType == 0){
		float magicDef = target.getIntelligence();
		effectingVal = -(effectVal * source.getIntelligence()* 1 + magicDef);	//value = -(spellAmount * intelligence - targetIntelligence)
		if(fabsf(effectingVal) >= target.getCurrentHP()) effectingVal = -(target.getCurrentHP());	//dealing damage n value > current health, set difference = currentHP (currentHP - currentHP = 0)
		setTargetParam(target, skillField, effectingVal);
		return -(effectingVal);
	}
	else if(skillType == 1){
		effectingVal = effectVal * source.getIntelligence() * 1;
		if(effectingVal > target.getMaxHP()) effectingVal = target.getMaxHP() - target.getCurrentHP();	//restoring health n amount > maxHP, set difference = maxHP - currentHP
		target.setCurrentHP(target.getCurrentHP()+effectingVal);
	}
	return effectingVal;
}

void skill::setTargetParam(gameChar &target, int field, int effectVal){
	switch(field){
		case 0: target.setCurrentHP(target.getCurrentHP() + effectVal); break;
		case 1: target.setCurrentMP(target.getCurrentMP() + effectVal); break;
		case 2: target.setAttVal(target.getAttVal() + effectVal); break;
		case 3: target.setDefVal(target.getDefVal() + effectVal); break;
		case 4: target.setIntVal(target.getIntVal() + effectVal); break;
	}
}
/************************ code for skillNode(skill tree node) *****************/

skillNode::skillNode(){}
skillNode::skillNode(int lv, skill in){
	unlockLv = lv;
	containSkill = in;
}

int skillNode::getUnlockLv(){return unlockLv;}
skill skillNode::getSkill(){return containSkill;}
