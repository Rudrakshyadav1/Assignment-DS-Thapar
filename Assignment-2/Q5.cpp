#include <iostream>
#include <cmath>
using namespace std;
int main(){
    // Diagonal matrix
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 0;
    cout << "Diagonal Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            if(i == j){
                cout << arr[p++] << " ";
            }
            else cout << 0 << " ";
        }
        cout << endl;
    } 
    cout << endl;   

    // Tri-diagonal matrix
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = sizeof(a) / sizeof(a[0]);
    n = (k + 2) / 3;  // Calculate matrix size for tri-diagonal
    p = 0;

    cout << "Tri-diagonal Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            if(i == j || i == j + 1 || i == j - 1)
                cout << a[p++] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    } 
    cout << endl;   

    // Lower triangular matrix
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    k = sizeof(b) / sizeof(b[0]);
    n = (int)((-1 + sqrt(1 + 8 * k)) / 2);
    p = 0;
    int rowLength = 1;
    cout << "Lower Triangular Matrix:\n";
    for(int i = 0; i < n; i++){
        int k = rowLength;
        for(int j = 0; j < n; j++){
            if(k > 0){
                cout << b[p++] << " ";
                k--;
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
        rowLength++;
    }
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    k = sizeof(c) / sizeof(c[0]);
    n = (int)((-1 + sqrt(1 + 8 * k)) / 2);
    p = 0;
    int count = n;
    cout << "Upper Triangular Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j < i) cout << 0 << " ";
            else cout << c[p++] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Symmetric Matrix
    int sy[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size_sy = sizeof(sy) / sizeof(sy[0]);
    n = (int)((-1 + sqrt(1 + 8 * size_sy)) / 2);
    p = 0;
    cout << "Symmetric Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i >= j)cout << sy[(i*(i+1))/2 + j] << " ";
        else cout << sy[(j*(j+1))/2 + i] << " ";
    }
    cout << endl;
}

}