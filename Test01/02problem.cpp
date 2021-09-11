/*

Bob is participating in a cycle race whose track follows a unique pattern.The track is shaped like an X - Y plane,
with four directions. Nort, East, South, and West. Two important terms to note in this race are round and lap.

Bob starts with a lap that covers 1-unit distance each in all four directions, then a second lap with the same
distance in any three directions, and so on till a fourth lap in any one direction. This entire pattern of 4 laps
thus constitutes a round. As soon as one round ends, the distance to be covered in the new round increases by one,
in the same pattern as before (2 units in round 2 instead of 1 unit in round 1).

You are given T testcases where each testcase contains a positive integer N. Find the sum of all the distance
travelled from lap 1 to N.

Input Format -
1. The first line of input contains a single integer T, the number of test cases.
2. Following T lines contains a positive interger N, the number of laps Bob needs to travel.

Output Format -
1. For each testcase, print the sum of all distance travelled from lap 1 to N.
2. Remember to use unsigned long long int and fast input/output.

sample input: 
2
5
7
sample output:
18 (4*1 + 3*1 + 2*1 + 1*1 + 4*2)
28 (4*1 + 3*1 + 2*1 + 1*1 + 4*2 + 3*2 + 2*2)

*/

/*

Answer:
full rounds, f = laps / 4

ans = ans + (10*f*(f+1))/2;

remaining laps, r = lap % 4;

i = 4;
while (r--) {
    ans += (f+1)*i;
    i--;
}

return ans;

TC = O(Q) // Q => queries

*/