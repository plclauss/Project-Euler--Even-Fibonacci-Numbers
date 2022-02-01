# Project Euler: Problem 2 - Even Fibonnaci numbers:

---

## First thoughts:
We wish to add up all the even numbers that occur in the Fibonacci sequence from 1 to 4 million. Off the bat, I'm thinking structure-wise, what would be the best approach?<br>
I'm thinking of at least two functions (in addition to main):
1. One to calculate what the next number in the Fibonnaci sequence of numbers will be, and 
2. An isEven() function to determine (by % 2 == 0) whether that number is even.
<br>

This is likely the non-algorithmic solution to this problem, but then again, these are my first thoughts.
<br><br>
I will try this approach first, and update this README with any updates as I move forward.
---
## First Solution (and some notes):
In my main function, the only notable piece of code is the nextFibbNumber() function call; the other two lines are printing out the result of the program and returning from main, respectively.<br>
nextFibbNumber takes in three parameters: 
1. the address of my global variable ("globalSum");
2. n, which was just an arbitrary name for the variable designating the smaller of the two variables to be added to get the next number in the sequence; and
3. r, which was the resulting next number in the sequence.
<br>

Initially, the function checks to see if r is above the limit. 
<br>
If not, check to see if r is even, and if it is, add it to the globalSum variable using the dereference operator. Both of these were written using the ternary operator.
<br>
Then comes the messiest part of the function: setting the values of n and r to accurately find the next number in the sequence. Truthfully, this likely could've had it's own function, but I got hungry and couldn't think of a name for the function at the time.
<br><br>
nextFibbNumber() then returns, and main prints out the answer and returns, as mentioned.<br>
Now on to read the more efficient way to solve this problem!