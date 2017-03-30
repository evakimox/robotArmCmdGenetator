#include "arc.cpp"
#include "adjustB.cpp"
#include <unistd.h>
#include <fstream>
#include <stdlib.h>
void unlatching(double x, double y, double z);
int main(int argc, char *argv[]){
  /*
  if(argc <5){
    cout<<"Not Enough argument, try agian"<<endl;
    return 0;
  }
  */
  
  //I have enough argument branch
  double x = atoi(argv[1]);
  double y = atoi(argv[2]);
  double z = atoi(argv[3]);
  unlatching(x,y,z);
  return 0;
}

void unlatching(double x, double y, double z){
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
  Commands.open("Commands_unlatch.txt");
  
  //check if position reachable
  if(y>0&& ServoA>22&&ServoA<144&& ServoC>25&&ServoC<170&& ServoB>0&&ServoB<191-C){
  }
  Commands<<B+45<<" b"<<endl;
  Commands.close();
}
