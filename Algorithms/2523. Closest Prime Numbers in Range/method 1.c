#include <stdbool.h>

int *closestPrimes(int left, int right, bool *list){
    int min_gap = -1;
    int save_index_num1 = -1, save_index_num2 = -1;
    
    for(int i = left; i < right; i++){
        for(int j = i+1; j <= right; j++){
            printf("\n%d %d", i, j);
            if(list[i] && list[j]){
                if(min_gap < 0) {
                    min_gap = j - i;
                    save_index_num1 = i;
                    save_index_num2 = j;
                    printf("| %d ", min_gap);
                    printf("| %d, %d", i, j);
                }
                else if(min_gap > (j-i)) {
                    min_gap = j - i;
                    save_index_num1 = i;
                    save_index_num2 = j;
                }
                else break;
            }
        }
    }
    
    int *closestPrime = malloc(sizeof(int) * 2);
    closestPrime[0] = save_index_num1;
    closestPrime[1] = save_index_num2;
    return closestPrime;
}

bool isPrime(int p){
    for(int k = 2; k < p; k++){
        if(p % k == 0)
            return false;
    }
    return true;
}

bool *Sieve(int n){
    n = n + 1;
    bool *list = (bool *)malloc(sizeof(bool) * n);
    
    list[0] = false; list[1] = false;
    for(int i = 2; i < n; i++) list[i] = true;
    
    for(int i = 2; i < n; i++){
        if(list[i]){
            if(isPrime(i)){
                for(int j = i; j < n; j ++){
                    list[j*i] = 0;
                }
            }
            else list[i] = 0;
        }
    }
    return list;
}

int main(int argc, char **argv){
    int n = 100;
    
    bool *list = Sieve(n);
    
    
    for(int i = 0; i < n+1; i++){
        printf("%d ", list[i]);
    }
    
    int *closestPrime = closestPrimes(1, 100, list);
    
    printf("\n%d %d\n", closestPrime[0], closestPrime[1]);
    
    return 0;
}

