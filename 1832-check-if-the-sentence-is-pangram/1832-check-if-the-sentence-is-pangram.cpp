class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> hash(sentence.begin(),sentence.end());
        if(hash.size()==26) return true;
        return false;
    }
};