class Solution {
public:

    int countBinarySubstrings(string s) {
        
        //using prev block to store the prev before edge case and curr respectively
        int prev = 0, curr = 1, res = 0;

        /*
        ex 0011001100 -> curr =2 , s[i]=1 res = 0 prev =curr(2) curr = 1, 
        s[i]=0 res = 2 prev =2 curr =1, s[i]=1 res = 2+2  prev =2 ,curr1,
        loop ends as it gets out of for condition
        */
        
        for(int i = 1;i < s.size(); i++)
        {
            if(s[i] == s[i-1])
                curr = curr + 1;
            else
            {
                res = res + min(curr,prev);
                prev = curr;
                curr = 1;
            }
        }
        
        //we add last group case
        return res + min(curr,prev);
    }

};