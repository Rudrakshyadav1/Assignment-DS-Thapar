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
    int size() {
        if (!head) return 0;
        int s = 0;
        Node* temp = head;
        do {
            s++;
            temp = temp->next;
        } while (temp != head);
        return s;
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
    void insertAfterValue(int afterVal, int v){
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->val == afterVal){
                Node* newNode = new Node(v);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == tail) tail = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Value " << afterVal << " not found.\n";
    }

    bool search(int v) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->val == v) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }
    void deleteValue(int v){
        if (!head) return;
        if (head == tail && head->val == v) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* curr = head;
        Node* prev = tail;
        do {
            if (curr->val == v) {
                if (curr == head) {
                    head = head->next;
                    tail->next = head;
                    delete curr;
                } else if (curr == tail) {
                    tail = prev;
                    tail->next = head;
                    delete curr;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
        cout << "Value " << v << " not found.\n";
    }
    void print() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
class DNode {
public:
    int val;
    DNode* next;
    DNode* prev;
    DNode(int v) {
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

    void insertAtTail(int v) {
        DNode* newNode = new DNode(v);
        if (!tail) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    void insertAfterValue(int afterVal, int v) {
        DNode* temp = head;
        while (temp) {
            if (temp->val == afterVal) {
                DNode* newNode = new DNode(v);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next) temp->next->prev = newNode;
                temp->next = newNode;
                if (temp == tail) tail = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << afterVal << " not found.\n";
    }

    bool search(int v) {
        DNode* temp = head;
        while (temp) {
            if (temp->val == v) return true;
            temp = temp->next;
        }
        return false;
    }

    void deleteValue(int v) {
        DNode* temp = head;
        while (temp) {
            if (temp->val == v) {
                if (temp == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << v << " not found.\n";
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

bool iscircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while(temp != nullptr && temp != head){
        temp = temp->next;
    }
    return (temp == head);
}
int main() {
    
}
