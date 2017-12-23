#include<iostream>
#include<string>
using namespace std;

class Playfield{
 private:
  int line1[3];
  int line2[3];
  int line3[3];

 
 public:
  Playfield(){
	  
	  for(int i=0; i<3; i++){
		  line1[i]=2;
	  }
	  
	  for(int i=0; i<3; i++){
		  line2[i]=2;
	  }
	  
	  for(int i=0; i<3; i++){
		  line3[i]=2;
	  }

  }

  void setAnswer(int pos, int number){
	switch (pos) {
        case 11: line1[0]=number; 
		 break;
        case 12: line1[1]=number; 
		 break;
        case 13: line1[2]=number; 
		 break;
        case 21: line2[0]=number; 
	   	 break;
        case 22: line2[1]=number;
		 break;

        case 23: line2[2]=number;
		 break;

        case 31: line3[0]=number; 
		 break;

        case 32: line3[1]=number; 
		 break;

        case 33: line3[2]=number; 
		 break;
        default: cout << "Wrong position"<<endl;  
    }

  }

  void print(){
	  cout << "     1." << "2." << "3." << endl;
	  cout << endl;
	  cout << "1.   ";
	  for(int i=0; i<3; i++){
		  cout << line1[i]<< " ";
	  }
	  cout << endl;
	  
	  cout << "2.   ";
	  for(int i=0; i<3; i++){
		  cout << line2[i]<< " ";
	  }
	  cout << endl;
	  
	  cout << "3.   ";
	  for(int i=0; i<3; i++){
		  cout << line3[i]<< " ";
	  }
	  cout << endl;
  }

  bool checkWinHorizontal(){
	  //1 Line
	  int counter=0;
	  for(int i=0; i<3; i++){
		if(line1[i]==0)
			counter++;
	  }
	  if(counter==3) return true;
	  counter=0;

	 //1 Line.
	  for(int i=0; i<3; i++){
		if(line1[i]==1)
			counter++;
	  }
	  if(counter==3) return true;
	  counter=0;
	 
	  //2 Line
	  for(int i=0; i<3; i++){
		if(line2[i]==0)
			counter++;
	  }
	  if(counter==3) return true;
	  counter=0;

	 //2 Line 
	  for(int i=0; i<3; i++){
		if(line2[i]==1)
			counter++;
	  }
	  if(counter==3) return true;
	  counter=0;
	 
	  //3 Line
	  for(int i=0; i<3; i++){
		if(line3[i]==0)
			counter++;
	  }
	  if(counter==3) return true;
	  counter=0;

	 //3 Line
	  for(int i=0; i<3; i++){
		if(line3[i]==1)
			counter++;
	  }
	  if(counter==3) return true;
	  counter=0;


	  return false;

  }

  bool chekWinVertical(){

	  int counter=0;
	  
	  //0  vertical
	  if(line1[0]==0) counter++;
	  if(line2[0]==0) counter++;
	  if(line3[0]==0) counter++;
	  if(counter==3) return true;
	  counter=0;
	  
	  if(line1[1]==0) counter++;
	  if(line2[1]==0) counter++;
	  if(line3[1]==0) counter++;
	  if(counter==3) return true;
	  counter=0;

	  if(line1[2]==0) counter++;
	  if(line2[2]==0) counter++;
	  if(line3[2]==0) counter++;
	  if(counter==3) return true;
	  counter=0;

	  //1 vertical
	  
	  if(line1[0]==1) counter++;
	  if(line2[0]==1) counter++;
	  if(line3[0]==1) counter++;
	  if(counter==3) return true;
	  counter=0;
	  
	  if(line1[1]==1) counter++;
	  if(line2[1]==1) counter++;
	  if(line3[1]==1) counter++;
	  if(counter==3) return true;
	  counter=0;

	  if(line1[2]==1) counter++;
	  if(line2[2]==1) counter++;
	  if(line3[2]==1) counter++;
	  if(counter==3) return true;
	  counter=0;

	  return false;



  }

  bool checkWinCross(){
	  //0 first situation
	  int counter=0;
	  if(line1[0]==0) counter++;
	  if(line2[1]==0) counter++;
	  if(line3[2]==0) counter++;
	  if(counter==3) return true;
	  counter=0;
	  //1 first situation
	  if(line1[0]==1) counter++;
	  if(line2[1]==1) counter++;
	  if(line3[2]==1) counter++;
	  if(counter==3) return true;
	  counter=0;

	  //0 second situation
	  if(line1[2]==0) counter++;
	  if(line2[1]==0) counter++;
	  if(line3[0]==0) counter++;
	  if(counter==3) return true;
	  counter=0;

	  //1 second situation
	  if(line1[2]==1) counter++;
	  if(line2[1]==1) counter++;
	  if(line3[0]==1) counter++;
	  if(counter==3) return true;
	  counter=0;

	  return false;

  }

  bool checkWin(){
	  bool win=false;
	  win=checkWinHorizontal();
	  if(win) return win;
	  win=chekWinVertical();
	  if(win) return win;
	  win=checkWinCross();
	  if(win) return win;

	  return win;
  }




};

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
	 cout << "You won!" << endl;
	 break;
 }
 f.print();
 cout << "Position: ";
 cin >> pos;
 cout << "Choice: ";
 cin >>number;
 f.setAnswer(pos, number);
 f.print();
 cout << endl;
 }while(true);



	return 0;
}
