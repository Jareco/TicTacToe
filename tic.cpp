#include<iostream>
#include<string>
#include "Playfield.h"
using namespace std;
int main(){
 int pos;
 int number;
 bool win=false;
 Playfield f;
 cout << "You should choose the position, where you can set you answer." << endl;
 cout << "Play with number 1 or 0." << endl;
 

 do{
 win=f.checkWin();
 if(win==true){
	 f.print();
	 cout << "You won!" << endl;
	 break;
 }
 f.print();
 cout << "Position: ";
 cin >> pos;
 cout << "Choice: ";
 cin >>number;
 f.setAnswer(pos, number);
 cout << endl;
 }while(true);


	return 0;
}
