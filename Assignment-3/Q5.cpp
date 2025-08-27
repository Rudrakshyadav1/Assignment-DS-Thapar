#include<iostream>
#include<stack> 
using namespace std;
int priority(char s){
    if(s=='+' || s=='-') return 1;
    if(s=='/' || s=='*') return 2;
    if(s=='^')return 3;
    return 0;
}
int main(){
    string str;cin>>str;
    stack<char>s;
    int n=str.size();
    for(int i=0;i<n/2;i++){
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
    for(int i=0;i<n;i++){
        if(str[i]=='(')str[i]=')';
        else if(str[i]==')')str[i]='(';
    }
    string ans="";
    for(int i=0;i<n;i++){
        if( str[i]>='0' && str[i]<='9')ans+=str[i];
        else if(str[i]=='(') s.push(str[i]);
        else if(str[i]==')'){
            while(s.top()!='('){
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && priority(s.top())>priority(str[i])){
                ans+=s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop(); 
    }
    for(int i=0;i<ans.size()/2;i++){
        char temp=ans[i];
        ans[i]=ans[ans.size()-i-1];
        ans[ans.size()-i-1]=temp;
    }
    cout<<ans<<endl;
}
