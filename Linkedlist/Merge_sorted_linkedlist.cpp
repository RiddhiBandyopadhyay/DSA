#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* main function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

//Function to merge two sorted linked list.
Node* sortedMerge(Node* h1, Node* h2)  
{  
    if(!h1) return h2;
    if(!h2) return h1;
    
    if(h1->data > h2->data) swap(h1,h2);
    Node* ans = h1;
    
    while(h1 and h2){
       Node* temp = NULL;
       
       while(h1 and h1->data <= h2->data){
           temp = h1;
           h1 = h1->next;
       }
       
       temp->next = h2;
       swap(h1, h2);
    }
    
    return ans;
}