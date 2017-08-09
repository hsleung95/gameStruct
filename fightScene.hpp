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
#include "mainChar.hpp"
#include "equipment.hpp"
#include <stdlib.h>
#include <list>

class fightScene{
public:
	static void fightFunction(mainChar &myChar);
	static enemyChar createEnemy(int lv);
	static bool attackChar(gameChar &source, gameChar &target);
	static gameChar& selectTarget(list<gameChar*> charlist);
	static void printDefense(gameChar gamechar);
};


#endif /* fightScene_hpp */
