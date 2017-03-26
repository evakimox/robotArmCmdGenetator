#include "arc.cpp"
#include "adjustB.cpp"

int main(){
  double x;
  double y;
  double z;
  cin>>x>>y>>z;
  int A = 70;
  int B = 44;
  int C = 100;

  adjustABC(x,y,z,A,B,C);

  cout<<"finalA: "<<A<<" finalB: "<<B<<" finalC: "<<C<<endl;
  
  return 0;
}
