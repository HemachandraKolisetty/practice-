#include <iostream>
#include <vector>
#include <string>

using namespace std;

void split(string s,char d,vector<string>& S){
    for(int i=0;i<s.length();i++){
        string temp="";
        for(int j=i;j<s.length();j++){
            if(s[j]==d){
                for(;i<j;i++) temp+=s[i];
                S.push_back(temp);
                break;
            }
            if(j==s.length()-1){
                for(;i<=j;i++) temp+=s[i];
                S.push_back(temp);
                break;
            }
        }
    }
} 

int main() {
    int t; cin>>t;
    for(int i=0;i<t;i++){
        string s; cin>>s;
        char delimiter='.';
        vector<string> S;
        split(s,delimiter,S);
        for(int j=S.size()-1;j>0;j--) cout<<S[j]<<".";
        cout<<S[0]<<endl;
    }
    return 0;
}