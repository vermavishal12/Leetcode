import java.util.*;

class Object {
    int number;
    int index;

    Object(int number, int index) {
        this.number = number;
        this.index = index;
    }
}

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        Object currMax = new Object(0, 0);
        Object[] suffix = new Object[n];
        Object[] prefix = new Object[n];
        Arrays.fill(suffix, new Object(0, 0));
        Arrays.fill(prefix, new Object(0, 0));

        int sum = 0;

        // Calculate suffix maximum
        for (int i = 0; i < k; i++) {
            sum += nums[n - i - 1];
        }
        currMax.number = sum;
        currMax.index = n - k;
        suffix[n - k] = new Object(sum, n - k);

        for (int i = n - k - 1; i >= 0; i--) {
            sum += nums[i] - nums[i + k];
            if (currMax.number <= sum) {
                currMax.number = sum;
                currMax.index = i;
            }
            suffix[i] = new Object(currMax.number, currMax.index);
        }

        // Reset sum for prefix calculation
        sum = 0;

        // Calculate prefix maximum
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        currMax.number = sum;
        currMax.index = 0;
        prefix[k - 1] = new Object(sum, 0);

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            if (sum > currMax.number) {
                currMax.number = sum;
                currMax.index = i - k + 1;
            }
            prefix[i] = new Object(currMax.number, currMax.index);
        }

        // Calculate the result
        sum = 0;
        for (int i = k; i < 2 * k; i++) {
            sum += nums[i];
        }

        int res = sum + prefix[k - 1].number + suffix[2 * k].number;
        int[] result = {0, k, suffix[2 * k].index};

        for (int i = 2 * k; i < n - k; i++) {
            sum += nums[i] - nums[i - k];
            if (res < sum + prefix[i - k].number + suffix[i + 1].number) {
                res = sum + prefix[i - k].number + suffix[i + 1].number;
                result[0] = prefix[i - k].index;
                result[1] = i - k + 1;
                result[2] = suffix[i + 1].index;
            }
        }

        return result;
    }
}
