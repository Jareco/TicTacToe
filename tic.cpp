#include<iostream>
#include<string>
#include "Playfield.h"
#include "Computerplayer.h"
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
   cin >> choice; 
   
   
   if(choice=='p'){
  
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
     
   }else{
      Computerplayer cplayer(f);
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
      }else{
        cplayer.playHorizontal();
        indexplayer++;
      }
      
      }while(true);
  
   }
  
  
	return 0;
}
