// the logic is we have to give the maximum coin to the alice
// and we can take the second maximum, so we can sort the piles of coins
// and take 2 coins from end and one from front; the front one we will give to the BOB
// the 2 coins from the end the highest coin will be taken by the ALICE and the left out we will take
// hence this way we can maximise the score.


class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size()/3 ;
        int ans = 0;
        int N = piles.size() - 2;
        while(n) {
            ans += piles[N];
            N -= 2;
            n--;
        }

        return ans;
    }
};