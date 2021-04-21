class Solution {
public:
    bool halvesAreAlike(string s) {
        
        string vowels = "aeiouAEIOU";
        int mid_value = s.size()/2;
        int res =0 ;
        for(int i=0,j=mid_value;i<mid_value;i++,j++)
        {
            if(~vowels.find(s[i]))
                res=res+1;
            if(~vowels.find(s[j]))
                res=res-1;
        }
    return res==0;
    }
};