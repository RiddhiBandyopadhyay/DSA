#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution {
public:
    Node *detectLoop(Node* head) {
        if(!head or !head->next) 
            return NULL;
        
        Node* slow = head;
        Node* fast = head;
        Node* dummy = head;
        
        while(fast->next and fast->next->next){ 
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(dummy != slow){
                    dummy = dummy->next;
                    slow = slow->next;
                }
                
               return dummy;
            }
        }
        
        return NULL;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        Node* node = ob.detectLoop(head);
    }
	return 0;
}
