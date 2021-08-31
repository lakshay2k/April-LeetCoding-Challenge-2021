class Solution {
public:
    int minOperations(int n) {

        //n = odd [1 , 3 , 5]    we have to perform n/2 operations to left and n/2 to right of mid element.
        //n=even [1,3,5,7] we have to perform n/2+1 operations to left and n/2+1 to right of mid element.
        //n/2*n*2 in case of odd  ,,,, (n/2 +1)*(n/2 +1) will be be same when taken floor.
        
        return n*n/4;

    }
};
