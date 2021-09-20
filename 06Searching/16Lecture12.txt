~~ kth smallest in a matrix ~~

given an n*n matrix, with each row sorted, find kth smallest element

upper_bound -> returns you the pointer of element which is just greater than m

TC = O(nlognlog(max-min))

in countNums function TC = O(nlogn), as you can do a BS for each row, and there are n rows hence, nlogn

then, log(max-min) is usual

ans to find max and min we can do it in o(n) by going through first and last column
