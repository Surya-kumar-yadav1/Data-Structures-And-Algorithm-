/* 
Problem: 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points 
Difficulty: Medium 
Topic: Linked List 
 
Approach: 
- Traverse the linked list while keeping track of the previous, current, and next nodes. 
- A node is a critical point if it is either a local maximum or a local minimum. 
- Store the index of the first critical point and keep updating the last critical point. 
- For every new critical point, calculate the distance from the previous critical point and 
  update the minimum distance. 
- The maximum distance is the difference between the last and first critical point. 
- If there are fewer than two critical points, return {-1, -1}. 
 
Time Complexity: O(n) 
Space Complexity: O(1) 
*/ 
 
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head->next;

        int idx = 1;

        int firstCritical = -1;
        int lastCritical = -1;
        int minDist = INT_MAX;

        while (cur->next) {
            ListNode* next = cur->next;

            bool isMax = cur->val > prev->val && cur->val > next->val;
            bool isMin = cur->val < prev->val && cur->val < next->val;

            if (isMax || isMin) {
                if (lastCritical == -1) {
                    firstCritical = idx;
                } 
                else {
                    minDist = min(minDist, idx - lastCritical);
                }

                lastCritical = idx;
            }

            prev = cur;
            cur = next;
            idx++;
        }

        if (firstCritical == -1 || firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDist = lastCritical - firstCritical;

        return {minDist, maxDist};
    }
};
