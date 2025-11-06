#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
Node *reverseKNodes(Node *head, int k){
    Node *curr = head, *prev = nullptr, *next = nullptr;
    int count = 0;
    while (curr != nullptr && count < k){
        next = curr->next;
        curr->next = prev;
        curr->prev = nullptr;
        if (prev != nullptr){
            prev->prev = curr;
        }
        prev = curr;
        curr = next;
        count++;
    }
    return prev;
}
Node *reverseKGroup(Node *head, int k){
    if (head == nullptr)return head;
    Node *groupHead = nullptr;
    Node *newHead = nullptr;
    Node *temp = head;
    int count = 0;
    while (temp && count < k){
        temp = temp->next;
        count++;
    }
    groupHead = reverseKNodes(head, k);
    if (newHead == nullptr){
        newHead = groupHead;
    }
    head->next = reverseKGroup(temp, k);
    if (head->next != nullptr){
        head->next->prev = head;
    }
    return newHead;
}
int main(){
  
}