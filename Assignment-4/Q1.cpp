#include<iostream>
using namespace std;
class Node {
    public:
        int val;
        Node* next;
        Node(int val) {
            this->val = val;
            next = nullptr;
        }
    };
class Queue{
    private:
        Node* front;
        Node* rear;
        int size;
    public:
        Queue(){
            front = rear = nullptr;
            size = 0;
        }
        bool isEmpty(){
            return size == 0;
        }
        void enqueue(int v){
            Node* newNode = new Node(v);
            if (isEmpty()) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
        void dequeue(){
            if (isEmpty()){
                cout << "Queue is Empty!\n";
                return;
            }
            Node* temp = front;
            cout << "Dequeued: " << temp->val << endl;
            front = front->next;
            delete temp;
            size--;
            if (front == nullptr) rear = nullptr; 
        }
        int peek() {
            if (isEmpty()) {
                cout << "Queue is Empty!\n";
                return -1;
            }
            return front->val;
        }
        void display(){
            Node* temp = front;
            cout << "Queue: ";
            while(temp != nullptr){
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};
int main(){
    Queue q; 
    
}