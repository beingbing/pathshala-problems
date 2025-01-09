### Key Observations on Binary Search
fundamental insights while applying binary search:
1. **Requirement of an Ordered Search Space:** the search space should be ordered somehow, which helps us in deducing which half to explore.

2. **Behavior When the Target Is Not Present:** If the target element isn’t present in the search space, binary search will exit with:
- **`low`** pointing to the position where the target could be inserted to maintain order. It points to the smallest element that is greater than the target.
- **`high`** pointing to the element just smaller than the target.

This observation makes binary search useful for applications where insertion points are needed:
- If the target were to be inserted, its position would be at `low`.
- If `low` equals the array’s length, the target would be the new last element.

This positioning behavior is especially valuable in sorted arrays when working with functions like -
- `ceil` (smallest element greater than or equal to the target) and
- `floor` (largest element smaller than or equal to the target).
