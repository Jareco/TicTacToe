#include<iostream>
#include<string>
using namespace std;

class Playfield{
 private:
  int playfield[3][3];
  char winner;

 
 public:
  Playfield(){
	  for(int i=0; i<3; i++){
		  for(int d=0; d<3; d++){
			  playfield[i][d]=2;
		  }
	  }  

	  winner='N';
	 
  }

  void setNumber(int i, int d, int number){
	playfield[i][d]=number;
  }

  int getNumber(int i, int d){
	  return playfield[i][d];
  }

  void setAnswer(int pos, int number){
	switch (pos) {
        case 11: if(playfield[0][0]==2) 
		 playfield[0][0]=number; 
		 break;
        case 12: if(playfield[0][1]==2)
		 playfield[0][1]=number; 
		 break;
        case 13: if(playfield[0][2]==2)
		 playfield[0][2]=number; 
		 break;
        case 21: if(playfield[1][0]==2)
		 playfield[1][0]=number; 
	   	 break;
        case 22: if(playfield[1][1]==2)
		 playfield[1][1]=number;
		 break;

        case 23: if(playfield[1][2]==2)
		 playfield[1][2]=number;
		 break;

        case 31: if(playfield[2][0]==2)
		 playfield[2][0]=number; 
		 break;

        case 32: if(playfield[2][1]==2)
		 playfield[2][1]=number; 
		 break;

        case 33: if(playfield[2][2]==2)
		 playfield[2][2]=number; 
		 break;
        default: cout << "Wrong position"<<endl;  
    }

  }

  void print(){
	  cout << "     1." << "2." << "3." << endl;
	  cout << endl;
	  for(int i=0; i<3; i++){  // Row
		  cout << (i+1)<<"    ";
		  for(int d=0; d<3; d++){ // Column
			  if(playfield[i][d]!=0 && playfield[i][d]!=1)
				  cout << "*" << " ";
			  else
			  	  cout<< playfield[i][d]<<" ";
		  }

		cout << endl;
	  }
  
  }	

  bool checkWinHorizontal(){
	int counter_0=0;    //counter for answer 0
	int counter_1=0;    //counter for answer 1
	for(int i=0; i<3; i++){
		  for(int d=0; d<3; d++){
			  if(playfield[i][d]==0)
			  	counter_0++;
			  if(playfield[i][d]==1)
				counter_1++;
		  }
		  if(counter_0==3){
			  winner='C';
			  return true;
		  } 
		  if(counter_1==3){
			  winner='P';
			  return true;
		  } 
		  counter_0=0;
		  counter_1=0;
	  }
	 
	  return false;

  }

  bool chekWinVertical(){
	int counter_0=0;
	int counter_1=0;
	for(int i=0; i<3; i++){  // Column
		  for(int d=0; d<3; d++){   // Row
			  if(playfield[d][i]==0)
			  	counter_0++;
			  if(playfield[d][i]==1)
				counter_1++;
		  }
		  if(counter_0==3){
			  winner='C';
			  return true;
		  } 
		  if(counter_1==3){
			  winner='P';
			  return true;
		  } 
		  counter_0=0;
		  counter_1=0;
	  }
	 


	 	  return false;



  }

  bool checkWinCross(){
	  //Cross Left-Right
	  int counter_0=0;
	  int counter_1=0;
	  for(int i=0; i<3; i++){
		 if(playfield[i][i]==0) counter_0++; 
		 if(playfield[i][i]==1) counter_1++;
	  }
		  if(counter_0==3){
			  winner='C';
			  return true;
		  } 
		  if(counter_1==3){
			  winner='P';
			  return true;
		  }
	  counter_0=0;
	  counter_1=0;

	  //Cross Right-Left
	  int columnindex=2;  //column
	  for(int i=0; i<3; i++){  //Row
		  if(playfield[i][columnindex]==0) counter_0++;
		  if(playfield[i][columnindex]==1) counter_1++;
		  columnindex--;
	  }
		  if(counter_0==3){
			  winner='C';
			  return true;
		  } 
		  if(counter_1==3){
			  winner='P';
			  return true;
		  }

	  return false;

  }


  bool checkWin(){
	  bool winresult=false;
	  winresult=checkWinHorizontal();
	  if(winresult) return winresult;
	  winresult=chekWinVertical();
	  if(winresult) return winresult;
	  winresult=checkWinCross();
	  if(winresult) return winresult;

	  return winresult;
  }

  bool checkTie(){
	  bool winResult=checkWin();
	  if(winResult) return false;
	  int counter=0; 
	  for(int i=0; i<3; i++){
		  for(int d=0; d<3; d++){
			  if(playfield[i][d]!=2) counter++;
		  }
	  }
	  if(counter==9) return true;


	return false;	
  }

  char getWinner(){
	  if(checkTie()) winner='T';
	  char returnwinner=winner;
	  winner='N';
	  return returnwinner;
  }




};

