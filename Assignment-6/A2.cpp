#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *prev, *next;
};
bool isEvenParity(int x){
    int parity = 0;
    while (x != 0){
        if (x & 1)parity++;
        x = x >> 1;
    }
    if (parity % 2 == 0)return true;
    else return false;
}
void deleteNode(Node** head_ref, Node* del){
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return;
}
void deleteEvenParityNodes( Node** head_ref){
    Node* ptr = *head_ref;
    Node* next;
    while (ptr != NULL){
        next = ptr->next;
        if (isEvenParity(ptr->data))
            deleteNode(head_ref, ptr);

        ptr = next;
    }
}
int main(){
}