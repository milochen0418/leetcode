## test2.cpp 
generate all prime gap in [2 .. 10^6]  
I use this code to generate data and put it in `primegaps.hpp` file.  
so that another file can include it and use the `vector<int> primgaps = {...}`   
In this file I put all prime gap 1~10^6  aka 1e6  
## test3.cpp
Use result of test2.cpp and try to represent all prime gaps by char string.  
Because LeetCode.com cannot accept large text file.  

## test4.cpp
I include `primegaps.hpp` and the convert it into string. Because leetcode.com  
cannot let me put too much code for primegaps.hpp. Because growing speed of  prime gap is not too  
large and for the case 10^6, we can use char to represent all the prime gap in this range.  
So I generate ascii string and make sure echo ascii char can be shown. Thus, that's why we can  
use string to instread `vector<int> primegaps`. So the size of source code become smalle and   
leetcode.com can allow it. So we use primegaps_str.   


## Math  
If you google search "how many prime number between 1-1000000"  
then you cna get this relationship  
x	π(x)	x/(ln x - 1)  
...

That's mean there are O(N/logN) primes from 1 to N.   
Refer https://primes.utm.edu/howmany.html  
π(x) ~ x/ln x. (number of primes from 1 to x)  
p(n) ~ n ln n  (nth prime is about n ln n)  

Refer prime gap  
https://en.wikipedia.org/wiki/Prime_gap  
g(n) = O( log(p(n))^2 ). so 10^6 can let us to encrpyt prime gap into string's character.   

