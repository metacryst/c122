#include <stdio.h>

int main()
{
    int originalValue = 3;

    // pointer variable contains the address of another cell containing an integer
    // must be declared with * so that this operator works later
    int *pointerVariable = &originalValue;
    
    int *secondPointerVariable;
    secondPointerVariable = &originalValue;

    // nump (address 2000) --points to--> num (address 1000) (value 3)
    // the direct value of num is 3, while direct value of nump is the address (1000) of the memory cell which holds 3

    // num = Direct Value of num = 3
    // nump = Direct Value of nump = 1000
    // *nump = Indirect Value of nump = 3
    // &nump = Address of nump = 2000

    // if we apply *pointerVariable we can access the integer value 3
    // * is known as the indirection operator, which returns the value of the variable located at the address specified by its operand
    printf("%d", *pointerVariable);
    printf("\n");
    printf("%d", *secondPointerVariable);
    printf("\n");

    return 0;
}
