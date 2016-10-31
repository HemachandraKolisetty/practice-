//Parenthesis checker
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		stack<char> mystack;
		for(int j=0;j<s.length();j++){
			if(mystack.empty()){
				if(s[j]=='}' || s[j]==']' || s[j]==')') break;
				else mystack.push(s[j]);
			}
			else{
				if((s[j]=='}' && mystack.top()=='{') || (s[j]==']' && mystack.top()=='[')
					|| (s[j]==')' && mystack.top()=='(')) mystack.pop();
				else mystack.push(s[j]);
			}
		}
		if(mystack.empty()) cout<<"balanced"<<endl;
		else cout<<"not balanced"<<endl;
	}
}