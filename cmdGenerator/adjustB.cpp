#include "sinNcos.cpp"
#include <cmath>

bool adjustB(double z,int &B, int C){
  int initialB = B;
  double prevdiff = 999;

  int Bchange = -2;
  double initialHeight = 12.3*sinof(C) - 14*sinof(B);
  if(initialHeight>=z){
    Bchange = 2;
  }
  
  for(int i = 0;i<300;i++){
    double currentHeight = 12.3*sinof(C) - 14*sinof(B);    
    double difference = abs(currentHeight-z);

    B = B+Bchange;
    
    if(prevdiff<difference){      
      B=B-2*Bchange;
      cout<<"initialB "<<initialB<<" final B "<<B<<endl;
      return (abs(initialB-B)>10)?1:0;
    }
    prevdiff = difference;
  }
}



bool adjustC(double x, double y,int B, int &C){
  int initialC = C;
  double prevdiff = 9999999999;

  cout<<"specified x: "<<x<<" specified y: "<<y<<endl;
  double xsq = x*x;
  double ysq = y*y;
  double horizontal_length_sq = xsq+ysq;
  
  int Cchange = -2;
  double initialDistance = 12.3*cosof(C) + 14*cosof(B);
  double initialDistance_sq = initialDistance*initialDistance; 
  
  if(initialDistance_sq>=horizontal_length_sq){
    Cchange = +2;
  }
  
  for(int i=0;i<300;i++) {
    double currentDistance = 12.3*cosof(C) + 14*cosof(B);
    double currentDistance_sq = currentDistance*currentDistance;
    double difference = abs(currentDistance_sq - horizontal_length_sq);

    cout<<"CurrentDistance square is: "<<currentDistance_sq<<"\nCurrent distance is: "<<difference<<endl;
    cout<<"C is now: "<<C<<endl;

    C = C+Cchange;
    
    if(prevdiff<=difference){      
      C=C-2*Cchange;
      cout<<"initialC "<<initialC<<" final C "<<C<<endl;
      return (abs(initialC-C)>10)?1:0;
    }
    prevdiff = difference;
  }
}


