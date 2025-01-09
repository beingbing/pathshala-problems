~~ finding minimum XOR ~~

given array, find min(a[i]^a[j]), where i != j and 0 <= i < j < n

brute-force approach:
There will be nC2 pairs for which we need to evaluate the XOR

ans = INT_MAX;
for (i = 0; i < n; i++) {
  for (int j = i; j < n; j++) {
    ans = min(ans, a[i]^a[j]);
  }
}
return ans;

TC = O(n^2)
SC = O(1)

optimized approach:
hypothesis 1: if two smallest elements are chosen will it give the smallest XOR ?
testing hypothesis:
we can check that it is not correct, if the individual difference between two chosen elements is large then the bit which is different will be farther on the left (more significant). Thus their XOR will be a bigger number.

Hence we need to find two numbers such that the bit which is different in binary representation of both of them is the smallest possible or in other words, as least significant as possible.

Hence two adjacent elements in a sorted array may have the smallest XOR if difference between them is smallest possible.

we reached to this solution by using mathematical exptrapolation approach where you take a smaller set of cases find the possible answer candidates, find a relation among them which might be responsible for answer and then extrapolate your hypothesis on a bigger set. if found true you have algorithm which can lead to your answer.

