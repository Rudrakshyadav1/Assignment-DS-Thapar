#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
    private:
      stack<int> s;
    public:
      vector<int> nextLargerElement(vector<int>& arr){
          int n = arr.size();
          vector<int> ans(n, -1);
          for(int i = 0; i < n; i++){
              if(s.empty()) s.push(i);
              else {
                  while(!s.empty() && arr[s.top()] < arr[i]) {
                      ans[s.top()] = arr[i];
                      s.pop();
                  }
                  s.push(i); 
            }
        }
        return ans;
    }
};
int main(){

}