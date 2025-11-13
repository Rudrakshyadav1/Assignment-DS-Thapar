#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void countingSort(vector<int>& a){
    int n = a.size();
    if (n == 0) return;
    int maxVal = *max_element(a.begin(), a.end());
    vector<int> count(maxVal + 1, 0);
    for (int i = 0; i < n; i++)count[a[i]]++;
    for (int i = 1; i <= maxVal; i++)count[i] += count[i - 1];
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--){ 
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++)a[i] = output[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
