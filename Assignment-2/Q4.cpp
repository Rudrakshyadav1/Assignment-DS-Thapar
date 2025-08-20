#include <iostream>
using namespace std;
void merge(char arr[], int s, int m, int l){
    int n1 = m - s + 1;
    int n2 = l - m;
    char* left = new char[n1];
    char* right = new char[n2];
    for (int i = 0; i < n1; i++) left[i] = arr[s + i];
    for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
    delete[] left;
    delete[] right;
}
void sortAlpha(char arr[], int l, int h){
    if (l >= h) return;
    int m = l + (h - l) / 2;
    sortAlpha(arr, l, m);
    sortAlpha(arr, m + 1, h);
    merge(arr, l, m, h);
}
int main(){
    char arr[] = "abcd";
    int a1 = sizeof(arr) / sizeof(arr[0]);
    char arr2[] = "efgh";
    int a2 = sizeof(arr2) / sizeof(arr2[0]);
    int size = a1 + a2 - 1;
    char arr3[size];
    for (int i = 0; i < a1 - 1; i++) arr3[i] = arr[i];
    for (int i = 0; i < a2 - 1; i++) arr3[i + a1 - 1] = arr2[i];
    arr3[size - 1] = '\0';
    cout << arr3 << endl;
    int l = 0, h = size - 2;
    while (l < h){
        char t = arr3[l];
        arr3[l] = arr3[h];
        arr3[h] = t;
        l++;
        h--;
    }
    cout << arr3 << endl;
    char newArr[size];
    int st = 0;
    for (int i = 0; i < size - 1; i++) {
        char c = arr3[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            newArr[st++] = c;
        }
    }
    newArr[st] = '\0';
    cout << newArr << endl;
    sortAlpha(arr3, 0, size - 2);
    cout << arr3 << endl;
    char a[]="ABCDEDFGFGFGFG";
    for(int i = 0; i < sizeof(a)/sizeof(a[0]) - 1; i++){
        if(a[i]>='A'&&a[i]<='Z')a[i] = a[i] - 'A' + 'a';
    }    
    cout<<a<<endl;
}
