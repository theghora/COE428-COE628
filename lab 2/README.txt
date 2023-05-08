Summary: In this lab, I was successfully able to modify the Main file to fill the needs of REQUIREMENT 2. 

Errors:No errors



REQURIREMENT 1:
Suppose that towers(5, 2, 3) is invoked.
  1. How will the first recursive call to towers() be invoked? Answer this question in the form: towers(x, y, z) where you give the actual values to the three parameters. 

Ans1. 
  First recursive call will be the n-1 of towers from the starting rod to the rod that is not start or destination. So this will be 4 disks move from tower 2 to tower 1. towers(n-1,start,other) => towers(4,2,1)

2.How many recursive calls to towers() will be made before this first recursive call actually returns to the initial invocation?

Ans2.
  The amount of recursive calls that will be made is 5 before returning the intial invocation

3.Once towers(5, 2, 3) has invoked its first recursive call to towers() and this
invocation has returned, what will be printed to stdout? (i.e. What actual
move will be made by towers(5, 2, 3) ?)

Ans3. Disk #1 will move from tower 2 to 3

4.How will the second recursive call to towers() be invoked? Answer this
question in the form: towers(x, y, z) where you give the actual values to the
three parameters. 

Ans4. The second recursive call is going to be towers(3,2,3)


Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout?
Answer: The program will output 255, or (2^n)-1, lines when it is ran with a custom amount of 8 disks.

  
