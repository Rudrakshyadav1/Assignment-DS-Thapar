#include <iostream>
#include <stack>
using namespace std;
int* prevSmaller(int* A, int n1, int *len1){
    stack<int>s;
    s.push(-1);
    int *arr = new int[n1];
    for(int i = 0; i < n1; i++){
        while(s.top() >= A[i]){
            s.pop();
        }
        arr[i] = s.top();
        s.push(A[i]);
    }
    *len1 = n1;
    return arr;
}
int main(){
    int A[] = {4, 5, 2, 10, 8};
    int n1 = sizeof(A)/sizeof(A[0]);
    int len1;
    int* result = prevSmaller(A, n1, &len1);
    for(int i = 0; i < len1; i++){
        cout << result[i] << " ";
    }
}
