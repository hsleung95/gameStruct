//
//  gameChar.hpp
//  gameStruct
//
//  Created by Wilson Leung on 20/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef gameChar_hpp
#define gameChar_hpp
#pragma once

#include <list>
#include <stdio.h>
#include <string>

using namespace std;

class gameChar{
public:
	const static int wearingNum = 8;
	const static int ownedNum = 10;
	const static int attrNum = 5;
	bool defensed;
	static string attrStr[5];
	
protected:
    int lv;
	float maxHP, currentHP;
	float maxMP, currentMP;
	float attack, attVal, attMod;	int decreasedAttRound; bool decreasedAtt;
	float defense, defVal, defMod; int defenseRound, decreasedDefRound;	bool decreasedDef;	//	value for defense action
	float intelligence, intVal, intMod; int decreasedIntRound;	bool decreasedInt;
    string charName;
    
public:
    gameChar();
    gameChar(string name, float hpVal,float mpVal,float att,float def, float intelligence);
    
    float getCurrentHP();
    float getMaxHP();
    float getCurrentMP();
    float getMaxMP();
    float getAttack();
    float getDefense();
	float getIntelligence();
	float getDefVal();
	float getAttVal();
	float getIntVal();
	float getAttMod();
	float getDefMod();
	float getIntMod();
    int   getLV();
    string getName();
	virtual string getType();
    static int getRandCount();
    
    void setCurrentHP(float val);
    void setMaxHP(float val);
    void setCurrentMP(float val);
    void setMaxMP(float val);
    void setAttack(float val);
    void setDefense(float val);
	void setIntelligence(float val);
	void setAttVal(float val);
	void setDefVal(float val);
	void setIntVal(float val);
	void setAttMod(float val);
	void setDefMod(float val);
	void setIntMod(float val);
    void setName(string name);
	void decreaseAttr(int attribute, float effectVal, int currentRound);
	void checkRoundStat(int currentRound);
	
    virtual void printStat();
    
    void setChar(string name, float charHP, float charMP, float charAtt, float charDef,float charInt, int lv);
    void randChar(int lv);
    
    float attackChar(gameChar target);
	bool defenseAction(int currentRound);
	bool stopDefense();
};

#endif /* gameChar_hpp */
