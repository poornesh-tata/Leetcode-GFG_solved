vector<int> v;
for(auto &it:nums)
{
int x=it;
while(v.size() and (__gcd(v.back(),it)>1))
{
int c=v.back();
v.pop_back();
x=lcm(c,it);
}
v.push_back(x);
}
return v;