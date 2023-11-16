<h2><a href="https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/">1846. Maximum Element After Decreasing and Rearranging</a></h2><h3>Medium</h3><hr><p>You are given an array of positive integers <code>arr</code>. Perform some operations (possibly none) on <code>arr</code> so that it satisfies these conditions:</p>
<ul>
  <li>The value of the <strong>first</strong> element in <code>arr</code> must be <code>1</code>.</li>
  <li>The absolute difference between any 2 adjacent elements must be <strong>less than or equal</strong> to <code>1</code>. In other words, <code>abs(arr[i] - arr[i - 1]) <= 1</code> for each <code>i</code> where <code>1 <= i < arr.length</code> <strong>(0-indexed)</strong>. <coode>abs(x)</code> is the absolute value of <code>x</code>.</li>
</ul>

<p>There are 2 types of operations that you can perform any number of times:</p>
<ul>
  <li><strong>Decrease</strong> the value of any element of <code>arr</code> to a <strong>smaller positive integer.</strong></li>
  <li><strong>Rearrange</strong> the elements of <code>arr</code> to be in any order.</li>
</ul>

<p>Return the <strong>maximum</strong> possible value of an element in <code>arr</code> after performing the operations to satisfy the conditions.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,2,1,2,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can satisfy the conditions by rearranging arr so it becomes [1,2,2,2,1].
The largest element in arr is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [100,1,1000]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One possible way to satisfy the conditions is by doing the following:
1. Rearrange arr so it becomes [1,100,1000].
2. Decrease the value of the second element to 2.
3. Decrease the value of the third element to 3.
Now arr = [1,2,3], which satisfies the conditions.
The largest element in arr is 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,3,4,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The array already satisfies the conditions, and the largest element is 5.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>arr.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], u<sub>i</sub>, v<sub>i</sub> &lt;= 10<sup>9</sup></code></li>

</ul>
