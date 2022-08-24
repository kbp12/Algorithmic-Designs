<h2><a href="https://leetcode.com/problems/winning-candidate/">574. Winning Candidate</a></h2><h3>Medium</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Table: <code>Candidate</code></p>

<pre>+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
+-------------+----------+
id is the primary key column for this table.
Each row of this table contains information about the id and the name of a candidate.
</pre>

<p>&nbsp;</p>

<p>Table: <code>Vote</code></p>

<pre>+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| candidateId | int  |
+-------------+------+
id is an auto-increment primary key.
candidateId is a foreign key to id from the Candidate table.
Each row of this table determines the candidate who got the i<sup>th</sup> vote in the elections.
</pre>

<p>&nbsp;</p>

<p>Write an SQL query to report the name of the winning candidate (i.e., the candidate who got the largest number of votes).</p>

<p>The test cases are generated so that <strong>exactly one candidate wins</strong> the elections.</p>

<p>The query result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 
Candidate table:
+----+------+
| id | name |
+----+------+
| 1  | A    |
| 2  | B    |
| 3  | C    |
| 4  | D    |
| 5  | E    |
+----+------+
Vote table:
+----+-------------+
| id | candidateId |
+----+-------------+
| 1  | 2           |
| 2  | 4           |
| 3  | 3           |
| 4  | 2           |
| 5  | 5           |
+----+-------------+
<strong>Output:</strong> 
+------+
| name |
+------+
| B    |
+------+
<strong>Explanation:</strong> 
Candidate B has 2 votes. Candidates C, D, and E have 1 vote each.
The winner is candidate B.
</pre>
</div>