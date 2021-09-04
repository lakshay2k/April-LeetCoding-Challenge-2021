class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
   
        //The main approach is simple that we can divide into two list having no. less than x and no. more than x. tricky part lies in joining as we have to keep in mind to neglect the starting first node of both list and also make the last to NULL which represents the end
        
        //Lets proceed step by step
        
        //We have s for list haivng small no. and l for list having more than x
        ListNode* s=new ListNode(0);// here forms a node with val = 0 and next = NULL
        ListNode* l=new ListNode(0);// here also forms a node with val =0 and next = NULL
        ListNode* s_head = s;// as we dont have to count these dummy nodes so we keep a pointer where s moves
        ListNode* l_head = l; // ans where l moves
        
        // we iterate till head points to null
        while(head)
        {
            
            //if val is less we add it to small linkedlist and increment small head pointer
            if(head->val < x)
            {
                s_head->next=head;//here initialy shead has refernce to s so we are adding it to s
                s_head = head;// then increment the shead pointer to next node
            }
            else
            {
                l_head->next = head;//here initialy lhead has refernce to l so we are adding it to l
                l_head = head;// then increment the lhead pointer to next node
            } 

            head = head->next;
        }
        
        //as l has large values so it becomes end of combined linkedlist, hence last should point to NULL 
        l_head->next = NULL;
        
        //here first node of second linkedlist that val greater than x as l is its head ans we r storing its nextnode thus neglecting first node of l
        s_head->next = l->next;
        
        //for neglecting first dummy node of s we simple return next node to head to ignore first node.
        return s->next;
    }
};
