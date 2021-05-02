class Solution {
public:
    int fib(int n) {
        
        //first thing comes to mind of recursion but it takes O(N*N) tc
        //for we can iterate using loop and then tc becomes O(N)
        
        if(n < 2)
            return n;
        
        //we are adding t1 and t2 in t2 or we can say storing sum of two previous numbers
        int t1=0,t2=1,temp;
        for(int i=1;i<n;i++)
        {
            temp=t1;
            t1=t2;
            t2=t2+temp;
        }
        
        //returing the last number whihc gives the fibonacci of given n
        return t2;
    }
};