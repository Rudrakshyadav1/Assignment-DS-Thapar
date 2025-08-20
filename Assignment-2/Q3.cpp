#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,89,100};
    int l=0;
    int h=sizeof(arr)/sizeof(arr[0]) -1;
    int s;
    cin>>s;
    bool ans=0;
    while(l<=h){
        int m=l+(h-l)/2;
        if(arr[m]==s){
            ans=1;
            break;
        }
        if(arr[m]<s)l=m+1;
        else h=m-1;
    }
    cout<<((ans)?"yes":"NO")<<endl;
}