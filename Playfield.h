#include<iostream>
#include<string>
using namespace std;

class Playfield{
 private:
  int playfield[3][3];

 
 public:
  Playfield(){
	  for(int i=0; i<3; i++){
		  for(int d=0; d<3; d++){
			  playfield[i][d]=2;
		  }
	  }  
	 
  }

  void setAnswer(int pos, int number){
	switch (pos) {
        case 11: playfield[0][0]=number; 
		 break;
        case 12: playfield[0][1]=number; 
		 break;
        case 13: playfield[0][2]=number; 
		 break;
        case 21: playfield[1][0]=number; 
	   	 break;
        case 22: playfield[1][1]=number;
		 break;

        case 23: playfield[1][2]=number;
		 break;

        case 31: playfield[2][0]=number; 
		 break;

        case 32: playfield[2][1]=number; 
		 break;

        case 33: playfield[2][2]=number; 
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
		  if(counter_0==3) return true;
		  if(counter_1==3) return true;
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
		  if(counter_0==3) return true;
		  if(counter_1==3) return true;
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
	  if(counter_0==3) return true;
	  if(counter_1==3) return true;
	  counter_0=0;
	  counter_1=0;

	  //Cross Right-Left
	  int columnindex=2;  //column
	  for(int i=0; i<3; i++){  //Row
		  if(playfield[i][columnindex]==0) counter_0++;
		  if(playfield[i][columnindex]==1) counter_1++;
		  columnindex--;
	  }
	  if(counter_0==3) return true;
	  if(counter_1==3) return true;

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




};
