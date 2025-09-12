#include <iostream>
using namespace std;
class Queue{
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
public:
    Queue(int n){
        arr = new int[n];
        capacity = n;
        front = 0;
        rear = 0;
        size = 0;
    }
    bool isFull(){
        return size == capacity;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(int val){
        if (isFull()){
            cout << "Queue is Full!\n";
            return;
        }
        arr[rear] = val;
        rear = (rear + 1) % capacity;
        size++;
    }
    void dequeue(){
        if (isEmpty()){
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Dequeued: "<<arr[front]<<endl;
        front = (front + 1) % capacity;
        size--;
    }
    void peek(){
        if(size>0){
            cout<<"peek\n"; 
            cout<<arr[front]<<endl;
        }
        else cout<<"it is Empty\n";
    }
    void display(){
        if (isEmpty()){
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size;i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); 
    q.dequeue(); 
    q.display(); 
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();   
    q.enqueue(70); 
}
