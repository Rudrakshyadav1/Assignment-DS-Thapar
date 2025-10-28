#include <iostream>
using namespace std;
class DNode {
public:
    int val;
    DNode* next;
    DNode* prev;
    DNode(int v){
        val = v;
        next = prev = nullptr;
    }
};
class DoublyLinkedList {
    public:
        DNode* head;
        DNode* tail;
        DoublyLinkedList() {
            head = tail = nullptr;
        }
        int size() {
            if (!head) return 0;
            DNode* temp = head;
            int s = 0;
            while (temp) {
                s++;
                temp = temp->next;
            }
            return s;
        }
        void insertAtHead(int v) {
            DNode* newNode = new DNode(v);
            if (!head) {
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        bool palindrome() {
            if (!head) return true;
            DNode* left = head;
            DNode* right = tail;
            while (left != right && left->prev != right){
                if (left->val != right->val) return false;
                left = left->next;
                right = right->prev;
            }
            return true;
        }
        void print() {
            DNode* temp = head;
            if (!temp) {
                cout << "List is empty\n";
                return;
            }
            while (temp) {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};
int main(){

}