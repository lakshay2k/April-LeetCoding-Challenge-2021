class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        
        //considering the deviation from a element is same as the global inversions
        for(int i = 0; i < A.size(); i++)
        {

            if(i - A[i] > 1 || i - A[i] < -1)
                return false;

        }
        
        //if deviation comes of more than one, it will make unequal global and local inversions
        //to be equal the difference should be only 1 

        return true;
    }
};