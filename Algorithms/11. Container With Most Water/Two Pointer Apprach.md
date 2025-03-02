# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Greedy Approach, keep moving until you finds the larger area.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Set two pointer one at the start$(i)$ and other at the end$(j)$ of array. Calculate the $area = min(height[i], height[j])*(j - i)$ intially and save this area.

2. Now move the pointer one ahead who is pointing to less height then other, again calculate the area and match the new calculated area with saved ones.
    * if new calculated area is greater then saved ones then update the area value with new area.

3. Repeat step 2 until the two pointer $i$ and $j$ crosses each other.

# Complexity
- Time complexity: $O(n)$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $O(1)$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```c []
int min(int a, int b){
    if(a > b) return b;
    else return a;
}

int maxArea(int* height, int heightSize) {

    int i = 0, j = heightSize - 1;

    unsigned int area = min(height[i], height[j]) * (j - i);
    unsigned int calc = -1;

    while(i != j){
        if(height[i] > height[j]){
            j--;
        }
        else{
            i++;
        }
        calc = min(height[i], height[j]) * (j - i);
        if(calc > area){
            area = calc;
        }
    }

    return area;
}
```
