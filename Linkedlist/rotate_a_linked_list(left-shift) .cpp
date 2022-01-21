#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    
    Node* rotate(Node* head, int k)
    {
        if(!head or !head->next or k == 0) 
            return head;
        
        Node* cur = head;
        int len = 1;
        while(cur->next){
            len++;
            cur = cur->next;
        }
        
        if(len == k) return head;
        
        cur->next = head;
        Node* temp = head;
        k--;
        while(k--){
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}