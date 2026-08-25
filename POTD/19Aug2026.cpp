/*
Problem: 1386. Cinema Seat Allocation
Difficulty: Medium
Topic: Array, Bit Manipulation, Hash Map

Approach:
- Each row has 10 seats, but a 4-person family can only use the blocks:
    2-5, 4-7, and 6-9.
- Seats 1 and 10 do not affect the possible groups, so we only track
  seats 2 to 9 using an 8-bit mask.
- For every reserved seat from 2 to 9, set the corresponding bit in the
  row's mask.
- Rows with no reserved seats can always accommodate 2 families, so:
    (n - number_of_rows_with_reservations) * 2
  is added initially.
- For rows having reservations:
    1. If both blocks (2-5) and (6-9) are completely free, we can place
       2 families.
    2. Otherwise, if any one of (2-5), (4-7), or (6-9) is completely free,
       we can place 1 family.
    3. Otherwise, no family can be placed.
- Bit masks make checking these blocks very fast.

Masks:
    A = 2-5
    B = 4-7
    C = 6-9
    D = A | C

Time Complexity: O(m)
Space Complexity: O(m)
*/

class Solution {
public:
    static int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        const int m = reservedSeats.size();

        // Store reserved seats for each affected row as an 8-bit mask.
        unordered_map<int, uint8_t> seat;
        seat.reserve(m);

        for (auto& r : reservedSeats) {
            const int i = r[0] - 1;
            const int j = r[1] - 2;

            // Only seats 2 to 9 matter.
            if (j < 0 || j >= 8)
                continue;

            seat[i] |= 1 << j;
        }

        // Rows without relevant reservations can fit 2 families.
        int sz = seat.size();
        int cnt = (n - sz) * 2;

        // Masks for the possible 4-seat blocks:
        // A -> seats 2-5
        // B -> seats 4-7
        // C -> seats 6-9
        const uint8_t A = 15;
        const uint8_t B = 15 << 2;
        const uint8_t C = 15 << 4;

        // A and C together allow two families.
        const uint8_t D = A | C;

        for (auto [_, S] : seat) {
            // Invert mask so 1 means the seat is free.
            S = ~S;

            bool has2 = (S & D) == D;

            bool has1 = (!has2) &&
                        ((S & A) == A ||
                         (S & B) == B ||
                         (S & C) == C);

            cnt += has2 << 1;  // Add 2 if two families can fit.
            cnt += has1;       // Otherwise add 1 if one can fit.
        }

        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
