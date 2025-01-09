~~ special edition ~~

given n, number of people contesting an election
every contestant has an influence level which will be supplied by an array
- every contestant is also a voter and every voter is a contestant
- every contestant can vote multiple times
- contestant can't vote for himself
- i can vote for j iff s[i] >= s[i+1] + s[i+2] + ... + s[j-1]
or, s[i] >= s[j+1] + s[j+2] + s[j+3] + ... + s[i-1]

M1 -
- fixing ith person
- figuring out who all can vote for him
TC = O(n^2)

M2 -
- fixing ith person
- figuring out who all can be voted by i
    - for that we can use BS, need to find the farthest possible element, which can be voted by i
        or, the first element which can not be voted by i.
TC = O(nlogn)

code -
preArr;
tempArr;
for (i{0}; i<n; i++) {
    l = i+1, h = n-1
    while (l <= h) {
        m = (l+h)/2
        if (a[i] < preArr[m-1]-preArr[i]) h = m-1
        else {
            if (a[i] < preArr[m]-preArr[i]) {q2 = m; break;}
            else l = m+1
        }
    }
    l = 0, h = i-1
    while (l <= h) {
        m = (l+h)/2
        if (a[i] < preArr[i-1]-preArr[m]) h = m-1
        else {
            if (a[i] < preArr[i-1]-preArr[m+1]) {q1 = m; break;}
            else l = m+1
        }
    }
    tempArr[q2]++
    if (q1 > 0) a[q1-1]--
}
for (i{n-2}; i>=0; i++)
    sufArr[i] = a[i]+sufArr[i+1]
return sufArr