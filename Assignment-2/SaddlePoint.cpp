#include <iostream>
using namespace std;
//work correctly if all eleemnts ina row are diff if there are multiple minimum elements in
// a row then it might give wrong results to fix that a vector can be maintained storing indexes of minimum 
//elements in a row and checking for all of them
int main(){
    int matrix[3][3]={
        {3, 8, 4},
        {2, 6, 9},
        {5, 6, 1}
    };
    int n = sizeof(matrix)/sizeof(matrix[0]);
    int m = sizeof(matrix[0])/sizeof(matrix[0][0]);
    for (int i = 0; i < n; i++) { 
        int maxi = INT_MIN;
        int colIndex = -1;
        for (int j = 0; j < m; j++){
            if (matrix[i][j] >= maxi){
                maxi = matrix[i][j];
                colIndex = j;
            }
        }
        bool isSaddle = true;
        for (int k = 0; k < n; k++){
            if (matrix[k][colIndex] < maxi){
                isSaddle = false;
                break;
            }
        }
        if (isSaddle){
            cout << "Saddle Point: " << maxi << endl;
            return 0;
        }
    }
    cout << "No Saddle Point Found" << endl;
}
