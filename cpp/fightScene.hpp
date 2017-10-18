//
//  fightScene.hpp
//  gameStruct
//
//  Created by Wilson Leung on 3/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef fightScene_hpp
#define fightScene_hpp
#pragma once
#include <iostream>
#include <string>
#include "enemyChar.hpp"
#include "career.hpp"
#include "equipment.hpp"
#include "skill.hpp"
#include <stdlib.h>
#include <list>

class fightScene{
public:
	static void fightFunction(career &myChar);
	static enemyChar createEnemy(int lv);
	static bool attackChar(gameChar &source, gameChar &target);
	static bool castSkillOnChar(gameChar &source, gameChar &target, skill* cast, int currentRound);
	static gameChar& selectTarget(list<gameChar*> charlist);
	static void printDefense(gameChar gamechar);
	static void resetChar(gameChar gamechar);
	static void fightRound(list<gameChar*> &charList, mainChar &myChar, enemyChar &enemyChar, list<skill*> skillList);
};


#endif /* fightScene_hpp */
