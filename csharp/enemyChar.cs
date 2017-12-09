using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class enemyChar : gameChar {

	protected float expContain;
	protected equipment eq;
	protected skill[] skillArr;

	enemyChar(){
		expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
		eq = equipment();
		eq.randomEquipment(1, *this);
	}

	public float getExpContain(){ return expContain; }
	void setExpContain(){ expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4; }

	new void printStat(){
		/*
		std::cout << "Enemy character value: " << endl;
		gameChar::printStat();
		std::cout << " exp: " << expContain << endl;
		cout << endl;
		*/
	}

	void printEq(){
		//eq.printEq();
	}

	new string getType(){ return "enemyChar";}

	equipment getEquipment(){return eq;}

	void randChar(string enemyName,int lv){
		gameChar::randChar(lv);
		expContain = maxHP * 0.5 + maxMP * 0.1 + attack * 4 + defense * 4;
		eq.randomEquipment(lv, *this);
		setName(enemyName);
		setExpContain();
	}

}

