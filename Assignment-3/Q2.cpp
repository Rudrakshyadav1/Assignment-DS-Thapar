#include<iostream> 
#include<stack>
#include<string>
using namespace std;
int main(){
    //Stack already Implemented in first Question.Hence using stl;
    stack<char>s;
    string str;cin>>str;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<"\n";
}