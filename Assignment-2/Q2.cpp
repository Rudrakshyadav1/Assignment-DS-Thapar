#include<iostream>
using namespace std;
int main(){
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        bool swap=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int c=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=c;
                swap=1;
            }
        }
        if(!swap) break;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}