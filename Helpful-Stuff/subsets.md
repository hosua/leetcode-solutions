```
N = 3 (size of list)
1000 = 1<<N 

i = 0

0000 = i
_____ j vals
   1
  10
 100
   .
   .
0 & j ALWAYS == 0
{ }

i = 1
0001
____ j vals
   1 **
  10
 100
1000
   .
   .
   .
No more values of 1 & j will be nonzero
{1}

i = 2
0010
____ j vals
   1
  10 **
 100
1000
   .
   .
   .
No more values of 2 & j will be nonzero
{2}

i = 3
0011
____ j vals
   1 **
  10 **
 100
1000
   .
   .
   .
No more values of 3 & j will be nonzero
{1, 2}
```
