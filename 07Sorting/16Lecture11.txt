~~ processing range queries ~~

given an arr with n elements initially all zero.
given q queries, each query is a pair containing details about 2 indexes
for each query +1 for each query from q.first till q.second
give state of array after execution of all the queries.

now to solve this problem let's take a simpler one first.
assume we got each query in which we need to +1 from 0 till given index
and then return the final state.

what we can do here is,
- we can create an array
- for each query just do +1 for that index which is specified in query
- and then take suffix sum of that array
- that suffix sum will be our answer

for (i{0}; i<q; i++) {
    a[q]++
}
for (i{n-2}; i>=0; i++)
    sufArr[i] = a[i]+sufArr[i+1]


similarly,
if we go back to original problem

what we can do here is,
- we can create an array
- for each query just do +1 for q.second index which is specified in query
  and, -1 for q.first-1 index
- and then take suffix sum of that array
- that suffix sum will be our answer

for (i{0}; i<q; i++) {
    a[q.second]++
    if (q.first > 0) a[q.first-1]--
}
for (i{n-2}; i>=0; i++)
    sufArr[i] = a[i]+sufArr[i+1]



This question comes under category of range queries
it's a separate domain for approaching a problem
