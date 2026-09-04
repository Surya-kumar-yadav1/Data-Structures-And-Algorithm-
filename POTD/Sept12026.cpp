/* 
Problem: 3568. Minimum Moves to Clean the Classroom 
Difficulty: Medium 
Topic: Breadth-First Search, Bitmask, State Space 
 
Approach: 
- Assign a unique bit to every litter cell so that the collected litter can be 
  represented using a bitmask. 
- Use BFS because every move has the same cost, so the first time we collect 
  all litter gives the minimum number of moves. 
- A state is represented by (row, column, mask, energy). 
- For every valid move, decrease the energy by 1. If the new cell is 'R', 
  reset the energy back to the maximum value. 
- If the new cell contains litter, mark it as collected in the bitmask. 
- For each (row, column, mask), store the maximum energy seen so far. 
  A state with less or equal energy can be discarded because it cannot be 
  better than the already visited state. 
- When the mask contains all litter items, return the number of moves. 
- If BFS finishes without collecting all litter, return -1. 
 
Time Complexity: O(m * n * 2^k * energy) in the worst case 
Space Complexity: O(m * n * 2^k) 
*/ 
 
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));

        int k = 0;
        int sr = 0, sc = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } 
                else if (classroom[r][c] == 'L') {
                    id[r][c] = k++;
                }
            }
        }

        if (k == 0)
            return 0;

        int totalMask = (1 << k) - 1;

        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        struct State {
            int r, c, mask, e, moves;
        };

        queue<State> q;

        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int ne = cur.e - 1;

                if (ne < 0)
                    continue;

                int nmask = cur.mask;

                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                if (nmask == totalMask) {
                    return cur.moves + 1;
                }

                if (ne <= best[nr][nc][nmask])
                    continue;

                best[nr][nc][nmask] = ne;

                q.push({nr, nc, nmask, ne, cur.moves + 1});
            }
        }

        return -1;
    }
};
