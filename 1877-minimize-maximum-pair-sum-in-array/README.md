<h2><a href="https://leetcode.com/problems/minimize-maximum-pair-sum-in-array">1877. Minimize the Maximum Pair Sum in Array</a></h2><h3>Medium</h3><hr>

<p>The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.</p>

<ul>
	<li>For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.</li>
</ul>

<p>Given an array <code>nums</code> of <strong>even</strong> length <code>n</code>, pair up the elements of <code>nums</code> into <code>n / 2</code> pairs such that:</p>

<ul>
	<li>Each element of <code>nums</code> is in <strong>exactly one</strong> pair, and</li>
	<li>The <strong>maximum pair sum </strong>is <strong>minimized.</strong></li>
</ul>

<p>Return the minimized <strong>maximum pair sum</strong> after optimally pairing up the elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,5,2,3]
<strong>Output:</strong> 7
<strong>Explanation:</strong> The elements can be paired up into pairs (3,3) and (5,2).
The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,5,4,2,4,6]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The elements can be paired up into pairs (3,5), (4,4), and (6,2).
The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == n</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> is <strong>even</strong></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
