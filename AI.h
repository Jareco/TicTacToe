#include <vector>
#include <iostream>
using namespace std;
class AI{
 private:
  struct Move{
	int i;
	int d; 
	int score;
	Move(){}
	Move(int score){
		this->score=score;
	}

   };
	const char computer='C';
	const char player='P';
	const char tie='T';
	Playfield *f;


 public:
 
	 AI(Playfield&  f){
		 this->f=&f;
	 }
	
	 void play(){
		 
		 Move bestMove=findMove(0);
		 f->setNumber(bestMove.i, bestMove.d, 0);
		 
	 }
	
	 Move findMove(int index){
		 bool wictory=f->checkWin();
		 char winner=f->getWinner();
		 //Break condition
		 if(computer==winner){
			return Move(10);	
		 }else if(winner==player){
			 return Move(-10);
		 }else if(winner==tie){
			 return Move(0);
		 }
		

	     //Recursion. Put moves in the vector
             std::vector<Move> moves;
	        for(int i=0; i<3; i++){
		    for(int d=0; d<3; d++){
			    if(f->getNumber(i,d)==2){
				    Move move;
				    move.i=i;
				    move.d=d;
				    f->setNumber(i,d, index);
				    if(index==0){
					    move.score=findMove(1).score;
				    }else{
					    move.score=findMove(0).score;
				    }
  
				    moves.push_back(move);
  
				    f->setNumber(i,d,2);
			    }
		    }
	    } 


	    //The best move 
    	    int bestmove=0;	    
	    if(index==0){
		    int bestScore=-1000000;
		    for(int i=0; i<moves.size(); i++){
			    if(moves[i].score>bestScore){
				    bestmove=i;
				    bestScore=moves[i].score;
			    }
		    }

	    }else{
		    int bestScore=1000000;
		    for(int i=0; i<moves.size(); i++){
			    if(moves[i].score<bestScore){
				    bestmove=i;
				    bestScore=moves[i].score;
			    }
		    }

	    }

	    return moves[bestmove];
	 }


 



};
