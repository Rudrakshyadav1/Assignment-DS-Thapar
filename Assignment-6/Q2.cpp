#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = nullptr;
    }
};
class CircularSingly {
public:
    Node* head;
    Node* tail;
    CircularSingly() {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtHead(int v) {
        Node* newNode = new Node(v);
        if (!head) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
    void insertAtTail(int v){
        Node* newNode = new Node(v);
        if (!head) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    void display(){
        if(!head) return;
        Node* t = head;
        do {
            cout << t->val << " ";
            t = t->next;
        } while (t != head);
        cout << head->val << endl;
    }
};
int main(){
    CircularSingly clist;
    clist.insertAtTail(20);
    clist.insertAtTail(100);
    clist.insertAtTail(40);
    clist.insertAtTail(80);
    clist.insertAtTail(60);
    clist.display(); 
}
