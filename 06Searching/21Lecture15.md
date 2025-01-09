# allocate the books
## Problem
Given n books and an array denoting pages each book contains, and m number of students. Allocate these n books to m students such that the total number of pages assigned to any student overall is minimum possible. All books should get assigned, and every student must get at least one book. The allotment of books must be done as contiguous subarray chunk, and a book must entirely be assigned to a single student.

### Solution
#### Key Insights and Approach
1. Why Binary Search on Maximum Pages?
    - Since the goal is to minimize the maximum pages allocated to any one student, we can think of a binary search approach on this maximum allocation.
    - We start with a possible range of page allocations:
        - The lower bound (`low`) is the maximum number of pages in any single book because each student will need to read at least one book, and no student can receive fewer pages than the largest book.
        - The upper bound (`high`) is the total sum of all pages in the books, representing the scenario where only one student reads all the books.

2. Checking Feasibility of a Page Allocation with Binary Search
    - For a given candidate maximum page allocation (let’s call it `mid`), we determine if it's possible to allocate books such that no student reads more than `mid` pages.
    - To do this, we:
        - Traverse the array of books and keep assigning books to the current student until the assigned pages exceed `mid`.
        - At that point, we assign the next student to continue the allocation, resetting the current page count to the current book.
    - If we need more than `M` students for this allocation, then `mid` is too low. Otherwise, it’s a feasible allocation.

3. Binary Search to Find the Minimum Feasible Maximum
    - If a candidate `mid` is feasible, it means we might be able to reduce the maximum page allocation further, so we adjust our binary search to try a smaller maximum by moving `high` to `mid - 1`.
    - If `mid` is not feasible, we need to increase the allocation to make it feasible, so we set `low` to `mid + 1`.

4. Edge Cases
    - Fewer books than students: Each student would get one book in this case, with the maximum page allocation being the book with the highest pages.
    - All books with the same number of pages: Binary search will converge quickly as any split is feasible if the total pages are within limits.

### Solution Steps
1. Set `low` to the maximum page count in the array, and `high` to the total sum of pages.
2. Perform a binary search within this range to find the minimum feasible `mid`.
3. In each iteration of the binary search, check if distributing books with `mid` as the maximum page load per student is feasible.
4. Continue adjusting `low` and `high` until you find the smallest feasible maximum.

### Code
```java
import java.util.Scanner;
public class BookAllocation {
    // Function to check if it is possible to allocate books such that no student reads more than maxPages
    private static boolean isFeasible(int[] books, int students, int maxPages) {
        int studentCount = 1;  // Start with one student
        int currentPages = 0;  // Pages allocated to the current student

        for (int pages : books) {
            if (currentPages + pages > maxPages) {
                studentCount++;  // Assign new student
                currentPages = pages;  // Reset page count to current book

                // If the number of students exceeds the limit, return false
                if (studentCount > students) return false;
            } else currentPages += pages;
        }
        return true;  // Allocation feasible with given maxPages
    }

    // Function to find the minimum possible maximum pages any student has to read
    public static int findMinPages(int[] books, int students) {
        if (students > books.length) return -1;  // More students than books is an invalid case

        int low = Integer.MIN_VALUE;  // Initialize to the max page count of a single book
        int high = 0;  // Initialize to the total pages

        for (int pages : books) {
            low = Math.max(low, pages);
            high += pages;
        }

        int result = high;  // Initialize result to the upper bound

        // Perform binary search between low and high
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if it is possible to allocate with maxPages as `mid`
            if (isFeasible(books, students, mid)) {
                result = mid;  // `mid` is a feasible solution, try for smaller maximum
                high = mid - 1;
            } else low = mid + 1;  // `mid` is too small, try a larger maximum
        }
        return result;
    }
}
```

### Discussion on the Approach
- **Binary Search on the Answer**:
    - Since the solution space is sorted (more pages mean fewer feasible partitions), binary search is efficient.
    - The binary search allows us to quickly converge on the optimal maximum page allocation.

- **Greedy Partitioning**:
    - The feasibility check uses a greedy approach, where it tries to allocate the maximum possible pages to each student before moving to the next student.

### Complexity Analysis
- Time Complexity:
    - Sorting is not required in this problem, so the primary complexity comes from the binary search on the maximum pages.
    - Each binary search iteration runs `isFeasible`, which has `O(n)` complexity.
    - Overall complexity: `O(n log(sum of pages))`, where `sum of pages` is the upper bound in binary search.

- Space Complexity: `O(1)` additional space, aside from input storage.
