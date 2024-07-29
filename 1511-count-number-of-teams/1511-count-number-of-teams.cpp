#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set_high tree<int, null_type, greater<int>, rb_tree_tag,tree_order_statistics_node_update> 

class Solution {
public:
    int numTeams(vector<int>& rating) {
        ordered_set leftSet, rightSet;
        ordered_set_high leftHighSet, rightHighSet;
        
        int n = rating.size();
        vector<int>leftLow(n), leftHigh(n), rightLow(n), rightHigh(n);
        for(int i =0 ; i < n ; i++) {
            leftLow[i] = leftSet.order_of_key(rating[i]);
            leftHigh[i] = leftHighSet.order_of_key(rating[i]);

            leftSet.insert(rating[i]);
            leftHighSet.insert(rating[i]);

        }

        for(int i = n-1; i >= 0 ;i--) {
            rightLow[i] = rightSet.order_of_key(rating[i]);
            rightHigh[i] = rightHighSet.order_of_key(rating[i]);

            rightSet.insert(rating[i]);
            rightHighSet.insert(rating[i]);
    
        }
        int res=0;
        
        for(int i = 0; i < n ; i++) {
            res += leftLow[i] * rightHigh[i];

            res += leftHigh[i] * rightLow[i];
        }

        return res;
    }
};