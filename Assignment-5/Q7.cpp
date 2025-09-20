/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
    public:
      Node* rotate(Node* head, int k){
          if (!head || k == 0) return head;
          int length = 1;
          Node* temp = head;
          while (temp->next){
              temp = temp->next;
              length++;
          }
          k = k % length;
          if (k == 0) return head;
          Node* newTail = head;
          for (int i = 1; i < k; i++){
              newTail = newTail->next;
          }
          Node* newHead = newTail->next;
          newTail->next =nullptr;
          temp->next = head;
          return newHead;
      }
  };
  