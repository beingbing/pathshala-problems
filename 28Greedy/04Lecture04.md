# Activity Selection - 3: `k` Persons
## Problem Statement
Given `n` activities and `k` persons, find the maximum number of non-overlapping activities that can be collectively performed.

## Solution
### Key Insight:
1. Each person can perform non-overlapping activities.
2. To maximize the total number of activities performed:
    - Prioritize activities that finish earlier, as they leave more room for subsequent activities.
    - Allocate each person to activities greedily.

#### Approach:
1. **Sort Activities by End Time**: Sorting activities based on their finish time ensures we always consider the activity that leaves the maximum room for future activities.
2. **Greedy Allocation for Each Person**: Assign activities to persons such that each person picks the earliest finishing activity available that they can perform next.
3. **Maximize Activities**: Use a priority queue (min-heap) to track the earliest available time of each person, enabling efficient allocation of activities.

#### Complexity:
- **Time Complexity:** O(n log n + n log k) (due to balanced BST operations for `k` persons).
- **Space Complexity:** O(k)

### Summary of Greedy Approaches:
1. **Single Person:** Sort by end time, iteratively select activities.
2. **Two Persons:** Assign activities to the person with the earliest available end time.
3. **`k` Persons:** Use a PriorityQueue for efficient assignment to the earliest available person.
