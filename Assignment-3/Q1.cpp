#include<bits/stdc++.h>
using namespace std;
class Stack{
private: 
    int f;
    int total;
    int* arr;
public:
    Stack(int s){
        f=-1;
        total =s;
        arr=new int[s];
    }
    void push(int  p){
        if(!isFull()){
            f++;
            arr[f]=p;
        }
    }
    void pop(){
        if(!isEmpty()){
            f--;
        }
    }
    bool isEmpty(){
        if(f==-1){
            return 1;
        }
        return 0;
    }
    bool isFull(){
        if(f==total-1){
            return 1;
        }
        return 0;
    }
    void display(){
        for(int i=0;i<=f;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    void peek(){
        cout<<arr[f]<<endl;
    }
};
int main(){
    Stack s(5);
    s.push(1);
    s.pop();
    s.push(2);
    s.display();
}
