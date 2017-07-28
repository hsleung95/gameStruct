//
//  equipment.cpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "equipment.hpp"

equipment::equipment(){
	eqName = "";
	description = "";
	effectingVal = 0;
}

equipment::equipment(string name, gameChar ownedBy, string eqDescription, int equipType, int effectingField, float effectVal){
	eqName = name;
	owner = ownedBy;
	description = eqDescription;
	effectingVal = effectVal;
}
