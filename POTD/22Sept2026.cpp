/* 
Problem: 3525. Find X Value of Array II
Difficulty: Hard
Topic: Segment Tree, Modular Arithmetic

Approach:
- For every segment, store:
  1. `prod` = product of all elements in the segment modulo k.
  2. `freq[r]` = number of subarrays in the segment whose product
     has remainder `r` modulo k.
- For a single element, its product remainder is `nums[i] % k`,
  so `freq[remainder] = 1`.
- While merging two segments:
  - Keep the product of both segments.
  - All subarrays completely inside the left segment remain unchanged.
  - For every subarray in the right segment with remainder `r`,
    multiplying it by the complete left segment changes its
    remainder to `(left.prod * r) % k`.
- Use a Segment Tree so that:
  - Updating one element takes O(log n).
  - Querying the range `[start, n-1]` takes O(k log n).
- After updating `nums[index]`, query the required suffix.
  The answer is `freq[x]`.

Time Complexity: O((n + q) * k log n)
Space Complexity: O(n * k)
*/

class Solution {
public:
    struct Node {
        int prod;
        array<int, 5> freq;

        Node() : prod(1) {
            freq.fill(0);
        }
    };

    int k;
    vector<Node> tree;
    vector<int> nums;

    // Merge two nodes
    Node merge(const Node& L, const Node& R) {
        Node res;

        // Product of the complete segment
        res.prod = (1LL * L.prod * R.prod) % k;

        // Subarrays completely inside the left segment
        res.freq = L.freq;

        // Subarrays that use the right segment
        for (int r = 0; r < k; ++r) {
            if (R.freq[r]) {
                int nr = (1LL * L.prod * r) % k;
                res.freq[nr] += R.freq[r];
            }
        }

        return res;
    }

    // Build the Segment Tree
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].prod = nums[tl] % k;
            tree[v].freq[tree[v].prod] = 1;
            return;
        }

        int tm = (tl + tr) / 2;

        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);

        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    // Update one element
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].prod = val % k;
            tree[v].freq.fill(0);
            tree[v].freq[tree[v].prod] = 1;
            return;
        }

        int tm = (tl + tr) / 2;

        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);

        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }

    // Query a range
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return Node();

        if (l == tl && r == tr)
            return tree[v];

        int tm = (tl + tr) / 2;

        return merge(
            query(v * 2, tl, tm, l, min(r, tm)),
            query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;
        this->nums = nums;

        int n = nums.size();

        tree.assign(4 * n, Node());

        // Build the tree
        build(1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            // Apply the update
            update(1, 0, n - 1, idx, val);

            // Query nums[start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            // Number of subarrays with product % k == x
            ans.push_back(res.freq[x]);
        }

        return ans;
    }
};
