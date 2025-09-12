#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    int n = 6;
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        q.push(p);
    }
    queue<int> fir, sec;
    for(int i = 0; i < (n + 1) / 2; i++){
        fir.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        sec.push(q.front());
        q.pop();
    }
    bool t = 0;
    for(int i = 0; i < n && !fir.empty() && !sec.empty(); i++){
        if(!t){
            cout << fir.front() << endl;
            fir.pop(); 
        }
        else{
            cout << sec.front() << endl;
            sec.pop(); 
        }
        t = abs(t - 1);
    }
    while(!fir.empty()){
        cout << fir.front() << endl;
        fir.pop();
    }
    while(!sec.empty()){
        cout << sec.front() << endl;
        sec.pop();
    }
}
