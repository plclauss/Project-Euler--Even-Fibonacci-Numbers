# Project Euler: Problem 2 - Even Fibonnaci numbers:

---

## First thoughts:
We wish to add up all the even numbers that occur in the Fibonacci sequence from 1 to 4 million. Off the bat, I'm thinking structure-wise, what would be the best approach?<br>
I'm thinking of at least two functions (in addition to main):
1. One to calculate what the next number in the Fibonnaci sequence of numbers will be, and 
2. An isEven() function to determine (by % 2 == 0) whether that number is even.
<br>

This is likely the non-algorithmic solution to this problem, but then again, these are my first thoughts. Perhaps we can make use of Karl Gauss' Proof of the Sum of Consecutive Integers. Perhaps when we find an even number (i.e., isEven() returns a boolean True), we can add it to some int* arr[], which we can then treat as a list of consecutive integers, where the formula S = (n(n+1))/2 may be of use.
<br><br>
I will try this approach first, and update this README with any updates as I move forward.