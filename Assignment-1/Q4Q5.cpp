#include<iostream>
using namespace std;
int *arr,n,**a,**b;
int** transpose(int **matrix,int rows,int cols){
    int **transposed=new int*[cols];
    for(int i=0;i<cols;i++){
        transposed[i]=new int[rows];
        for(int j=0;j<rows;j++){
            transposed[i][j]=matrix[j][i];
        }
    }
    return transposed;
}
void reversal(int **matrix,int r,int c){
    for(int i=0;i<r;i++){
        int l=0,h=c-1;
        while(l<=h){
            int k=matrix[i][l];
            matrix[i][l]=matrix[i][h];
            matrix[i][h]=k;
            l++;
            h--;
        }
    }
}
void multiplication(int **mat1,int r1,int c1,int **mat2,int r2,int c2){
    if(c1!=r2){
        cout<<"Matrix multiplication not possible\n";
        return;
    }
    cout<<"Multiplication:\n";
    int **res=new int*[r1];
    for(int i=0;i<r1;i++){
        res[i]=new int[c2];
        for(int j=0;j<c2;j++){
            res[i][j]=0;
            for(int k=0;k<c1;k++){
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<r1;i++)delete[]res[i];
    delete[]res;
}
void sumrowcol(int **matrix,int r,int c){
    cout<<"Row sums:\n";
    for(int i=0;i<r;i++){
        int row_sum=0;
        for(int j=0;j<c;j++)row_sum+=matrix[i][j];
        cout<<row_sum<<endl;
    }
    cout<<"Column sums:\n";
    for(int i=0;i<c;i++){
        int col_sum=0;
        for(int j=0;j<r;j++)col_sum+=matrix[j][i];
        cout<<col_sum<<endl;
    }
}
int main(){
    int r,c;cin>>r>>c;
    a=new int*[r];
    for(int i=0;i<r;i++){
        a[i]=new int[c];
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    int rb,cb;cin>>rb>>cb;
    b=new int*[rb];
    for(int i=0;i<rb;i++){
        b[i]=new int[cb];
        for(int j=0;j<cb;j++){
            cin>>b[i][j];
        }
    }
    int **temp=transpose(a,r,c);
    swap(r,c);
    multiplication(a,r,c,b,rb,cb);
    sumrowcol(a,r,c);
    reversal(a,r,c);
}
