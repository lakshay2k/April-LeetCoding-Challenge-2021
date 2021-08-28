class Solution {
public:

    bool isPalindrome(ListNode* head) {

        if(head==NULL) return true;
        else if(head->next == NULL) return true;
        else if(head->next->next == NULL) 
        {
            if(head->val==head->next->val) return true;
            else return false;
        }      
        
        //Initial goal is to find the mid point using two pointers approach
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //check if number of nodes are even or odd
        bool even = false;
        if(fast == NULL)
            even = true;
        
        //reversing the linkedlist before midpoint
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next=prev;
            if(next == slow)
                break;
            prev=curr;
            curr=next;
        }
        
        if(!even)
            slow=slow->next;
        
        //now compare the two linkedlist
        //pointer for first ll is curr and pointer for second ll is slow
        while(slow && curr)
        {
            if(curr->val != slow->val)
                return false;
            curr = curr->next;
            slow = slow->next;
        }

        return true;
    }
};
