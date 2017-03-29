#include "arc.cpp"
#include "adjustB.cpp"
#include <unistd.h>
void moveTopoint(double x, double y, double z, bool fromLeft);
int main(){
  double x;
  double y;
  double z;
  bool Left;
  cin>>x>>y>>z>>left;

  moveTopoint(x,y,z,Left);
  return 0;
}

void moveTopoint(double x, double y, double z, bool fromLeft){
  //Initial Positions
  int iniA = 0;
  int iniB = 0;
  int iniC = 140;
  
  int A = iniA;
  int B = iniB;
  int C = iniC;
  adjustABC(x,y,z,A,B,C);

  int diffB = abs(B-iniB);
  int iniBsmol = (iniB-B)>0?1:-1;
  int diffC = abs(C-iniC);
  int iniCsmol = (iniC-C)>0?1:-1;

  int iniAsmol = (iniA-A)>0?1:-1;
  int diffA = abs(A-iniA);

  bool ValidOrNot;
    
  cout<<"Destination: "<<A+83<<" a "<<B+10<<" b "<<C<<" c\n"<<endl;

  //select mode for A operation
  if(fromLeft){
    iniA = iniA-59;
    diffA = abs(A-iniA);
    iniAsmol = (iniA-A)>0?1:-1;
    for(int i = 0;i<60;i++){
      cout<<83-i<<" a "<<endl;
    }
  }
  else{
    iniA = iniA+59;
    diffA = abs(A-iniA);
    iniAsmol = (iniA-A)>0?1:-1;
    for(int i =0;i<60;i++){
      cout<<83+i<<" a "<<endl;
    }
  }

  
  for(int i=0;i<=diffC;i++){
    //cout<<A+83<<" a "<<iniB+10<<" b "<<iniC-(i*iniCsmol)<<" c "<<endl;
    cout<<iniC-(i*iniCsmol)<<" c "<<endl;
    usleep(30000);
  }
  for(int i=0;i<=diffB;i++){
    //cout<<A+83<<" a "<<iniB-(i*iniBsmol)+10<<" b "<<C<<" c "<<endl;
    cout<<iniB-(i*iniBsmol)+10<<" b "<<endl;
    usleep(30000);
  }
  for(int i=0;i<=diffA;i++){
    cout<<iniA-(i*iniAsmol)+83<<" a "<<endl;
    usleep(30000);
  }
}
