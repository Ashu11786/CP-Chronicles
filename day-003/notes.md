### Approach
We use DFS with backtracking to simulate the path from (0,0) to (6,0).
At each step, we follow the given direction or try all possible directions if the character is '?'.
We track visited cells to avoid revisiting.

Pruning is applied to avoid dead ends where the grid becomes split into unreachable parts.

### Time Complexity
Efficient due to pruning (passes all constraints).

### Space Complexity
O(7 × 7) for visited grid and recursion stack.

### Learnings
Pruning is essential in backtracking problems to avoid TLE.
