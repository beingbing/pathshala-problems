~~ Introducing Time Complexity ~~

Question: How to represent the time taken by a code to execute ?
Answer: we have to represent it in a way that is hardware agnostic. so, time taken will be directly proportional to the number of operations. The number of operations will be directly proportional to the input size. So, time taken is directly proportional to the input size.

Example:
int arr[n], sum = 0, c = 0;  //  constant time operation, do not depend on input size
for (i: 0 to n) {       // n iteration for an input size of n
    sum += a[i]; c++;   // 2 addition, which again do not depend on input size hence constant
}

so, time taken = c + n*2c, where c = constant

here, we can see that the time taken is directly dependent on input size in a linear manner, hence, the time Complexity is of order n, which can be expressed as, TC = O(n)
