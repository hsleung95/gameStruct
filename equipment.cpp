//
//  equipment.cpp
//  gameStruct
//
//  Created by Wilson Leung on 27/7/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "equipment.hpp"
string equipment::eqTypeStr[8] = {"head","shoulders","arms","body","legs","boots","leftHand","rightHand"};

equipment::equipment(){
	eqName = "";
	description = "";
	lv = 1;
	rank = 1;
	for(int i=0;i<4;i++){
		attributePair[i] =  pair<attribute, float>(static_cast<attribute>(rand()%4), (0));
	}
}

equipment::equipment(enum eqType equipType){
	eqType = equipType;
	eqName = "";
	description = "";
	lv = 1;
	rank = 1;
	for(int i=0;i<4;i++){
		attributePair[i] =  pair<attribute, float>(static_cast<attribute>(rand()%4), (0));
	}
}

equipment::equipment(string name, gameChar ownedBy, string eqDescription, int lvCap, enum eqType equipType, int eqRank, pair<attribute, float> attrPair[4]){
	eqType = equipType;
	eqName = name;
	owner = ownedBy;
	description = eqDescription;
	lv = lvCap;
	if(eqRank > 4) eqRank = 4;
	rank = eqRank;
	for(int i=0;i<4;i++){
		attributePair[i] = attrPair[i];
	}
}

void equipment::setEquipment(string name, gameChar ownedBy, string eqDescription, int lvCap, enum eqType equipType, int eqRank, pair<attribute, float> attrPair[4]){
	eqType = equipType;
	eqName = name;
	owner = ownedBy;
	description = eqDescription;
	lv = lvCap;
	if(eqRank > 4) eqRank = 4;
	rank = eqRank;
	for(int i=0;i<4;i++){
		attributePair[i] = attrPair[i];
	}
}

enum equipment::eqType equipment::getEqType(){ return eqType;}
enum equipment::attribute equipment::getAttribute(int index){ return attributePair[index].first;}
string equipment::getEqName(){return eqName;}
gameChar equipment::getOwner(){return owner;}
string equipment::getDescription(){return description;}
float equipment::getEqVal(int index){return attributePair[index].second;}
int equipment::getLvCap(){return lv;}
int equipment::getRank(){return rank;}

void equipment::randomEquipment(int lvCap, gameChar ownedChar){
	eqName = "random equipment";
	description = "random equipment";
	eqType = static_cast<enum equipment::eqType>(rand()%gameChar::wearingNum);
	owner = ownedChar;
	lv = lvCap;
	int randNum = rand()%100;
	if(randNum < 20) rank = 1;
	else if(randNum < 60) rank = 2;
	else if(randNum < 90) rank = 3;
	else rank = 4;
	for(int i=0;i<rank;i++){
		enum equipment::attribute attr = static_cast<enum equipment::attribute>(rand()%5);
		float attrVal = (rand()%10 + 1) * lv;
		attributePair[i] = pair<attribute, float>(attr, attrVal);
	}
}

bool equipment::setOwner(gameChar ch){
	owner = ch;
	return true;
}

void equipment::printEq(){
	cout << "Equipment Type: " << equipment::eqTypeStr[eqType] << endl;
	cout << "Name: " << eqName << endl;
	cout << "Rank: " << rank << endl;
	cout << "Description: " << description << endl;
	//cout << "+" << effectingVal  << " " << gameChar::attrStr[(int)attribute] << endl;
	for(int i=0;i<rank;i++){
		cout << "+" << attributePair[i].second << " " << gameChar::attrStr[(int)attributePair[i].first] << endl;
	}
	cout << "can be equiped after lv" << lv << endl;
}

bool equipment::equipChar(gameChar &equiped){
  for(int i=0;i<rank;i++){
    float effectingVal = attributePair[i].second;
	  cout << "+" << effectingVal << gameChar::attrStr[attributePair[i].first] << endl;
    switch (attributePair[i].first) {
	case 0:{
		equiped.setMaxHP(equiped.getMaxHP()+effectingVal);
		equiped.setCurrentHP(equiped.getCurrentHP()+effectingVal);
		break;
	}
	case 1:{
		equiped.setMaxMP(equiped.getMaxMP()+effectingVal);
		equiped.setCurrentMP(equiped.getCurrentMP()+effectingVal);
		break;
	}
	case 2:{
		equiped.setAttack(equiped.getAttack()+effectingVal);
		break;
	}
	case 3:{
		equiped.setDefense(equiped.getDefense()+effectingVal);
		break;
	}
	case 4:{
		equiped.setIntelligence(equiped.getIntelligence()+effectingVal);
		break;
	}
			
	default:{
		return false;
		break;
	}
    }
  }
  return true;
}

bool equipment::unEquipChar(gameChar &equiped){
  for(int i=0;i< rank;i++){
    float effectingVal = attributePair[i].second;
    switch (attributePair[i].first) {
		case 0:{
			equiped.setMaxHP(equiped.getMaxHP() - effectingVal);
			equiped.setCurrentHP(equiped.getCurrentHP() - effectingVal);
			break;
		}
		case 1:{
			equiped.setMaxMP(equiped.getMaxMP() - effectingVal);
			equiped.setCurrentMP(equiped.getCurrentMP() - effectingVal);
			break;
		}
		case 2:{
			equiped.setAttack(equiped.getAttack() - effectingVal);
			break;
		}
		case 3:{
			equiped.setDefense(equiped.getDefense() - effectingVal);
			break;
		}
		case 4:{
			equiped.setIntelligence(equiped.getIntelligence() - effectingVal);
			break;
		}
			
		default:{
			return false;
			break;
		}
	}
  }
	return true;
}

bool equipment::isNull(){
	if(eqName=="" && description == "" && lv == 1 && rank == 1) return true;
	return false;
}

bool equipment::operator==(equipment &eq){
	return (this == &eq ? true : false);
}
