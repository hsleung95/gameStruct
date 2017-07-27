//
//  equipment.hpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//


#ifndef equipment_hpp
#define equipment_hpp
#pragma once

#include <stdio.h>
#include "gameChar.hpp"
#include <string>

#endif /* equipment_hpp */

class equipment{
	enum eqType {head, shoulders, left_hand, right_hand, body, legs, foots};	//7 parts
	enum effectField {hp,mp, attack, defense, intelligence};
	string eqName;
	gameChar owner;
	string description;
	float effectingVal;
	
public:
	equipment();
	equipment(string name, gameChar ownedBy, string description, int equipType, int effectingField, float effectVal);
	
	void changeOwner(gameChar gamechar);
	void increaseFieldByVal();
};
