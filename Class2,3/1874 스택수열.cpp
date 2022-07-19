#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int *a;

int main(){
	int n,index=1,c_i=0;cin>>n;
	a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	char c[10000000];
	for(int i=0;i<n;i++){
		if(i==0) {
			s.push(1);
			c[c_i++] = '+';
			index++;
			//cout<<"first "<<s.top()<<" "<<c[c_i-1]<<index<<endl;
		}
		if(s.empty()){
			int idx = index;
			for(int j=a[i];j>=idx;j--){
				s.push(index++);
				c[c_i++] = '+';
			}
			//cout<<"bigger "<<s.top()<<" "<<c[c_i-1]<<endl;
			s.pop();
			c[c_i++] = '-';
			//cout<<s.top()<<' '<<c[c_i-1]<<endl;
			continue;
		}
		if(s.top() < a[i]){
			int idx = index;
			for(int j=a[i];j>=idx;j--){
				s.push(index++);
				c[c_i++] = '+';
			}
			//cout<<"bigger "<<s.top()<<" "<<c[c_i-1]<<endl;
			s.pop();
			c[c_i++] = '-';
			//cout<<s.top()<<' '<<c[c_i-1]<<endl;
			continue;
		}
		if(s.top() != a[i]){
			cout<<"NO";
			return 0;
		}
		if(s.top()==a[i]){
			//cout<<"pop top "<<s.top()<<" ";
			s.pop();
			c[c_i++] = '-';
			//cout<<c[c_i-1]<<endl;
		}
	}
	c[c_i] = '0';
	for(int i=0;c[i]!='0';i++){
		cout<<c[i]<<"\n";
	}
}
