class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //decalring variables for length and listnode temp to traverse linkedlist
        int len = 0,i;
        ListNode* temp = head;
        
        //calculating the length of linkedlist
        while(temp)
        {
            temp=temp->next;
            len = len +1 ;
        }
        
        //if the len is equal to n which means last nth means first node which is head.

        if(len == n)
        {
            //first storing the head next link and deleting head and returnig new head
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }
        
        //now the temp is at last when we calculated the length so need to set it to head again.
        temp = head;
        
        //using this for loop , we are going to one node ahead of nth node 
        for(i=1;i<(len-n);i++)
        {
            temp=temp->next;
        }
        
        //to_delete has the node to be deleted which is temp->next 
        //but before than we have link node before nth node and node after nth node
        ListNode* to_delete = temp->next;
        temp->next = temp->next->next;
        
        //after linking , delete the nth node
        delete to_delete;
        
        //return the head.
        return head;
        
    }
};
