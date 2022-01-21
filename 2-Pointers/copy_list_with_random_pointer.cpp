class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Step 1 : Making the deep copies
        Node* iter = head;
        Node* front = head;
        
        while(iter != NULL){
            front = iter->next;
            Node* copy = new Node(iter->val); //Making the deep copy
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        //Step 2 : Pointing the random pointers
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }
        
        //Step 3 : Differentiating the original and the deep copy list
        iter = head;
        Node* copyHead = new Node(0);
        Node* temp = copyHead;
        
        while(iter != NULL){
            front = iter->next->next;
            temp->next = iter->next;
            iter->next = front;
            temp = temp->next;
            iter = iter->next;
        }
        
        return copyHead->next;
    }
};