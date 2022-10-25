class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string one,two;
        for(auto it:word1) one+=it;
        for(auto it:word2) two+=it;
        return one==two;
    }
};