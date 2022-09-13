<h2><a href="https://leetcode.com/problems/encode-string-with-shortest-length/">471. Encode String with Shortest Length</a></h2><h3>Hard</h3><hr><div><p>Given a string <code>s</code>, encode the string such that its encoded length is the shortest.</p>

<p>The encoding rule is: <code>k[encoded_string]</code>, where the <code>encoded_string</code> inside the square brackets is being repeated exactly <code>k</code> times. <code>k</code> should be a positive integer.</p>

<p>If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return <strong>any of them</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaa"
<strong>Output:</strong> "aaa"
<strong>Explanation:</strong> There is no way to encode it such that it is shorter than the input string, so we do not encode it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaaaa"
<strong>Output:</strong> "5[a]"
<strong>Explanation:</strong> "5[a]" is shorter than "aaaaa" by 1 character.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aaaaaaaaaa"
<strong>Output:</strong> "10[a]"
<strong>Explanation:</strong> "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 150</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>
</div>