class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
     
        //initialising a vector of positions of all elements according to order given
        vector<int> positions(26);
        
        //having small number meaning high priority
        for(int i=0;i<order.size();i++)
        {
            positions[order[i]-'a'] = i;
        }
        
        //now checking two elements letter by letter one by one
        for(int i=0;i<words.size() - 1;i++)
        {

            for(int j=0;j<words[i].size();j++)
            {

                //when first letter is big compared to second and have same starting letter like app and apple
                if(j == words[i+1].size())
                    return false;

                //if word at first has more posn means it has low priority so we return false
                if(positions[words[i][j] - 'a'] > positions[words[i+1][j] - 'a'])
                    return false;

                //if word at first has less posn, it means first has high priority than second and is sorted so we break here
                if(positions[words[i][j] - 'a'] < positions[words[i+1][j] - 'a'])
                    break;
            }
        }
        
        //when everything is sorted
        return true;
    }
};
