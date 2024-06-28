typedef long long ll;
class Solution {
public:
    bool judgeSquareSum(int c) {

        // if(c == 0)return true;
        for(ll b = 0;b * b <= c ; b++) {
            ll a = sqrt(c - (b*b));
            if((a*a) + (b*b) == c)return true;
        }

        return false;
    }
};