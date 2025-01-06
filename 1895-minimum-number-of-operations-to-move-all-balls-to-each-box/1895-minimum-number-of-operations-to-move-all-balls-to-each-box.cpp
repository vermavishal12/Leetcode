class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>res(n);
        int rightCurr = 0, rightCntr = 0;
        for(int i = 1; i < n ; i++) {
            if(boxes[i] == '1'){
                rightCntr++;
                rightCurr += i;
            }
        }
        res[0] = rightCurr;
        int leftCntr = boxes[0]-'0', leftCurr = 0;

        
        for(int i = 1; i < n ; i++) {
            res[i] = rightCurr - rightCntr + (i)*leftCntr - leftCurr;
            rightCurr = rightCurr - rightCntr;
            if(boxes[i] == '1'){
                rightCntr--;
                leftCntr++;
                leftCurr += i;
            }
        }

        return res;

        
    }
};