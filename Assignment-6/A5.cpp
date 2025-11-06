#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* up;
    Node* down;
    Node(int x) : data(x) , left(NULL) , right(NULL) , up(NULL) , down(NULL) {}
};
void print(Node* head){
    Node* downptr = head;
    Node* rightptr;
    while (downptr){
        rightptr = downptr;
        while (rightptr){
            cout << (rightptr->data) << " ";
            rightptr = rightptr->right;
        }
        cout << "\n";
        downptr = downptr->down;
    }
}
int main(){
    int mat[3][3] ={
         { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int n = 3, m = 3;
    Node* head_main = NULL; 
    Node* prev, *upper = new Node(-1); 
    for (int i = 0; i < n; i++) {
        Node* head_row; 
        Node *prev = new Node(-1); 
        for (int j = 0; j < m; j++) {
            Node* temp = new Node(mat[i][j]);
            if (j == 0) head_row = temp;
            if (i == 0 && j == 0) head_main = temp;
            temp->left = prev;
            prev->right = temp;
            if (i == n - 1) temp->down = NULL;
            if (!upper->right){
                upper->right = new Node(-1);
            }
            upper = upper->right;
            temp->up = upper;
            upper->down = temp;
            prev = temp;

            if (j == m - 1) prev->right = NULL;

        }
        upper = head_row->left;
    }
    print(head_main);

}