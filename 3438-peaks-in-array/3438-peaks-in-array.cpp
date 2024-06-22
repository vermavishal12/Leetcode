#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e6;
class Solution {
public:

    ll arr[N], tree[N];

    void buildTree(ll low, ll high, ll idx) {
        if(low == high) {
            tree[idx] = arr[low];
            return;
        }
        ll mid = (low+high)/2;
        buildTree(low,mid,idx*2 + 1);
        buildTree(mid+1,high,idx*2 + 2);
        tree[idx] = tree[idx*2 + 1] + tree[idx*2 + 2];
    }


    void update(ll low, ll high, ll left, ll right, ll idx, ll val) {
        if(low == left && high == right) {
            arr[left] = val;
            tree[idx] = val;
            return;
        }

        if(high < left || low > right)return;

        ll mid = (high+low)/2;
        update(low,mid, left, right, 2*idx + 1,val) ,
        update(mid+1,high,left,right, 2*idx + 2,val);
        tree[idx] = tree[idx*2 + 1] + tree[idx*2 + 2];
    }

    ll getSum(ll low, ll high, ll left, ll right, ll idx){
        if(low >= left && high <= right) {
            return tree[idx];
        }

        if(high < left || low > right)return 0;

        ll mid = (high+low)/2;

        return getSum(low,mid,left, right,2*idx + 1) + 
                getSum(mid+1,high,left,right,2*idx + 2);
    }
    
    void print(){
        // for(int i = 0; i < 4 ; i++) {
        //     cout<<arr[i]<<" ";
        // }
        for(int i = 0; i < 8 ; i++) {
            cout<<tree[i]<<" ";
        }
        cout<<"\n";
    }
    
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;

        ll n = nums.size();
        for(ll i =0; i < n*2 ; i++) {
            arr[i] = 0;
        }

        for(ll i = 1; i < n-1 ; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                arr[i] = 1; 
            }
        }

        buildTree(0,n-1,0);
        
        for(auto q: queries) {
            if(q[0] == 1) {
                int val = getSum(0,n-1,q[1]+1,q[2]-1, 0);
                res.push_back(val);
            }else {
                ll val, idx = q[1];
                nums[idx] = q[2];
                if(idx > 0 && idx < n-1) {
                    val = ((nums[idx] > nums[idx+1]) && (nums[idx] > nums[idx-1]));
                    // cout<<"a = "<<val<<" ";
                    update(0,n-1,idx,idx,0,val);
                    if (idx > 1) {

                        val = ((nums[idx-1] > nums[idx-2]) && (nums[idx-1] > nums[idx])) ;
                        // cout<<val<<" ";
                        update(0,n-1,idx-1,idx-1,0,val);
                    }
                    if (idx < n-2){

                        val = ((nums[idx+1] > nums[idx]) && (nums[idx+1] > nums[idx+2]));
                        // cout<<val;
                        update(0,n-1,idx+1,idx+1,0,val);
                    }
                    // cout<<"\n";
                }else if(idx > 0) {
                    if (idx > 1 ){
                        
                         val = ((nums[idx-1] > nums[idx-2]) && (nums[idx-1] > nums[idx])) ;
                        // cout<<"b = "<<val<<"\n";
                        update(0,n-1,idx-1,idx-1,0,val);
                    }
                } else if(idx < n-1) {
                    
                    if (idx < n-2){
                        val = ((nums[idx+1] > nums[idx]) && (nums[idx+1] > nums[idx+2]));
                        // cout<<"c = "<<val<<"\n";
                        update(0,n-1,idx+1,idx+1,0,val);
                    }
                }
            }
            // print();
        }
        return res;
    }
};

/*
5 3 8 4
0 0 1 0

2 3 8 4
0 0 1 0
*/