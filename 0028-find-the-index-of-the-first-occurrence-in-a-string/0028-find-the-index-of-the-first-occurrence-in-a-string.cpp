class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()){return -1;}
		if(haystack.size()==needle.size())
        {
            if(haystack==needle) return 0;
            else return -1;
        }
		for(int i=0; i<haystack.size()-needle.size()+1; i++){
			string s=haystack.substr(i, needle.size());
			if(s==needle){
				return i;
			}
		}
		return -1;
    }
};