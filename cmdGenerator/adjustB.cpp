#include "sinNcos.cpp"
#include <cmath>

bool adjustB(double z,int &B, int C){
  int initialB = B;
  double prevdiff = 999;
  
  for(int i = 0;i<30;i++){
    double currentHeight = 12.3*sinof(C) - 14*sinof(B);
    // cout<<"current Height: "<<currentHeight<<endl;
    // cout<<"current B value:" <<B<<endl<<endl;
    
    double difference = abs(currentHeight-z);
    
    int Bchange = 2;

    B = B+Bchange;
    
    if(prevdiff<difference){      
      B=B-2*Bchange;
      return (abs(initialB-B)>25)?1:0;
    }
    prevdiff = difference;
  }
}

/*
bool adjustC(double z,int B, int &C){
  int initialC = C;
  double prevdiff = 999;
  bool changeDirection = 0;
  
  for(int i = 0;i<30;i++){
    double currentHeight = 12.3*sinof(C) - 14*sinof(B);
    // cout<<"current Height: "<<currentHeight<<endl;
    // cout<<"current B value:" <<B<<endl<<endl;
    
    double difference = abs(currentHeight-z);
    
    int Bchange = 2;

    B = B+Bchange;
    
    if(prevdiff<difference){      
      B=B-2*Bchange;
      return (abs(initialB-B)>25)?1:0;
    }
    prevdiff = difference;
  }
}
    
  
*/
