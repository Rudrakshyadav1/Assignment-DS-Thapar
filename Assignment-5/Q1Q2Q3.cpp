#include<iostream>
using namespace std;
class Node{
public:
    Node* next;
    int val;
    Node(){
        next = nullptr;
        val = INT_MIN;
    }
    Node(int v){
        val = v;
        next = nullptr;
    }
};
class linkedlist{
public:
    Node* head;
    Node* tail;
    linkedlist(){
        head = tail = nullptr;
    }
    void insertHead(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertTail(int val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteHead(){
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }
    void deleteTail(){
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    void Search(int v){
        Node* temp = head;
        int c = 0;
        while (temp != nullptr && temp->val != v){
            temp = temp->next;
            c++;
        }
        if (temp == nullptr){
            cout << "Not Found" << endl;
        }
        else {
            cout << "Found at position " << c << endl;
        }
    }
    void display(){
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void delete_key(int key){
        while (head != nullptr && head->val == key){
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr){
            if (temp->next->val == key){
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                if (toDelete == tail){
                    tail = temp;
                }
                delete toDelete;
            }
            else{
                temp = temp->next;
            }
        }
        if (head == nullptr){
            tail = nullptr;
        }
    }
    Node* middle() {
        if (head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* reverseiter(Node* h){
        if (!h || !h->next){
            return h;
        }
        Node* prev = nullptr;
        Node* current = h;
        Node* next = nullptr;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev; 
    }
    Node* reverserecurr(Node* h){
        if (h == nullptr || h->next == nullptr){
            return h;
        }
        Node* rest = reverserecurr(h->next);
        h->next->next = h;
        h->next = nullptr;
        return rest; 
    }
};
int main(){

}