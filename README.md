# Project Euler: Problem 2 - Even Fibonnaci numbers:

---

## First thoughts:
I believe Karl Gauss' theorem of the sum of consecutive integers (learned about in the previous problem set) may be of use here, as well. <br>
Before, to make use of the equation, we defined a limit (in this case, it would be 4 million) and a divisor, which, in this case, does not *really* apply. Instead, we want to check whether the next Fibonnaci number in the sequence is even, and if it is, add it to the sum. <br>
Additionally, we need some method of finding said number. <br>
I'm thinking of two functions: 