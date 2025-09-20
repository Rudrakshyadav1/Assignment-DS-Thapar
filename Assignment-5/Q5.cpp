#include<iostream>
using namespace std;
class Node {
public:
    Node* next;
    int val;
    Node() {
        next = nullptr;
        val = INT_MIN;
    }
    Node(int val) {
        next = nullptr;
        this->val = val;
    }
};
Node* solve(Node* head, int k) {
    if (!head || k == 1) return head;
    Node *dummy = new Node(0);  
    dummy->next = head;
    Node *prevGroupEnd = dummy, *curr = head;
    while(curr){
        Node*groupStart=curr;
        int count = 0;
        while (curr && count < k){
            curr = curr->next;
            count++;
        }
        if (count == k){
            Node *prev = nullptr, *next = nullptr;
            Node *groupEnd = groupStart;
            while(count--){
                next = groupStart->next;
                groupStart->next = prev;
                prev = groupStart;
                groupStart = next;
            }
            prevGroupEnd->next = prev;
            groupEnd->next = curr; 
            prevGroupEnd = groupEnd;
        }
    }
    return dummy->next; 
}
void printList(Node* head){
    Node* temp = head;
    while (temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    int k = 3;
    cout << "Original List: ";
    printList(head);
    head = solve(head, k);
    cout << "Reversed List in groups of " << k << ": ";
    printList(head);
}
