#include "arc.cpp"
#include "adjustB.cpp"
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
void moveTopoint(double x, double y, double z, bool fromLeft);
int main(int argc, char *argv[]){
  if(argc <5){
    cout<<"Not Enough argument, try agian"<<endl;
    return 0;
  }
  
  //I have enough argument branch
  double x = atoi(argv[1]);
  double y = atoi(argv[2]);
  double z = atoi(argv[3]);
  bool Left = atoi(argv[4]);

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

  //final position recorded
  int diffB = abs(B-iniB);
  int iniBsmol = (iniB-B)>0?1:-1;
  int diffC = abs(C-iniC);
  int iniCsmol = (iniC-C)>0?1:-1;

  int iniAsmol = (iniA-A)>0?1:-1;
  int diffA = abs(A-iniA);

  bool ValidOrNot;
  int ServoA = A+83;
  int ServoB = B+10;
  int ServoC = C;

  //prepare file to be send to arduino
  ofstream Commands;
  Commands.open("Commands.txt");
  
  //check if position reachable
  if(y>0&& ServoA>22&&ServoA<144&& ServoC>25&&ServoC<170&& ServoB>0&&ServoB<191-C){
  }
  else{
    /*branch not reachable position, tell arduino not to operate*/
    //write to file
    Commands<<"Bad position"<<endl;
    return;
  }

  /*branch reachable*/
  //note to self
  cout<<"Destination: "<<A+83<<" a "<<B+10<<" b "<<C<<" c"<<endl;

  //select mode for A operation
  if(fromLeft){
    iniA = iniA-59;
    diffA = abs(A-iniA);
    iniAsmol = (iniA-A)>0?1:-1;
    for(int i = 0;i<60;i++){
      //write to file
      Commands<<83-i<<" a "<<endl;
    }
  }
  else{
    iniA = iniA+59;
    diffA = abs(A-iniA);
    iniAsmol = (iniA-A)>0?1:-1;
    for(int i =0;i<60;i++){
      //write to file
      Commands<<83+i<<" a "<<endl;
    }
  }

  
  for(int i=0;i<=diffC;i++){
    //write to file
    Commands<<iniC-(i*iniCsmol)<<" c "<<endl;
  }
  for(int i=0;i<=diffB;i++){
    //write to file
    Commands<<iniB-(i*iniBsmol)+10<<" b "<<endl;
  }
  for(int i=0;i<=diffA;i++){
    //write to file
    Commands<<iniA-(i*iniAsmol)+83<<" a "<<endl;
  }
  Commands.close();
}
