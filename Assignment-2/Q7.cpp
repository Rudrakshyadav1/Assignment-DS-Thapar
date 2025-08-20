#include<iostream>
using namespace std;
void merge(int arr[],int s,int m,int l,int &c){
    int *left=new int[m-s+1];
    int *right=new int[l-m];
    for(int i=0;i<m-s+1;i++)left[i]=arr[i+s];
    for(int i=0;i<l-m;i++)right[i]=arr[m+1+i];
    int i=0,j=0,k=s;
    while(i<m-s+1 && j<l-m){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
            c+=m-s+1-i;
        }
    }
    while(i<m-s+1)arr[k++]=left[i++];
    while(j<l-m)arr[k++]=right[j++];
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[],int s,int l,int &c){
    if(s>=l)return;
    int m=s+(l-s)/2;
    mergeSort(arr,s,m,c);
    mergeSort(arr,m+1,l,c);
    merge(arr,s,m,l,c);
}
int main(){
    int arr[]={100,90,89,1,2,3,4,56,89};
    int s=sizeof(arr)/sizeof(arr[0]);
    int c=0;
    mergeSort(arr,0,s-1,c);
    cout<<c<<endl;
}
