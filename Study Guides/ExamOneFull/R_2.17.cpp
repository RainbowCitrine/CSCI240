#include <iostream> 

/*

Write a short program that takes as input three integers, a, b, and c, and
determines if they can be used in a correct arithmetic formula (in the given
order), like “a+b = c,” “a = b−c,” or “a ∗ b = c.”

*/


bool operatorTest(int a, int b, int c)
{
    return ((a + b == c) || (a == b - c) || (a * b == c));
}


