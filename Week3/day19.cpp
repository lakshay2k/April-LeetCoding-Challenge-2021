class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        
        //creating subresults vector which stores result of dynamic programming- intermediate results
        vector<unsigned int> dp(target+1,0);
        
        //the size id targt + 1 as it is zero index and we have to cover target no. so
        //for ex if target is 4 and t(4) - 0 1 2 3 there will be no 4, thats why
        
        //here to get the sum of zero we need zero (1 element) so we made it 1
        dp[0] = 1;
        
        //now we made results for smal numbers and then move to target.
        //for 1 , how can we make 1 using given numbers in nums. so like that.
        
        for(int i = 1; i<= target; i++)
        {
            for(int num : nums)
            {
                //to make sum upto 2 we need number less than 2 only so using this logic below
                if(num<=i)
                    dp[i] = dp[i] + dp[i-num];

                    //for making 3 we need 1 and then combination of how to make 2 which we have already stored
                    //for making 3 we need 2 and then combination of how to make 1 which we have already stored
                    //for making 3, we can select 3 ,
                    
            }
        }
        
        //return dp[target] - it stores number of ways to make target. 
        return dp[target];
    }
};