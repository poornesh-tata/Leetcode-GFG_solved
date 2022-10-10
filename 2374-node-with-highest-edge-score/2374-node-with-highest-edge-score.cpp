class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> v(edges.size(),0);
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i]]+=i;
        }
        long long max=INT_MIN;
        long long id;
        for(long long i=0;i<edges.size();i++)
        {
            if(v[i]>max)
            {
                max=v[i];
                id=i;
            }
        }
        return id;
    }
};