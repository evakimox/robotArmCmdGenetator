#include <iostream>
#include <cmath>

using namespace std;

int arcCos(double cosValue);
int arcSin(double sinValue, bool small);


int arcSin(double sinValue, bool small){
  double listofSinValue[47]={
0.00000	,
0.03490	,
0.06976	,
0.10453	,
0.13917	,
0.17365	,
0.20791	,
0.24192	,
0.27564	,
0.30902	,
0.34202	,
0.37461	,
0.40674	,
0.43837	,
0.46947	,
0.50000	,
0.52992	,
0.55919	,
0.58779	,
0.61566	,
0.64279	,
0.66913	,
0.69466	,
0.71934	,
0.74314	,
0.76604	,
0.78801	,
0.80902	,
0.82904	,
0.84805	,
0.86603	,
0.88295	,
0.89879	,
0.91355	,
0.92718	,
0.93969	,
0.95106	,
0.96126	,
0.97030	,
0.97815	,
0.98481	,
0.99027	,
0.99452	,
0.99756	,
0.99939	,
1.00000 ,
2
  };

  if(sinValue>1||sinValue<-1){
    cout<<"wrong";
    return 999;
  }
  else{
    double difference = 999;
    double prevdiff = 999;
    for(int i = 0; i<47;i++){
      difference = abs(listofSinValue[i]-sinValue);
      if(difference > prevdiff){
	if(small){
	  cout<<"you want small value: "<<endl;
	  return (i-1)*2;
	}
	else if(!small){
	  cout<<"you want big value: "<<endl;
	  return 180-((i-1)*2);
	}
      }
      prevdiff = difference;
    }
  }

    

}//end of arcsine
    





int arcCos(double cosValue){
  double listofCosValue[92] = {
1.00000	,
0.99939	,
0.99756	,
0.99452	,
0.99027	,
0.98481	,
0.97815	,
0.97030	,
0.96126	,
0.95106	,
0.93969	,
0.92718	,
0.91355	,
0.89879	,
0.88295	,
0.86603	,
0.84805	,
0.82904	,
0.80902	,
0.78801	,
0.76604	,
0.74314	,
0.71934	,
0.69466	,
0.66913	,
0.64279	,
0.61566	,
0.58779	,
0.55919	,
0.52992	,
0.50000	,
0.46947	,
0.43837	,
0.40674	,
0.37461	,
0.34202	,
0.30902	,
0.27564	,
0.24192	,
0.20791	,
0.17365	,
0.13917	,
0.10453	,
0.06976	,
0.03490	,
0.00000	,
-0.03490	,
-0.06976	,
-0.10453	,
-0.13917	,
-0.17365	,
-0.20791	,
-0.24192	,
-0.27564	,
-0.30902	,
-0.34202	,
-0.37461	,
-0.40674	,
-0.43837	,
-0.46947	,
-0.50000	,
-0.52992	,
-0.55919	,
-0.58779	,
-0.61566	,
-0.64279	,
-0.66913	,
-0.69466	,
-0.71934	,
-0.74314	,
-0.76604	,
-0.78801	,
-0.80902	,
-0.82904	,
-0.84805	,
-0.86603	,
-0.88295	,
-0.89879	,
-0.91355	,
-0.92718	,
-0.93969	,
-0.95106	,
-0.96126	,
-0.97030	,
-0.97815	,
-0.98481	,
-0.99027	,
-0.99452	,
-0.99756	,
-0.99939	,
-1.00000	,
-2
  };

  // up is int listofCosValue[] 
  if(cosValue>1||cosValue<-1){
    cout<<"wrong";
    return 999;
  }
  else{
    double difference = 999;
    double prevdiff = 999;
    for(int i = 0; i<92;i++){
      difference = abs(listofCosValue[i]-cosValue);
      if(difference > prevdiff){
	return (i-1)*2;
      }
      prevdiff = difference;
    }
  }
}
    
