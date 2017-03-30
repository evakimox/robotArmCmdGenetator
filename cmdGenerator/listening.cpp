#include "arc.cpp"
#include "adjustB.cpp"
#include <unistd.h>
#include <fstream>
#include <string>
#include <stdlib.h>

void moveTopoint(double x, double y, double z, bool fromLeft);
bool Listener(string filename, string &cmd2, string &cmd3);
int main(){
  while(1){
    sleep(1);
    string cmd2exec = "./toPosition ";
    string cmd3exec = "./unlatch ";
    if(Listener("xyzValue.txt",cmd2exec,cmd3exec)){
      cout<<"string after edition: "<< cmd2exec<<endl;
      int i = 0;
      char c_arr[50];
      char d_arr[50];
      for(i=0;i<cmd2exec.length();i++){
	c_arr[i] = cmd2exec[i];
      }
      for(i=0;i<cmd2exec.length();i++){
	d_arr[i] = cmd3exec[i];
      }
      c_arr[i] = '/0';
      d_arr[i] = '/0';
      system(c_arr);
      system(d_arr);
      cout<<"d_arr "<<d_arr<<endl;
      system("rm xyzValue.txt");
    }
    
  }
  return 0;
}

bool Listener(string filename, string &cmd2exec, string &cmd3exec){
  ifstream xyzvalues(filename);
  if(xyzvalues.is_open()){
    string line;
    while(getline(xyzvalues,line)){
      cout<<line<<endl;
      cmd2exec+=line;
      cmd3exec+=line;
      cmd2exec+=' ';
      cmd3exec+=' ';
    }
    xyzvalues.close();
    return true;
  }

  return false;
}
