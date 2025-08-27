#include <iostream>
#include <stack>
#include <string>
using namespace std;
int priority(char s){
    if(s == '+' || s == '-') return 1;
    if(s == '*' || s == '/') return 2;
    if(s == '^') return 3;
    return 0;
}
int main(){
    // infix to postfix
    string str;cin >> str;
    int n = str.size();
    stack<char> s; 
    string ans = "";
    for(int i = 0; i < n; i++){
        if((str[i] >= '0' && str[i] <= '9'))ans += str[i];
        else if(str[i] == '(')s.push(str[i]);
        else if(str[i] == ')'){
            while(s.top() != '('){
                ans += s.top(); 
                s.pop();
            }
            s.pop();
        }
        else if(s.empty())s.push(str[i]);
        else{
            while(!s.empty() && priority(s.top()) >= priority(str[i])){
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans << endl;
}
