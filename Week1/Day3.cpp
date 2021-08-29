class Solution {
public:
    int longestValidParentheses(string s) {
        
        if(size(s) <= 1)
            return 0;
        
        //initialising longest variable to track length of valid parenthesis
        int longest = 0;
        stack<int> mystack;
        
        //to denote start of valid parenthesis stack will always have the -1
        //as soon as -1 disappers the till now longest lengthh cannot be extended further
        mystack.push(-1);
        
        //if it is ( , we push to stack otherwise
        for(int i = 0; i < size(s); i++)
        {

            if(s[i] == '(')
                mystack.push(i);
            //otherwise we pop its equivalent opening bracket
            //so whenever closing bracket comes we pop one element from stack
            else
            {
                mystack.pop();
                if(mystack.empty())
                    mystack.push(i);
                else
                    longest = max(longest, i - mystack.top());
            }
        }

        return longest;
    }
};
