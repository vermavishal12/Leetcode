// this solution we using monotonic stack.
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>discount = prices;
        stack<int>s;
        for(int  i = prices.size()-1; i >= 0 ; i--) {
            while(!s.empty() && prices[s.top()] > prices[i]) {
                s.pop();
            }
            if(!s.empty()) {
                discount[i] -= prices[s.top()];
            }

            s.push(i);
        }

        return discount;

    }
};