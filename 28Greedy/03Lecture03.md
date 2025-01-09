# Activity Selection - 2: Two Persons
## Problem Statement
Given `n` activities with start and end times, find the maximum number of non-overlapping activities that two people can collectively perform. Each person can perform only one activity at a time.

## Solution
### Key Insight:
If an activity can be assigned to both persons, assign it to the one whose last activity ends earlier. This ensures future activities have better opportunities to fit.

#### Steps to Solve:
1. Pair the start and end times as `(start[i], end[i])`.
2. Sort activities by end time.
3. Maintain two variables (`endTime1` and `endTime2`) to track the end times of the activities assigned to the two persons.
4. Assign each activity to the person whose last activity ends earlier.

#### Complexity:
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)
