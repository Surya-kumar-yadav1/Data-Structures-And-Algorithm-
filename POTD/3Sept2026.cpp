/* 
Problem: 3876. Construct Uniform Parity Array II 
Difficulty: Medium 
Topic: Array, Greedy, Parity 
 
Approach: 
- Store the minimum even number and the minimum odd number in the array. 
- For an element nums1[i], we can either keep it unchanged or subtract a 
  smaller element from it. 
- To make nums2 elements uniformly odd/even, the key observation is that 
  the smallest element determines whether every element can be made odd. 
- If the minimum odd element is smaller than the minimum even element, 
  every element can be made odd: 
      - Odd elements can be kept as they are. 
      - Even elements can subtract the smaller odd element, producing an odd number. 
- If there is no odd element at all, all elements are already even, so the 
  answer is true. 
- Otherwise, if the minimum even element is smaller than the minimum odd 
  element, an even element cannot be made odd using a smaller odd element, 
  so constructing a uniform-parity array is impossible. 
 
Time Complexity: O(n) 
Space Complexity: O(1) 
*/ 
 
class Solution {
public:
    bool uniformArray(auto& A) {
        uint32_t x[2] = {-1u, -1u};

        for (uint32_t a : A)
            x[a & 1] = min(x[a & 1], a);

        return x[1] < x[0] | x[1] == -1u;
    }
};
