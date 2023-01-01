#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int right=1e6;//2,3,5,7,11 ... primegaps ={ 1, 2, 2, 4 }
    vector<int> is_primes = vector<int>(right+1,1);
    is_primes[0] = is_primes[1] = 0;
    
    //printf("primes ={%d, ",2);
    printf("vector<int> primegaps = { ");
    int prev_prime = 2;
    for(int i = 3;i<=right;i+=2) {
        if(is_primes[i]==1) {
            for(int j = i+(i+i);j<=right;j+=(i+i)) {
                is_primes[j] = 0;
            }
            printf("%d,",i-prev_prime);
            prev_prime = i;
        }
    }
    printf("};\n");

    return 0;
}
