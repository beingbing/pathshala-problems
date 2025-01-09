# Activity Selection - 1: Single Person
## Problem statement
Given `n` activities with start and end times, find the maximum number of non-overlapping activities that a single person can perform, where only one activity can be performed at a time.

## Solution
### Key Insight:
- activities alligned such that next activities start-time is after previous activities end-time can only be picked.
- Sorting activities by their **end-time** ensures we select the earliest finishing activity, leaving the maximum room for subsequent activities.

#### Steps to Solve:
1. Pair the start and end times as `(start[i], end[i])`.
2. Sort the activities by their end time.
3. Iteratively select activities:
    - Pick an activity if its start time is greater than or equal to the end time of the last selected activity.
4. Return the count of selected activities.

#### Complexity:
- **Time Complexity:** O(n log n) (sorting the activities).
- **Space Complexity:** O(n) (storing the pairs).

### Note:
After sorting, first activity is always selected. In best case scenario, answer got excluding it can have count equal to what we have gotten by including it but can never go beyond it. As first activity is the earliest finishing one, hence it always contributes to both our answer and selection of next activity.
