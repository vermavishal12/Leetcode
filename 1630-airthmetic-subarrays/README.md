<h2><a href="https://leetcode.com/problems/arithmetic-subarrays">1630. Arithmetic Subarrays</a></h2><h3>Medium</h3><hr>

<p>A sequence of numbers is called <strong>airthmetic</strong> if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence <code>s</code> is arithmetic if and only if <code>s[i+1] - s[i] == s[1] - s[0]</code> for all valid i.</p>

<p>For example, these <strong>airthmetic</strong> sequences: </p>
<ul>
	<li>1, 3, 5, 7, 9</li>
	<li>7, 7, 7, 7</li>
	<li>3, -1, -5, -9</li>
</ul>

<p>The following sequence is not <strong>airthmetic:</strong></p>
<ul>
	<li>1, 1, 2, 5, 7</li>
</ul>

<p>You are given an array of <code>n</code> integers, nums, and two arrays of m integers each, <code>l</code> and <code>r</code>, representing the <code>m</code> range queries, where the <code>i<sup>th</sup></code> query is the range <code>[l[i], r[i]]</code>. All the arrays are <strong>0-indexed</strong>.</p>

<p>Return a list of <code>boolean</code> elements <code>answer</code>, where <code>answer[i]</code> is <code>true</code> if the subarray <code>nums[l[i]], nums[l[i]+1], ... , nums[r[i]]</code> can be <strong>rearranged</strong> to form an <strong>arithmetic</strong> sequence, and <code>false</code> otherwise.</p>


<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
<strong>Output:</strong> [true,false,true]
<strong>Explanation: </strong>
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10], l = [0,1,6,4,8,7], r = [4,4,9,7,9,10]
<strong>Output:</strong> [false,true,false,false,true,true]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == l.length</code></li>
	<li><code>m == r.length</code></li>
	<li><code>2 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= m &lt;= 500</code></li>
	<li><code>0 &lt;= l[i] &lt; r[i] &lt; n</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>
