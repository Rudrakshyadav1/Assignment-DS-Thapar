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
void loopremove(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow && fast && slow == fast){
        slow = head;
        if(slow == fast){
            while (fast->next != slow) fast = fast->next;
            fast->next = nullptr;
            return;
        }
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
    }
}
int main() {

}
