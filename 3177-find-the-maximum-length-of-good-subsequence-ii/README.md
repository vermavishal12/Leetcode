<h2><a href="https://leetcode.com/problems/find-the-maximum-length-of-a-good-subsequence-i">3176. Find the Maximum Length of a Good Subsequence I</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> and a  <strong>non-negative</strong> integer <code>k</code> A sequence of integers <code>seq</code> is called <code>good</code> if there are <strong>at most</strong> <code>k</code> indices <code>i</code> in the range <code>[0, seq.length - 2]</code> such that <code>seq[i] != seq[i + 1]</code>.</p>

<p>Return the <strong>maximum</strong> possible length of a <strong>good</strong> subsequence of <code>nums</code>.</p>



<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,1,1,3], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong> The maximum length subsequence is <code>[1,2,1,1]</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3,4,5,1], k = 0
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum length subsequence is [1,1].
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5*10<sup>3</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= min(nums.length, 50)</code></li>
</ul>
