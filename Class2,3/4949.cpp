#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main(){
    while(1){
        int i=0;
        bool state = true;
        stack<char> s;
        string str;
        getline(cin,str);
        if(str=="." && str.length()==1) break;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                s.push('(');
            }
            else if(str[i]=='['){
                s.push('[');
            }
            else if(str[i]==')'){
                if(!s.empty() &&s.top() =='('){
                    s.pop();
                }
                else {
                    state = false;
                }
            }
            else if(str[i]==']'){
                if(!s.empty() &&s.top() =='['){
                    s.pop();
                }
                else {
                    state = false;
                }
            }
        }
        if(s.empty()&&state){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}
