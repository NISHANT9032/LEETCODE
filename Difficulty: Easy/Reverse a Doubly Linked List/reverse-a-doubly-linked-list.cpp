/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node *curr=head , *prev=nullptr , *next;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            curr->prev=next;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};

