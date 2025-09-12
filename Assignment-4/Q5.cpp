#include<iostream>
#include<queue>
using namespace std;
class s1{
private:
    queue<int> q1;
    queue<int> q2;
public:
    s1() {}
    void push(int v){
        q1.push(v);
    }
    bool isEmpty(){
        return (q1.empty() && q2.empty());
    }
    void pop(){
        if(isEmpty()){
            cout << "empty\n";
            return;
        }
        int n = q1.size();
        for (int i = 0; i < n - 1; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << "\n";
        q1.pop();
        q1 = q2;
        while (!q2.empty()) q2.pop(); 
    }
    void peek(){
        if (isEmpty()) {
            cout << "empty\n";
            return;
        }
        int n = q1.size();  
        for (int i = 0; i < n - 1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        cout << q1.front() << "\n";
        q2.push(q1.front());
        q1.pop();
        q1 = q2;
        while (!q2.empty()) q2.pop(); 
    }
};
class s2 {
    private:
        queue<int> q;
    public:
        s2() {}
        bool isEmpty() {
            return q.empty();
        }
        void push(int v) {
            q.push(v);
            int n = q.size();
            for (int i = 0; i < n - 1; i++) {
                q.push(q.front());
                q.pop();
            }
        }
        void pop() {
            if (isEmpty()) {
                cout << "empty\n";
                return;
            }
            cout << q.front() << "\n";
            q.pop();
        }
        void peek() {
            if (isEmpty()) {
                cout << "empty\n";
                return;
            }
            cout << q.front() << "\n";
        }
};
int main(){
    s1 st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.peek();
    st.pop();  
    st.peek(); 
    st.pop();  
    st.pop();  
    st.pop();  
}
