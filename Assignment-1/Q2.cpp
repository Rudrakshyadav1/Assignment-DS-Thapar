#include<iostream>
using namespace std;
int *arr,n,s;
// without hashmap or sorting
void delete_in(int j){
    for(int i=j;i<s;i++){
        arr[i]=arr[i+1];
    }
    s--;
}
void remove_duplicate(){
    for(int i=0;i<=s;i++){
        for(int j=i+1;j<=s;j++){
            if(arr[i]==arr[j]){
                delete_in(j);
                j--;
            }
        }
    }
}
int main(){
    cin>>n;
    s=n-1;
    arr=new int[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    remove_duplicate();
    for(int i=0;i<=s;i++) cout<<arr[i]<<" ";
    cout<<endl;
    delete[] arr;
}
