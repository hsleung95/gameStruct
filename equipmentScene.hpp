//
//  equipmentScene.hpp
//  gameStruct
//
//  Created by Wilson Leung on 3/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#ifndef equipmentScene_hpp
#define equipmentScene_hpp

#pragma once
#include <iostream>
#include <string>
#include "enemyChar.hpp"
#include "career.hpp"
#include "equipment.hpp"
#include <stdlib.h>
#include <list>

class equipmentScene{
public:
	static void printAllEquipment(career &myChar);
	static void equipmentFunction(career &myChar);
};

#endif /* equipmentScene_hpp */
