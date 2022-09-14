<h2><a href="https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/">2031. Count Subarrays With More Ones Than Zeros</a></h2><h3>Medium</h3><hr><div><p>You are given a binary array <code>nums</code> containing only the integers <code>0</code> and <code>1</code>. Return<em> the number of <strong>subarrays</strong> in nums that have <strong>more</strong> </em><code>1</code>'<em>s than </em><code>0</code><em>'s. Since the answer may be very large, return it <strong>modulo</strong> </em><code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,1,0,1]
<strong>Output:</strong> 9
<strong>Explanation:</strong>
The subarrays of size 1 that have more ones than zeros are: [1], [1], [1]
The subarrays of size 2 that have more ones than zeros are: [1,1]
The subarrays of size 3 that have more ones than zeros are: [0,1,1], [1,1,0], [1,0,1]
The subarrays of size 4 that have more ones than zeros are: [1,1,0,1]
The subarrays of size 5 that have more ones than zeros are: [0,1,1,0,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No subarrays have more ones than zeros.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The subarrays of size 1 that have more ones than zeros are: [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>
</div>