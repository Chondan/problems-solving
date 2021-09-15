# Dynamic Programming

- Identifying and solving subproblems
- Using subproblems together to solve larger problem

5 steps:
For example: Longest Increasing Subsequence (LIS)
[3, 1, 8, 2, 5]

1. Visualize example
2. Find an appropriate subproblem
3. Find relationship among subproblems 
	- LIS[4] = 1 + max{LIS[0], LIS[1], LIS[3]} = 3
4. Generalize the relationship
	- LIS[n] = 1 + max{LIS[k] | k < n, A[k] < A[n]}
5. Implement by solving subproblems in order

---

# Dynamic Programming - Learn to Solve Algorithmic Problems & Coding Challenges
- Memoization Recipe
	- Example Problems
		- fibonaccit memoization
		- gridTraveler memoization
		- canSum
	- Alivin's Memoization Recipe
		1. Make it work.
			- visualize the problem as a tree
			- implement the tree using recursion
			- test it
		2. Make it efficient.
			- add a memo object
			- add a base case to return memo values
			- store return values into the memo
