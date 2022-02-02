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

---
## Algorithmic Solution Explanation:
O.K., I know this sounds farfetched, but I promise that I had figured out the pattern mentioned in the PDF, but before I get to that, let's break down the contents of the PDF. The algorithm was broken into two pieces:
1. A description of the pattern, and
2. A manipulation of that pattern.

**The Pattern:**<br>
The PDF mentions that, when looking at a list of the Fibonacci numbers, it's noticeable that every third number is even. This is what I had observed prior to my solution. I opened [this link](https://r-knott.surrey.ac.uk/Fibonacci/fibtable.html), which shows the first 300 numbers in the sequence, and just started trying things to find a pattern. I did notice that every third was an even number, but that felt so...cheap? So simple. So I then tried finding another pattern dealing with raising 2 to a power X. This, however, did not work for all X. So, I said "whatever, the +=3 loop is not much different from the +=1 approach," so I tackled it that way.
<br>
**The Manipulation:**<br>
This is the extra step I couldn't get to. Sure, I saw the pattern, but adding 3 isn't much different from adding 1. This is where the mathematics comes in (and probably where I'd benefit from having a notebook). Anyways, let's begin to analyze this pattern.<br>
What do we know? Let's make a list:
1. That every third number in the Fibbonacci sequence is even.

That's it. Pretty short list. What does this mean? Well, we can alter the original Fibonacci equation... <br>
```asm
F(n) = F(n - 1) + F(n - 2)
```
...to fit our purposes...
```asm
F(n) = F(n - 3) + F(n - 6)
```
...but this is incomplete. If we list out a few of the numbers in the sequence (evens only), we get:
```asm
2 8 34 144 610 ...
```
We see that, in order to get the next term, we can use the equation (denoted Fe(n) for differentiation and comparison):
```asm
Fe(n) = 4Fe(n - 1) + Fe(n - 2)
```
There is, however, another way of arriving at this equation. We may derive it from the first two equations listed above: the original Fibonacci equation and our desired result, respectively. 
```asm
F(n) = F(n - 1) + F(n - 2)

//If we "expand" the first term... (or, figure out what two terms make up the first term), we get:

F(n) = F(n - 2) + F(n - 3) + F(n - 2)
     = 2F(n - 2) + F(n - 3).
     
/* O.K. There are probably a few branches you could go down that would lead you to the correct answer, but we don't need an "n - 2" term, so we'll expand that one first, and see what happens.*/

F(n) = 2F(n - 2) + F(n - 3)
     = 2{[F(n - 3)] + [F(n - 4)]} + F(n - 3)
     = 3F(n - 3) + 2F(n - 4)
     
//From here, we can re-write 2F(n - 4) as F(n - 4) + F(n - 4), expand one, and keep the other.

F(n) = 3F(n - 3) + F(n - 5) + F(n - 6) + F(n - 4)

//Now, notice that F(n - 3) = F(n - 4) + F(n - 5), so:

F(n) = 4F(n - 3) + F(n - 6)
```
And we're done!
<br><br>
We can reduce `F(n)`, though, by equating it with `Fe(n)`. Since they are the same equation (except for the value, say, k, within the terms (n - k)), we can just rewrite `F(n)` in terms of `Fe(n)`. Thus, our final equation is:
```asm
Fe(n) = 4Fe(n - 1) + Fe(n - 2)
```


***Note: This is a recursive relation with two different function calls of two different magnitudes, k. Thus, we have two base cases:***
```asm
...
if (k == 0)
    return k;
if (k == 1)
    return 2;
...
```

**Visualization:**<br>
If it helps (because it certainly helped me), here is a small visualization of the stack (growing downward) as the recursive function runs:
<br><br>

```
//Assume main calls our recursive function func(n), where n = 2. When the program runs, main will be
//added to the stack, and once func is called, it, too, will be added to the stack, until it returns,
//at which point it will be popped.

//**NOTE**: In C/C++, it does not matter which function call (Fe(n - 1) or Fe(n - 2)) is called first, 
//since all we're doing is calculating for a number. We are not altering other variables, nor are we
//printing anything out. This is, at least, what I got from this Stack Overflow post:

//https://stackoverflow.com/questions/12920001/recursion-two-calls-in-one-statement

//I highly recommend reading this, as it might clear up some confusion. The certified answer also 
//covers the sequence of operations for recursive function calls in Java and C#. Additionally, I'd 
//check out this visualization:

//https://www.freecodecamp.org/news/how-recursion-works-explained-with-flowcharts-and-a-video-de61f40cb7f9/#:~:text=Recursive%20functions%20use%20something%20called,take%20off%20the%20top%20item.

//...of the stack from freeCodeCamp. This article is primarily what I referenced for my visualization
//below.
//**ENDNOTE**

//**NOTE** I will show two examples, and all the stack pushes/pops that come with them. I will use 
//X.Y to denote which example we're on (X) and how many pops we've done (Y). So, 1.0 means the first
//example, 0 pops. 1.1 means first example, after one pop.

//Since there is no consequence to which recursive function gets called first, we'll first examine the
//4Fe(n - 1) term.

1.0
_______________________
|                      | main
|______________________|
|                      | func, n = 2
|______________________|
|                      | func, n = 1 ---> since n = 1, return 2
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

1.1
_______________________
|                      | main
|______________________|
|                      | func, n = 2 ---> This is the first function call, so we have 4*(2) + Fe(n-2)
|______________________|
|                      | func, n = 0 ---> return 0.
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

1.2
_______________________
|                      | main
|______________________|
|                      | func, n = 2 ---> Maintaining our prev. results: 4*(2) + (0) = 8.
|______________________|
|                      |
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

1.3
_______________________
|                      | main --> first func call returns  8, which you can use here to do...something
|______________________|
|                      | 
|______________________|
|                      | 
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

//Which is what we expect as the next even number in the sequence. (The second number in the sequence,
//that is.
//Let's calculate for the third even number in the sequence. (i.e., n = 3).

2.0
_______________________
|                      | main
|______________________|
|                      | func, n = 3
|______________________|
|                      | func, n = 2
|______________________| 
|                      | func, n = 1 --> return 2
|______________________| 
|                      |
|                      | 
------------------------

2.1
_______________________
|                      | main
|______________________|
|                      | func, n = 3
|______________________|
|                      | func, n = 2 ---> 4*(2) + Fe(n - 2)
|______________________| 
|                      | func, n = 0 ---> return 0
|______________________| 
|                      |
|                      | 
------------------------

2.2
_______________________
|                      | main
|______________________|
|                      | func, n = 3 ---> 4*(8) + Fe(n - 2)
|______________________|
|                      | func, n = 2 ---> 4*(2) + 0 ---> return 8
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

2.3
_______________________
|                      | main
|______________________|
|                      | func, n = 3
|______________________|
|                      | func, n = 1 ---> return 2
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

2.4
_______________________
|                      | main
|______________________|
|                      | func, n = 3 ---> 4*(8) + 2 = 32 + 2 = 34
|______________________|
|                      | 
|______________________| 
|                      |
|______________________| 
|                      |
|                      | 
------------------------

...

//Which is, again, what we'd expect to be the third even number in the sequence.
```