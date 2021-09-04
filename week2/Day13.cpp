/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    
    //creating resultant vector and a pointer to each element in nested list
    vector<int> result;
    int ptr=0;
    
public:
    
    void myfunction(vector<NestedInteger> &nestedList)
    {
        for(int i =0;i<nestedList.size();i++)
        {

            //we keep the integer or we pass the list using recursion again till we get integers
            if(nestedList[i].isInteger())
                result.push_back(nestedList[i].getInteger());
            else
                myfunction(nestedList[i].getList());

        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        myfunction(nestedList);
    }

    //here next returns the value of result vector at specified locaton and increment for later use
    int next() {
        return result[ptr++];
        
    }

    //here condition is pointer is less than rsultant vector size then it returns true otherwise false
    bool hasNext() {
        return ptr < result.size();
    }

};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
