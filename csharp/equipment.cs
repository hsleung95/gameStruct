﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class Pair<T1, T2>{
	public T1 first;
	public T2 second;

	public Pair(T1 tfirst, T2 tsecond){
		first = tfirst;
		second = tsecond;
	}
}

public class equipment : MonoBehaviour
{
	public enum eqType {head=0, shoulders=1, arms=2, body=3, legs=4, boots=5, leftHand=6, rightHand=7};	//8 types of eq
	public enum attribute {attack=0, hp=1, mp=2, defense=3, intelligence=4};	//5 atrributes
	public static string[] eqTypeStr = {"head","shoulders","arms","body","legs","boots","leftHand","rightHand"};

	protected eqType eqtype;
	protected string eqName;
	protected gameChar owner;
	protected string description;
	protected Pair<attribute, float>[] attributePair;
	protected int lv;
	protected int rank;

	equipment(){
		eqName = "";
		description = "";
		lv = 1;
		rank = 1;
		for(int i=0;i<4;i++){
			attributePair[i] =  Pair<attribute, float>((Random.Range(0,4)), (0));
		}
	}

	equipment(eqType equipType){
		eqType = equipType;
		eqName = "";
		description = "";
		lv = 1;
		rank = 1;
		for(int i=0;i<4;i++){
			attributePair[i] =  Pair<attribute, float>((Random.Range(0,4)), (0));
		}
	}

	equipment(string name, gameChar ownedBy, string eqDescription, int lvCap, eqType equipType, int eqRank, Pair<attribute, float>[] attrPair){
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

	void setEquipment(string name, gameChar ownedBy, string eqDescription, int lvCap, eqType equipType, int eqRank, Pair<attribute, float>[] attrPair){
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

	eqType getEqType(){ return eqType;}
	attribute getAttribute(int index){ return attributePair[index].first;}
	string getEqName(){return eqName;}
	gameChar getOwner(){return owner;}
	string getDescription(){return description;}
	public float getEqVal(int index){return attributePair[index].second;}
	int getLvCap(){return lv;}
	int getRank(){return rank;}

	void randomEquipment(int lvCap, gameChar ownedChar){		//random setter with known lv and owner
		eqName = "random equipment";
		description = "random equipment";
		eqType = (Random.Range(0,gameChar.wearingNum));
		owner = ownedChar;
		lv = lvCap;
		int randNum = Random.Range(0,100);		// rand a number and distribute percentage
		if(randNum < 20) rank = 1;
		else if(randNum < 60) rank = 2;
		else if(randNum < 90) rank = 3;
		else rank = 4;
		for(int i=0;i<rank;i++){
			attribute attr = Random.Range(0,5);
			float attrVal = (rand()%10 + 1) * lv;
			attributePair[i] = Pair<attribute, float>(attr, attrVal);
		}
	}

	bool setOwner(gameChar ch){	//change owner
		owner = ch;
		return true;
	}

	void printEq(){
		/*
		cout << "Equipment Type: " << eqTypeStr[eqType] << endl;
		cout << "Name: " << eqName << endl;
		cout << "Rank: " << rank << endl;
		cout << "Description: " << description << endl;
		//cout << "+" << effectingVal  << " " << gameChar::attrStr[(int)attribute] << endl;
		for(int i=0;i<rank;i++){
			cout << "+" << attributePair[i].second << " " << gameChar::attrStr[(int)attributePair[i].first] << endl;
		}
		cout << "can be equiped after lv" << lv << endl;
		*/
	}

	bool equipChar(gameChar equiped){
		for(int i=0;i<rank;i++){		//for each rank, set the owner's attribute
			float effectingVal = attributePair[i].second;
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

	bool unEquipChar(gameChar equiped){
		for(int i=0;i< rank;i++){		//for each rank, unset owner's attribute
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

	bool isNull(){		//function to check if the equipment is empty
		if(eqName=="" && description == "" && lv == 1 && rank == 1) return true;
		return false;
	}

	public override bool Equals(object equip){
		equipment eq = (equipment)equip;
		return (this.eqName == eq.eqName &&
		this.eqtype == eq.eqtype &&
		this.owner == eq.owner &&
		this.lv == eq.lv &&
		this.rank == eq.rank &&
		this.attributePair == eq.attributePair &&
		this.description == eq.description);
	}

	public static bool operator != (equipment eq1, equipment eq2){
		return !eq1.Equals (eq2);
	}

	public static bool operator == (equipment eq1, equipment eq2){
		return eq1.Equals(eq2);
	}

}
