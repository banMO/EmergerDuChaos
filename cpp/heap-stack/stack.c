#include <stdio.h>

// http://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html

// All of the variables are created on the stack.

// This two variables are pushed onto the stack as soon as the multiplyByTwo() function allocates them.
// As soon as this function exits, the variables are popped off of the stack and is gone forever.
double multiplyByTwo (double input) {
  double twice = input * 2.0;
  return twice;
}

int main (int argc, char *argv[])
{
    // These variables are pushed onto the stack as soon as the main() function allocates them.
    // When the main function exits and the program stops, these variables are popped off of the stack.
    int age = 30;
    double salary = 12345.67;
    double myList[3] = {1.2, 2.3, 3.4};

    printf("double your salary is %.3f\n", multiplyByTwo(salary));

    return 0;
}