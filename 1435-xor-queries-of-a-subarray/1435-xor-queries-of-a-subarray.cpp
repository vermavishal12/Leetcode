// the logic we used in the problem is the concept of the prefix array
// if we want to the xor of the numbers in the range bw {i,j}
// then if we have the xor values from {0,i-1} and {0,j} , then we can do the xor of two values this will give us the result

// xor(0,j) = xor(xor(0,i-1),xor(i,j))
// xor(i,j) = xor(xor(0,j),xor(0,i-1)) => xor(xor(0,i-1),xor(0,i-1), xor(i,j))

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    
        int n = arr.size();
        vector<int> res, pre(n+1);
        for(int i = 0; i < n ; i++) {
            pre[i+1] = pre[i] ^ arr[i];
        }
        
        for(auto& q : queries) {
            res.push_back(pre[q[0]]^pre[q[1]+1]) ;
        }

        return res;
    }
};