<h2><a href="https://leetcode.com/problems/maximum-subsequence-score/">2542. Maximum Subsequence Score</a></h2><h3>Medium</h3><hr><div>

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code> of equal length <code>n</code> and a positive integer <code>k</code>. You must choose a <strong>subsequence</strong> of indices from <code>nums1</code> of length <code>k</code>.</p>

<p>For chosen indices <code>i0</code>, <code>i1</code>, ..., <code>i(k-1)</code>, your <strong>score</strong> is defined as:</p>

<ul>
    <li>The sum of the selected elements from <code>nums1</code> multiplied with the minimum of the selected elements from <code>nums2</code>.</li>

</ul>
<ul>
    <li>It can defined simply as: <code>(nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1])</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> possible score.</p>

<p>A <strong>subsequence</strong> of indices of an array is a set that can be derived from the set <code>{0, 1, ..., n-1}</code> by deleting some or no elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
<strong>Output:</strong> 12
<strong>Explanation:</strong> The four possible subsequence scores are:
- We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
- We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
- We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
- We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
Therefore, we return the max score, which is 12. 

</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
<strong>Output:</strong> 30
<strong>Explanation:</strong> 
Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li>n == nums1.length == nums2.length<li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
    <li><code>0 &lt;= nums1[i] , nums2[i] &lt;= 10<sup>5</sup></code></li>
    <li><code>1 &lt;= k &lt;= n</code></li>
</ul>
</div>