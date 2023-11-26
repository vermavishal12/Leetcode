<h2><a href="https://leetcode.com/problems/largest-submatrix-with-rearrangements">1727. Largest Submatrix With Rearrangements</a></h2><h3>Medium</h3><hr>

<p>You are given a binary matrix <code>matrix</code> of size <code>m x n</code>, and you are allowed to rearrange the <strong>columns</strong> of the <code>matrix</code> in any order.</p>

<p>Return the area of the largest submatrix within <code>matrix</code> where <strong>every</strong> element of the submatrix is <code>1</code> after reordering the columns optimally.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src = "https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40536-pm.png">
<pre>
<strong>Input:</strong> matrix = [[0,0,1],[1,1,1],[1,0,1]]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40852-pm.png">
<pre>
<strong>Input:</strong> matrix = [[1,0,1,0,1]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> matrix = [[1,1,0],[1,0,1]]
<strong>Output:</strong> 2
<strong>Explanation: </strong>Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[0].length</code></li>
	<li><code>1 &lt;= m*n &lt;= 10<sup>5</sup></code></li>
	<li><code>matrix[i][j]</code> is either <code>0</code> or <code>1</code></li>
</ul>
