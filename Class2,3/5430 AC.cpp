/**
 * @file 5430 AC.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>

using namespace std;

int main(){
  int t; cin>>t;
  while(t--){
    deque<int> dq; //list of number
    string str; cin>>str; //command list
    int nsize; cin>>nsize;  //size of list
    string nstr; cin>>nstr; nstr = nstr.substr(1,nstr.size()); //list
    
    if(nsize!=0){
      char sep = ',';
      istringstream iss(nstr);
      string str_buf;
      while(getline(iss, str_buf, sep)){
        dq.push_back(stoi(str_buf));
      }
    }
    bool state=true; //0 - begin , 1 - rbegin
    bool _break = false;
    for(int i=0;i<str.size();i++){
      if(str[i] == 'R'){   //R
        state = !state;
      }
      else{                 //D
        if(dq.size() == 0) {
          cout<<"error\n";
          _break = true;
          break;
        }
        if(state){ //begin
          dq.pop_front();
          nsize--;
        }
        else{      //reverse
          dq.pop_back();
          nsize--;
        }
      }
    }
    //empty list
    if(_break) continue;
    if(nsize==0 && !_break) {
      cout<<"[]\n";
      continue;
    }
    if(state){
      cout<<"[";
      if(nsize>0)
        for(int i=0;i<nsize-1;i++) cout<<dq.at(i)<<",";
      cout<<dq[nsize-1]<<"]\n";
    }
    else{
      cout<<"[";
      if(nsize>0)
        for(int i=nsize-1;i>0;i--) cout<<dq.at(i)<<",";
      cout<<dq[0]<<"]\n";
    }
  }
}