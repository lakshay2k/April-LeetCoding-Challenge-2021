class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        //declaring variable for size of s, and string for result
        //and a stack that accept pair of letter and its count
        int n = s.size(),i;
        string result = "";
        stack<pair<char,int>> mystack;
        
        //if the length of string is less than k, then string does not have k adjacent duplicates
        if(n<k)
            return s;
        
        for(i=0;i<n;i++)
        {

            //first we check if it is empty or the other letter matches the already stored letter or not
            char c = s[i];

            if(mystack.empty() || c!=mystack.top().first)
                mystack.push({c,1});
            //in else means the next letter we are storing is same as the previous stored one
            else
            {
                //so here we increase the frequency of previously stored number
                mystack.top().second++;
                
                //and then check that whether it equals to k or not, id it does then pop it.
                if(mystack.top().second == k)
                    mystack.pop();
            }
        }
        
        //here we get the letter which are not duplicates so we concatenate them by running a for loop 
        //till there counts and add them t resultant string
        while(!mystack.empty())
        {

            for(i = 0;i<mystack.top().second;i++)
                result = mystack.top().first + result;
            mystack.pop();
        }
        
        return result;
    }
};
