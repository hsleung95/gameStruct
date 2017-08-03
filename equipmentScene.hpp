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
#include "mainChar.hpp"
#include "equipment.hpp"
#include <stdlib.h>
#include <list>

class equipmentScene{
public:
	static void equipmentFunction(mainChar &myChar);
};

#endif /* equipmentScene_hpp */
