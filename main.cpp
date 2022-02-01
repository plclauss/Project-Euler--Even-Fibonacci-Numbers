#include <iostream>

/* nextFibbNumber()'s only job is to be a recursive function that calls isEven() and that terminates once the next
 * number is above 4 million.
 * Additionally, if isEven() returns a true in some form, it will update (or append) an int* arr[] to include that
 * number.
 * Upon return (so, we're back in main), a simple for loop will iterate over the int* arr[], adding up all elements in
 * it. */

/* isEven()'s only job is to figure out whether the next integer in the sequence is even. */

int globalSum = 0;

int isEven(int x) {
    return ((x % 2) == 0)?1:0;
}

void nextFibbNumber(int* sum, int n, int r) {
    if (r > 4000000)
        return;

    (isEven(r) == 1) ? *sum+=r : *sum+=0;

    int temp = r;
    r += n;
    n = temp;

    return nextFibbNumber(&globalSum, n, r);
}

int main() {
    nextFibbNumber(&globalSum, 1, 2);

    std::cout << "Sum of even numbers from 1 to 4million in the Fibonacci sequence is: " << globalSum << "." << std::endl;

    return 0;
}
