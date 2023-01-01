## test2.cpp 
generate all prime gap in [2 .. 10^6]

## test3.cpp
Use result of test2.cpp and try to represent all prime gaps by char string.
Because LeetCode.com cannot accept large text file. 


## 
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


