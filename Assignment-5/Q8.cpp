/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
    public:
      Node *addPolynomial(Node *head1, Node *head2){
          Node*first=head1;
          Node*prev=nullptr;
          while(head1 && head2){
              if(head2->pow>head1->pow){
                  Node*newNode=new Node(head2->coeff,head2->pow);
                  newNode->next=head1;
                  if(prev==nullptr){
                      first=newNode;
                  }
                  else{
                      prev->next=newNode;
                  }
                  prev=newNode;
                  head2=head2->next;
              }
              else if(head1->pow==head2->pow){
                  head1->coeff+=head2->coeff;
                  prev=head1;
                  head1=head1->next;
                  head2=head2->next;
              }
              else{
                  prev=head1;
                  head1=head1->next;
              }
          }
          if(head2){
              if(prev) prev->next=head2;
              else first=head2;
          }
          return first;
      }
  };
  