#include<iostream>
using namespace std;
int *arr,n,s;
void display(){
    for(int i=0;i<=s;i++) cout<<arr[i]<<" ";
    cout<<endl;
}
void insert(int in,int t){
    if(in<0||s>=n-1){
        cout<<"Invalid index or array full"<<endl;
        return;
    }
    for(int i=s+1;i>in;i--){
        arr[i]=arr[i-1];
    }
    arr[in]=t;
    s++;
}
void delete_in(int in){
    if(s<0||in<0||in>s){
        cout<<"Invalid index or Empty array.."<<endl;
        return;
    }
    for(int i=in;i<s;i++){
        arr[i]=arr[i+1];
    }
    s--;
}
bool linearSearch(int t){
    for(int i=0;i<=s;i++){
        if(t==arr[i]) return true;
    }
    return false;
}
int main(){
    cin>>n;
    s=n-1;
    arr=new int[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    while(true){
        int c;
        cin>>c;
        if(c==-1){
            break;
        }
        else if(c==2){
            display();
        }
        else if(c==3){
            int in,t;
            cin>>in>>t;
            insert(in,t);
        }
        else if(c==4){
            int t;
            cin>>t;
            if(linearSearch(t)) cout<<"Found\n";
            else cout<<"NO\n";
        }
        else if(c==5){
            int in;
            cin>>in;
            delete_in(in);
        }
    }
    delete[] arr;
}
