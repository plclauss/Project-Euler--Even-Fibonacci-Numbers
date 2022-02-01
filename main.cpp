#include <iostream>

int globalSum = 0;

int isEven(int x) {
    return ((x % 2) == 0)?1:0;
}

void nextFibbNumber(int* sum, int n, int r) {
    //terminates if r ("result") is over the given limit
    if (r > 4000000)
        return;

    //determine if the result is even, and add to the globalSum if it is
    (isEven(r) == 1) ? *sum+=r : *sum+=0;

    //update terms n and r to find next Fibbonacci number
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
