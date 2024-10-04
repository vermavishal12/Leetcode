#define ll long long
class Solution {
public:
    ll dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        ll sum = skill[0] + skill.back(), res = skill[0]*skill.back();
        int n = skill.size();
        for(int i = 1; i < n/2; i++) {
            ll currSum = skill[i] + skill[n-i-1];
            if(currSum != sum)return -1;
            ll curr = skill[i];
            curr = curr*skill[n-i-1];
            res += curr;
        }   
        return res;
    }
};