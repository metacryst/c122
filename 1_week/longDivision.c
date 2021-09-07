#include <stdio.h>

void long_division (int dividend, int divisor, int *quotientp, int *remainderp);

int main(void)
{
    int quot, rem;
    
    long_division(40, 3, &quot, &rem);
    printf("40 divided by 3 yields quotient %d ", quot);
    printf("and remainder %d\n", rem);
    
    return 0;
}

void long_division (int dividend, int divisor, int *quotientp, int *remainderp)
{
    
};



// main does not go out of scope until end of program
// so, long_division can see the variables