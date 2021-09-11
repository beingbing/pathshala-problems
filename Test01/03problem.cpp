/*

given N number of bottles numbered from 1 to N. You will be given a number,
you need to remove bottle with that number, you can do this in two ways,
either remove the said bottle along with all the bottles in front of it.
or, remove the said bottle along with all the bottles after it.

complete this job such that, sum of all the bottles removed is minimum possible.

*/

/*

indices[arr[i]] = i

Answer:
ans = max(preSum[i], totalSum - preSum[i]);

*/