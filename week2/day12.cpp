class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        //vector having the beautiful arrangement of numbers
        vector<int> result(n);
        
        //we are solving the array by dividing it into two parts 
        // covering till k+1 and after that simply incrementing the number and storing it.
        for(int i = 0 , a = 1 , z = k+1 ; i <= k; i++)
        {
            
            //here we are dealing with the extremes and the maximum and unique differences can be calculated using the extremes only
            //for ex : [1,2,3,4,5]
            //max diff of 4 can be from (1,5) max diff of 3 can be from (1,4) OR (2,5)
            //max diff of 2 can be from (1,3) OR (2,5) and so on
            //here i%2 is being used to alternatively choose one extreme
            result[i] = i % 2 ? z-- : a++;
        }
        
        //after covering till k+1 elements we have found all the distinct differences and for the rest of elements of array , we can simply add them to the last
        for(int i = k+1; i < n; i++)
        {
            result[i] = i + 1;
        }
        
        //now return the resultant array
        return result;
    }
};