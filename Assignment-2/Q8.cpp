#include<iostream>
#include<climits>
using namespace std;
void merge(int arr[], int s, int m, int l){
    int* left = new int[m - s + 1];
    int* right = new int[l - m];
    for (int i = 0; i < m - s + 1; i++) left[i] = arr[s + i];
    for (int i = 0; i < l - m; i++) right[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = s;
    while (i < m - s + 1 && j < l - m){
        if (left[i] < right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < m - s + 1) arr[k++] = left[i++];
    while (j < l - m) arr[k++] = right[j++];
    delete[] left;
    delete[] right;
}
void sortnum(int arr[], int s, int l){
    if (s >= l) return;
    int m = s + (l - s) / 2;
    sortnum(arr, s, m);
    sortnum(arr, m + 1, l);
    merge(arr, s, m, l);
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 78, 99, 100, 100, 100, 2, 3, 4, 5};
    int c = 0;
    int maximum = *max_element(arr, arr + sizeof(arr) / sizeof(arr[0]));
    bool* arr2 = new bool[maximum + 1]{};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (!arr2[arr[i]]) {
            arr2[arr[i]] = 1;
            c++;
        }
    }
    cout << c << endl;
    delete[] arr2;
    c = 0;
    sortnum(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    c = 1;
    for (int i = 1; i < sizeof(arr)/sizeof(arr[0]);i++){
        if (arr[i] != arr[i - 1])c++;
    }
    cout << c << endl;
}
