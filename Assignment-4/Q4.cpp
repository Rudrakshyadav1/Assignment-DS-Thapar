#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<char> q;
    string str = "aabc";
    int freq[26] = {0};
    for(int i = 0; i < str.size(); i++){
        freq[str[i] - 'a']++;
        q.push(str[i]);
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }
        if(q.empty())cout << -1 << endl;
        else cout << q.front() << endl;
    }
}
