#include "arc.cpp"
#include "adjustB.cpp"

int main(){
  /* double inputsin;
  cin>>inputsin;
  cout<<arcSin(inputsin,0);
  cout<<'\n';
  return 0;
  */
  int z;
  int C = 90;
  int B = 0;
  cin>>z;
  bool needRevise = adjustB(z,B,C);
  cout<<"your final B is "<< B<<endl;
  cout<<"you need revise:? "<<needRevise<<endl;
}
