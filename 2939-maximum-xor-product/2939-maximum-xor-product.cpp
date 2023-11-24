/* ---------    APPROACH     -----------*/

// now in order to maximize the answer we are required to find the maxmimum element which is in the range of 0 to 2^50 - 1
// which will result in the maxmimised answer, but if we iterate over each element in the range of 0 to 2^50 - 1 it will lead to TLE
// hence our the solution begins like we store the binary representation of the integers 'a' and 'b' in the array 'A' and 'B' respectively 
// and for each index in the array 'A' and 'B' we check whether both the array contains same value at that index or not
// if yes then we simply assign the ith bit of the x to the xor of A[i] 
// if not so then we check whether which of the i.e. set or unset bit at that index will yield us the maximum product
// this can be done by comparing the sol1 and sol2 value, if sol2 >= sol1 then we set the bit at ith index
// here sol1 is the product of the ((a xor x) * (b xor x)) when the bit is unset
// and sol2 is the product of the ((a xor x) * (b xor x)) when the bit is set


/* _*_ PROBLEM   */
// the solution is giving the error right now because when we are checking the product ((a xor x) * (b xor x)) it is showing that result is going out of bound.

class Solution {
public:
    
    typedef long long ll;
    ll mod = 1e9 + 7;
    
    vector<ll> binaryVal(ll num) {      // returns the binary representation of the num
        vector<ll>binary(50);
        int index = 0;
        while(num) {
            binary[index++] = num&1;
            num = num/2;
        }
        
        return binary;
    }
    
    int maximumXorProduct(long long a, long long b, int n) {
        vector<long long>binaryValA = binaryVal(a);
        vector<long long>binaryValB = binaryVal(b);
        
        ll res = 0;
    
        vector<ll>binaryValN(50);
        for(int i = n-1; i >= 0; i--) {
            ll val = 1 << i;

            if(binaryValA[i] == binaryValB[i]){
                if(binaryValA[i] == 0) {
                    res = res^val;
                    
                }
                
            }else{
                ll m = (res^a)%mod , N = (res^b)%mod;
                ll sol1 = (m) * (N);
                m = (res^val^a)%mod , N = (res^val^b)%mod;
                ll sol2 = (m) * (N);
                if(sol1 <= sol2){
                    res = res^val;
                }
            }
        }

        ll m = (res^a)%mod , N = (res^b)%mod;
        ll ans = (m)*(N);
        return ans%mod;
        /*
        _ _ _ _
        1 1 0 0
        0 1 0 1
        0 0 1 1
        
        1 1 1 1 = 15
        0 1 1 0 = 6
        
        _ _ _
        0 0 1
        1 1 0
             
        
        */
    }
};