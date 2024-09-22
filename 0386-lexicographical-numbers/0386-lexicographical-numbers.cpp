class Solution {
public:

    vector<int>res;

    void func(int currNum, int n) {
        if(currNum > n)return;

        res.push_back(currNum);
        
        for(int i = 0; i < 10 ; i++) {
            func(currNum*10 + i , n);
        }

        return;
    }
    vector<int> lexicalOrder(int n) {

        for(int i = 1; i <= 9 ; i++) {
            func(i,n);
        }

        return res;
    }
};