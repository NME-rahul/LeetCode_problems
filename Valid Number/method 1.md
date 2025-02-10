# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Just a simple scientific notation.

# Approach
<!-- Describe your approach to solving the problem. -->

$Q = \{q_1, q_2, q_3, q_4, q_5, q_6, q_7, q_8 \}$

$F = \{q_4, q_5, q_8\}$

$q = q_1$

$\sum = \{., +, -, e, E, 0...9\}$

$RE  = (+, -, \epsilon)(0...9)^*\{\epsilon, .(0...9)^+\}\{\epsilon, (e, E)(+, -, \epsilon)(0...9)^+\}$ 

![](https://raw.githubusercontent.com/NME-rahul/LeetCode_problems/refs/heads/main/Valid%20Number/image/20250211_000516.jpg)

PS: Above Finite automaton is not minimal by converting it to minimal DFA you can achieve faster execution, still the time complexity will remain same.

Code is messy !! 🥲

# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```c []
/*
Integer: a whole number without decimal point. can contain '+' or '-'
Decimal: a number with decimal point. can contain '+', '-' or '.'(decimal point can be any where)
Exponent: denoted by e or E

1. ()
2. Decimal [e / E/ NULL]
*/

/*

*/

char *loop_0_9(char *s){
    while(*s){
        if(*s >= 48 && *s <= 57) s++;
        else break;
    }
    return s;
}

bool isNumber(char* s) {

    if(*s == '+' || *s == '-'){
        s++;
        if(*s == '.'){
            s++;
            if(*s >= 48 && *s <= 57){ s++; goto q_4; }
        }
        if(*s >= 48 && *s <= 57){ s++; goto q_4; }
        else{return false;}
    }
    if(*s >= 48 && *s <= 57){
        s++;
        q_4:
        if(*s >= 48 && *s <= 57){
            s++;
            s = loop_0_9(s);
        }
        if(*s == '.'){
            s++;
            q_5:
            s = loop_0_9(s);
            if(*s == 'e' || *s == 'E'){
                s++;
                goto q_6;
            }
            if(*s == '\0'){return true;}
            else{return false;}
        }
        if(*s == 'e' || *s == 'E'){
            s++;
            q_6:
            if(*s == '+' || *s == '-'){
                s++;
            }
            if(*s >= 48 && *s <= 57){
                s++;
                s = loop_0_9(s);
                if(*s == '\0'){return true;}
            }
            else{return false;}
        }
        if(*s == '\0'){return true;}
        else{return false;}
    }
    if(*s == '.'){
        s++;
        if(*s >= 48 && *s <= 57){
            s++;
            goto q_5;
        }
        else{return false;}
    }
    else{return false;}
}
```
