~~ using bitwise operators ~~

checking a number even/odd using bitwise operators
num & 1 == 1 odd
num & 1 == 0 even



check if ith bit is 1/0 (set/unset)
num & (1 << i) == 1 set
               == 0 unset
or,
num & mask == 1/0 (set/unset)

Note: (1 << i) is known as mask



check if num is a power of 2
num & (num-1) == 0 true, is a power of 2
              == 1 false, not a power of 2
