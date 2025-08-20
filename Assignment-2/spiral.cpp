#include <iostream>
using namespace std;
/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* spiralOrder(const int** A, int n11, int n12, int *len1) {
    int* arr = new int[n11 * n12];
    *len1 = n11 * n12;
    int top = 0, bottom = n11 - 1;
    int left = 0, right = n12 - 1;
    int p = 0;
    while (top <= bottom && left <= right){
        // Traverse right
        for (int i = left; i <= right; i++) arr[p++] = A[top][i];
        top++;
        // Traverse down
        for (int i = top; i <= bottom; i++) arr[p++] = A[i][right];
        right--;
        // Traverse left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) arr[p++] = A[bottom][i];
            bottom--;
        }
        // Traverse up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) arr[p++] = A[i][left];
            left++;
        }
    }
    return arr;
}

int main() {
    int rows = 4, cols = 4;
    int mat[4][4] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    const int* ptrs[4];
    for(int i = 0; i < rows; i++)ptrs[i] = mat[i];
    int len;
    int* spiral = spiralOrder(ptrs, rows, cols, &len);
    cout << "Spiral order traversal:\n";
    for(int i = 0; i < len; i++) {
        cout << spiral[i] << " ";
    }
    cout << endl;
}
