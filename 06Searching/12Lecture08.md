# Understanding Monotonic Functions and Binary Search

In computer science, monotonic functions play a crucial role in applying binary search to complex problem settings, especially when the dataset does not appear sorted at first glance.

Suppose, for an unsorted randomly generated array, we have a property on the basis of which a monotonicity can be established. The property function will give us a new transformed array on which Binary Search is applicable.

## Types of Monotonic Functions
1. **Monotonically Increasing**: A function `f(x)` is said to be monotonically increasing if, for any `x_1 < x_2`, `f(x_1) <= f(x_2)`.
2. **Monotonically Decreasing**: A function `f(x)` is monotonically decreasing if, for any `x_1 < x_2`, `f(x_1) >= f(x_2)`.

## Applying Binary Search to Monotonic Functions
The effectiveness of binary search relies on the presence of a **monotonic trend**—either explicitly or implicitly defined. In some problems, a monotonic property may not be evident from the original data but can be derived based on a specific condition or transformation.

### Key Idea
To use binary search:
- Identify a property or condition that can establish a monotonic relationship.
- Create a **property function** that transforms the array into a monotonically increasing or decreasing sequence based on that property.
- Apply binary search on this transformed sequence.

### Key Takeaway

Binary search can be applied even on unsorted data if we derive a monotonic property from a condition or transformation. By focusing on a monotonic trend through a **property function**, we can apply binary search effectively to a variety of complex scenarios.