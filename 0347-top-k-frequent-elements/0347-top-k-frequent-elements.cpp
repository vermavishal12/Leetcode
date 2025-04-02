class Solution {
public:
    vector<int>unique;
    unordered_map<int,int>freq;

    int partition(int left, int right, int pivot) {
        int pivotFreq = freq[unique[pivot]];

        swap(unique[pivot], unique[right]);

        int cntr = left;

        for(int i = left; i <= right ; i++) {
            if(freq[unique[i]] < pivotFreq) {
                swap(unique[cntr], unique[i]);
                cntr++;
            }
        }

        swap(unique[right], unique[cntr]);
        return cntr;
    }

    void helper(int start, int end, int kSmallest) {
        if(start == end)return;

        int pivot = start + rand() % (end - start + 1);

        pivot = partition(start, end, pivot);

        if(kSmallest == pivot) {
            return;
        } else if (kSmallest < pivot) {
            helper(start, pivot-1, kSmallest);
        } else {
            helper(pivot+1, end, kSmallest);
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n ; i++) {
            freq[nums[i]]++;
        }    

        for(auto num : freq) {
            unique.push_back(num.first);
        }

        helper(0,unique.size()-1,unique.size()-k);
        vector<int>topKFrequentElements(k);

        copy(unique.begin() + unique.size()- k, unique.end(), topKFrequentElements.begin());

        return topKFrequentElements;
    }
};