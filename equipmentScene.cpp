//
//  equipmentScene.cpp
//  gameStruct
//
//  Created by Wilson Leung on 3/8/2017.
//  Copyright © 2017年 Wilson Leung. All rights reserved.
//

#include "equipmentScene.hpp"
void equipmentScene::equipmentFunction(career &myChar){
	//char userInput = 'x';		//get userInput
	string userInput = "";
	int userInputNum = -1;	//input integer for equipment id
	
	while(userInput.compare("exit")!=0){	//main loop
		myChar.printStat();
		cout << endl;
		equipment* ownedArr = myChar.getOwnedArr();		//get owned and wearing list from character
		equipment* wearing = myChar.getWearingArr();
		cout << "wearing: " << endl;
		for(int i=0;i<myChar.wearingNum;i++){			// print equipments from wearing and then owned list
			cout << i << ": ";
			cout << "type:" << equipment::eqTypeStr[i];	// type of the slot
			if(!wearing[i].isNull()){					// if have equipment, print the eq details
				cout << ", name:" << wearing[i].getEqName() << ", rank:" << wearing[i].getRank() << endl;
			}
			cout << endl;
		}
		cout << "owned: " << endl;
		for(int i=0;i<myChar.ownedNum;i++){
			cout << i+myChar.wearingNum << ": ";
			if(!ownedArr[i].isNull()){
				cout << "type:" << equipment::eqTypeStr[ownedArr[i].getEqType()];
				cout << ", name:" << wearing[i].getEqName() << ", rank:" << ownedArr[i].getRank() << endl;
			}
			cout << endl;
		}
		
		do{			//do while loop of checking userInput, break the loop if user inputed 'exit' or number between 0 and wearingNum+ownedNum
			cout << "Enter the equipment number for detail or enter 'exit' and back to menu: ";
			cin >> userInput;
			if(userInput.compare("exit")!=0)
				userInputNum = stoi(userInput);
		}
		while(userInput.compare("exit")!=0 && (userInputNum < 0 || userInputNum > (myChar.wearingNum+myChar.ownedNum)) );
		
		if(userInput.compare("exit")==0){		//user entered "exit"
			break;
		}
		
		else{		//user entered number between 0 and wearingNum+ownedNum
			if(userInputNum < myChar.wearingNum && !wearing[userInputNum].isNull()){	//wearing equipment id
				wearing[userInputNum].printEq();
				char eqInput = 'x';
				do{
					cout << "what do you want to do? " << endl;
					cout << "a. unequip equipment" << endl;
					cout << "b. drop equipment" << endl;
					cout << "c. browse other equipment" << endl;
					cin >> eqInput;
				}
				while(eqInput!='a' && eqInput!='b' && eqInput !='c');
				if(eqInput == 'a'){
					wearing[userInputNum].unEquipChar(myChar);
					myChar.addEquipment(wearing[userInputNum]);
					wearing[userInputNum] = equipment();
				}
				else if(eqInput == 'b'){
					wearing[userInputNum].unEquipChar(myChar);
					wearing[userInputNum] = equipment();
				}
				else if(eqInput == 'c'){
					
				}
			}
			
			else if(userInputNum < (myChar.wearingNum+myChar.ownedNum) && !ownedArr[userInputNum - myChar.wearingNum].isNull()){	//owned equipment id
				int index = userInputNum - myChar.wearingNum;
				ownedArr[index].printEq();
				char eqInput = 'x';
				do{
					cout << "what do you want to do? " << endl;
					cout << "a. equip equipment" << endl;
					cout << "b. drop equipment" << endl;
					cout << "c. browse other equipment" << endl;
					cin >> eqInput;
				}
				while(eqInput!='a' && eqInput!='b' && eqInput !='c');
				if(eqInput == 'a'){
					myChar.changeEquipment(ownedArr[index]);
					ownedArr[index] = equipment();
				}
				else if(eqInput == 'b'){
					ownedArr[userInputNum] = equipment();
				}
				else if(eqInput == 'c'){
					
				}
			}
			else{	//no equipment in the slot
				cout << "no equipment in this slot" << endl;
			}
		}
	}
}
