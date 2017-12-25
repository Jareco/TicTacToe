class Computerplayer{
 private:

	Playfield *f;


 public:
 
	 Computerplayer(Playfield&  f){
		 this->f=&f;
	 }
	

 void playHorizontal(){
	int stepcounter=0;
	//1 Row
	int counter_1=0;    //counter for answer 1
	for(int i=0; i<3; i++){
		if(f->getNumber(0,i)==1) counter_1++;
	  }

	if(counter_1>=1){
		
		for(int i=0; i<3; i++){
			if(f->getNumber(0,i)!=1 && f->getNumber(0,i)!=0){
				f->setNumber(0,i,0);
				stepcounter++;
				break;
			}
		}
		if(stepcounter>0) return;
	}
	counter_1=0;

	//2 Row
	for(int i=0; i<3; i++){
		if(f->getNumber(1,i)==1) counter_1++;
	  }

	if(counter_1>=1){
		for(int i=0; i<3; i++){
			if(f->getNumber(1,i)!=1 && f->getNumber(1,i)!=0){
				f->setNumber(1,i,0);
				stepcounter++;
				break;
			}
		}
		if(stepcounter>0) return;
	}
	counter_1=0;


	//3 Row
	for(int i=0; i<3; i++){
		if(f->getNumber(2,i)==1) counter_1++;
	  }

	if(counter_1>=1){
		for(int i=0; i<3; i++){
			if(f->getNumber(2,i)!=1 && f->getNumber(2,i)!=0){
				f->setNumber(2,i,0);
				stepcounter++;
				break;

			}
		}
		if(stepcounter>0) return;
	}
	counter_1=0;

 }



};
