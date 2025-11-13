#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void improvedSelectionSort(vector<ll>& a){
    int n = a.size();
    int start = 0, end = n - 1;
    while (start < end){
        int minIndex = start, maxIndex = start;
        for (int i = start; i <= end; i++){
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }
        swap(a[start], a[minIndex]);
        if (maxIndex == start)maxIndex = minIndex;
        swap(a[end], a[maxIndex]);
        start++;
        end--;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

