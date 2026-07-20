<h2><a href="https://www.geeksforgeeks.org/problems/find-number-of-closed-islands/1">Count Groups of 1's Surrounded by 0's</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a binary matrix <strong>mat[][]</strong> of size <strong>n x m</strong>, where <strong>1</strong> represents an active cell and <strong>0</strong> represents an inactive cell, count the number of groups of connected 1s that are completely surrounded by 0s.</span></p>
<p><span style="font-size: 18px;">Two 1 cells are considered connected if they share a side (up, down, left, or right).</span></p>
<p><span style="font-size: 18px;">A group is counted only if none of its cells lie on the boundary of the matrix.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong><span style="font-size: 18px;">Input:</span> </strong></span><span style="font-size: 18px;">n = 5, m = 8, 
mat[][] =</span> <span style="font-size: 14pt;">[[</span><span style="font-size: 18px;">0, 0, 0, 0, 0, 0, 0, 1],&nbsp;
          [0, 1, 1, 1, 1, 0, 0, 1],&nbsp;
          [0, 1, 0, 1, 0, 0, 0, 1],&nbsp;
          [0, 1, 1, 1, 1, 0, 1, 0],&nbsp;
          [1, 0, 0, 0, 0, 1, 0, 1]]</span>
<span style="font-size: 18px;"><strong>Output: </strong>2
<strong>Explanation</strong>:
</span><span style="font-size: 18px;">mat[][] = [[0, 0, 0, 0, 0, 0, 0, 1],&nbsp;
          [0, <strong>1, 1, 1, 1, </strong>0, 0, 1],&nbsp;
          [0, <strong>1</strong>, 0, <strong>1</strong>, 0, 0, 0, 1],&nbsp;
          [0, <strong>1, 1, 1, 1, </strong>0, <strong>1</strong>, 0],&nbsp;
          [1, 0, 0, 0, 0, 1, 0, 1]]<br><br>There are 2 groups of connected 1s that are completely surrounded by 0s and do not touch the boundary of the matrix.
The other groups are not counted because they are connected to the boundary of the matrix. </span>
</pre>
<pre><span style="font-size: 18px;"><strong><span style="font-size: 18px;">Input:</span> </strong></span><span style="font-size: 18px;">n = 3, m = 3,
mat[][] = [[1, 0, 0],
          [0, 1, 0],
          [0, 0, 1]]</span>
<span style="font-size: 18px;"><strong>Output: </strong></span><span style="font-size: 18px;">1<strong><br>Explanation:<br></strong>mat[][] = [[1, 0, 0],<br>         [0, <strong>1</strong>, 0],<br>         [0, 0, 1]]<br><br>Only the cell at the center forms a valid group because it does not touch the boundary and is surrounded by 0s.
The other 1s lie on the boundary of the matrix, so they are not counted.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 500<br></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;<code>union-find</code>&nbsp;