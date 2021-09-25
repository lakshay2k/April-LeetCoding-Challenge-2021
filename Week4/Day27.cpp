class Solution {
public:

    bool isPowerOfThree(int n) {
        
        //if we get 1 after dividing the number continuously by 3
        // we can say that it can be expressed in power of 3
        
        //to check for zero 
        if(n>1)
        {
        while(n%3 == 0)
        {
            n=n/3;
        }
        }   

        return n==1;
    }
};
