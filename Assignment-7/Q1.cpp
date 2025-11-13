#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void merger(vector<ll>& a, int s, int e) {
    int m = s + (e - s) / 2;
    int i = s;
    int j = m + 1;
    vector<ll> temp;
    while (i <= m && j<= e){
        if (a[i] <= a[j])temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while (i <= m) temp.push_back(a[i++]);
    while (j <= e) temp.push_back(a[j++]);
    for (int k = 0; k < temp.size(); k++)a[s + k] = temp[k];
}
void mergeSort(vector<ll>& a, int s, int e){
    if(s >= e) return;
    int m = s + (e - s) / 2;
    mergeSort(a, s, m);
    mergeSort(a, m + 1, e);
    merger(a, s, e);
}
int partition(vector<ll>&a,int s,int e){
    ll i=s-1;
    for(ll j=s;j<e;j++){
        if(a[j]<a[e]){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}
void quickSort(vector<ll>&a,int s,int e){ 
    if(s>=e)return;
    int index=partition(a,s,e);
    quickSort(a,0,index-1);
    quickSort(a,index,e);
}
void insertionSort(vector<int>& a){
    int n = a.size();
    for (int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void selectionSort(vector<int>& a){
    int n = a.size();
    for (int i = 0; i < n - 1; i++){
        int mini = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[mini]){  
                mini = j;
            }
        }
        swap(a[i], a[mini]);
    }
}
void bubbleSort(vector<int>& a){
    int n = a.size();
    for (int i = 0; i < n - 1; i++){
        bool c = 0;
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
               c=1;
            }
        }
        if (!c) break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}