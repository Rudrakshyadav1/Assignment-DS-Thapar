#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    stack<char> s;
    string str;cin >> str;
    for (char c : str){
        if (c == '('){
            s.push(c);
        }
        else if (c == ')'){
            if (s.empty()){
                cout << "NO\n";
                return 0;
            }
            s.pop();
        }
    }
    cout << (s.empty()?"YES\n":"NO\n");
}
