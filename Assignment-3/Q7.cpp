#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
        int mini;
        vector<int> arr;
    public:
        Solution() {
            mini = INT_MAX;
        }
        void push(int x) {
            if (arr.empty()){
                arr.push_back(x);
                mini = x;
            }
            else if (x >= mini)arr.push_back(x);
            else{
                arr.push_back(2 * x - mini);
                mini = x;
            }
        }
        void pop() {
            if (arr.empty()) return;
            int top = arr.back();
            if (top < mini)mini = 2 * mini - top;
            arr.pop_back();
            if (arr.empty())mini = INT_MAX; 
        }
        int peek() {
            if (arr.empty()) return -1; 
            int top = arr.back();
            if (top < mini) return mini;
            else return top;
        }
        int getMin() {
            if (arr.empty()) return -1;
            return mini;
        }
};
int main(){


}