class Solution {
public:
    
    void combineletter(string digits, vector<string> &result,string dict[],int i, string s)
    {

        //if i is equal to digits length means we have reached leaf nodes and are ready to store the combinations of letter.
        if(i==digits.size())
        {
            result.push_back(s);
            return ;
        }

        //taking the first number in digits for i = 0, and so on
        string val = dict[digits[i] - '0']; // ex: dict[2] = "a b c" j=0(a), j=1(b) , j=2(c)
        for(int j = 0;j<val.size();j++)
            combineletter(digits,result,dict,i+1,s+val[j]); // pasing (1,a)(1,b)(1,c)

        //then (2,"ad")(2,"ae"),(2,"af") .. so on 
        //now here i is same as the digits length so we will stor it.
    }
    
    vector<string> letterCombinations(string digits) {
        
        //making resultant vector having all combinations of strings
        vector<string> result;
        
        //checking whether the digits have some value or not , if then returning null vector
        if(digits.size()==0)
            return result;
        
        //making a string array containing of the respective string pattern for respective numbers
        //number 0 and number 1 does not have any pattern assigned to them.
        string dict[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        //now we will call recursive function
        //here we are sending 0 and null string pattern because it will be the root of our tree and then we will traverse to leaf nodes having our main combination of letters.
        //sending digits for accesing the numbers, result to store the combinations and dict to check the respective pattern for available number.
        combineletter(digits,result,dict,0,"");
        
        //now we return result as we have passed the result vector by reference in recursive call
        return result;
    }
};