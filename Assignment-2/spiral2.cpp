#include <iostream>
using namespace std;
int ** generateMatrix(int A, int *len1, int *len2) {
    int **ans = new int*[*len1];
    for(int i = 0; i < *len1; i++){
        ans[i] = new int[*len2];
    }
    int l = 0, r = *len2 - 1, t = 0, b = *len1 - 1, p = 1;
    while(l <= r && t <= b){
        // Right
        for(int i = l; i <= r; i++){
            ans[t][i] = p++;
        }
        t++;
        // Down
        for(int i = t; i <= b; i++){
            ans[i][r] = p++;
        }
        r--;
        // Left
        if(t <= b){
            for(int i = r; i >= l; i--){
                ans[b][i] = p++;
            }
            b--;
        }
        // Up
        if(l <= r){
            for(int i = b; i >= t; i--){
                ans[i][l] = p++;
            }
            l++;
        }
    }
    return ans;
}

int main(){
    int n = 4;
    int rows, cols;
    rows=n;
    cols=n+2;
    int **matrix = generateMatrix(n, &rows, &cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout <<endl;
    }
}
