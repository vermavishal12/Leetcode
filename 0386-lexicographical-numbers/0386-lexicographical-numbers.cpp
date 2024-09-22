class Solution {
public:

    vector<int>res;

    // we start with the single digits and then go one by one by adding the integers
    // at the back, if the current integer in the iteration is greater than the given integer we fall back
    // else we keep on going deep
    void traverseSubNodes(int currNum, int n) {
        if(currNum > n)return;

        res.push_back(currNum);
        
        for(int i = 0; i < 10 ; i++) {
            traverseSubNodes(currNum*10 + i , n);
        }

        return;
    }
    vector<int> lexicalOrder(int n) {

        for(int i = 1; i <= 9 ; i++) {
            traverseSubNodes(i,n);
        }

        return res;
    }
};