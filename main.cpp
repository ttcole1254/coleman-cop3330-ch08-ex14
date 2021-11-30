/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Tyler Coleman
 */

/*
* Can we declare a non-reference function argument const (e.g., void f(const int);)? What might that mean? Why might
* we want to do that? Why don’t people do that often? Try it; write a couple of small programs to see what works.
*/

#include "std_lib_facilities.h"	
int var1 = 2;
void testconst1(int const &var1) {
    cout << "\n\nThis function uses const and a reference. The number starts off as 2, we try and increase it by 3.\n";
    cout << "Initial var: " << var1;
    //var1 = var1 + 3;
    cout << "\nCompile error when trying to set value due to it being const.\n";
}

void testconst2(int &var1) {
    cout << "\n\nThis function doesn't use const but does use a reference. The number starts off as 2, we try and increase it by 3 and then access outside this function.\n";
    cout << "Initial var: " << var1;
    var1 = var1 + 3;
    cout << "\nValue inside function now: " << var1;
}

void testconst3(int var1) {
    cout << "\n\nThis function doesn't use const and doesn't use a reference. The number starts off as 2, we try and increase it by 3 and then access outside this function.\n";
    cout << "Initial var: " << var1;
    var1 = var1 + 3;
    cout << "\nValue inside function now: " << var1;
}

int main()
{
    cout << "Yes, a non-reference function argument const can be declared, it is used to pass a value that is assured to never be changed.\n\n";
    cout << "It is also used because as a function argument, the int value would normally be copied. Using &int instead when the variable is very large avoids the copy so the reference is direct, but now it could be changed inadvertently.\n";
    cout << "Using const &int solves the problem by not copying the value, and also not allowing it to be changed. Do note that this usage can be messy.";
    testconst1(var1);
    var1 = 2;
    testconst2(var1);
    cout << "\nValue outside the function: " << var1;
    var1 = 2;
    testconst3(var1);
    cout << "\nValue outside the function: " << var1;
    cout << "\n\nAs you can see, const and references keep the value from being copied in memory and also prevent it from being changed."
}