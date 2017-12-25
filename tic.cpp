#include<iostream>
#include<string>
#include "Playfield.h"
#include "AI.h"
using namespace std;
int main(){
   int pos;
   int number;
   bool win=false;
   Playfield f;
   char choice;
   cout << "You should choose the position, where you can set you answer." << endl;
   cout << "Play with number 1 or 0." << endl;
   cout << "Play against computer: 'c' or play against player: 'p'" << endl;
   cout << "Player or Computer: ";
   cin >> choice; 
   
   
   if(choice=='p'){
  
      do{
      win=f.checkWin();
      if(win==true){
	     f.print();
	     cout << "You won!" << endl;
	     break;
      }
      if(f.checkTie()){
	      f.print();
	      cout << "Tie!" << endl;
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
     
   }else{
      cout << "Use only 1 for playing with computer." << endl;
      AI cplayer(f);
      int indexplayer=0;
    
      do{
    
      win=f.checkWin();
      if(win==true){
	     f.print();
	     cout << "Win!" << endl;
	     break;
      }
      
      
      if(indexplayer%2==0){
        f.print();
        cout << "Position: ";
        cin >>pos;
        cout << "Choice: ";
        cin >> number;
        f.setAnswer(pos, number);
        indexplayer++;
        win=f.checkWin();
	if(win==true){
	     f.print();
	     cout << "Win!" << endl;
	     break;
        }
        if(f.checkTie()){
	      f.print();
	      cout << "Tie!" << endl;
	      break;
        }
      }else{
        cplayer.play();
        indexplayer++;
	if(win==true){
	     f.print();
	     cout << "Win!" << endl;
	     break;
        }
		
      }
      
      }while(true);
  
   }
  
  
	return 0;
}
