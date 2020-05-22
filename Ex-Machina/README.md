I tried to be as faithful as possible to the original code so i keeped the coments in the code, I just modify two parts, first the shebang to run the code in local and the function int in the range (n, **int**(n/2)) because without this the code in python 3.5.2 collapse.

**Algorithm:** :mag:

the algorithm that Caleb use is called Κόσκινον Ερατοσθένους or The Sieve of Eratosthenes that he mencioned in the coments, this algorithm attributed to the greek polymath: mathematician, geographer, poet, astronomer, and music theorist Ἐρατοσθένης ὁ Κυρηναῖος (Eratosthenes of Cyrene) has it's earliest mention in the book *Introduction to Arithmetic* by Nicomachus of Gerasa's, this algorithm is used to calculated all the prime numbers up to any given limit. So for example if I have the number eight in the classic algorithm my result is 2,3,5,7 all the prime numbers given my limit eight, the way that the algorithm calculates the prime numbers is actually quite simple, we have all the values from 2 (that is the first prime) to n and we marked the numbers that are not primes, so at the finall all unmarked numbers are primes. We start with all numbers unmarked, so two the first number is unmarked so is prime then we mark every 2nd number in the list after 2 by counting up from 2 in increments of 2 (this numbers finally are all the multiples of two and we are counting 2, 4, 6... etc), then we move to the next number that is three it is unmarked so is prime we do the same thing as before and we mark all the multiples of three but look something intersting 6 is alredy marked because is multiple of 2 so exist an optimization that start to mark the numbers after the square of the actual prime. then we go to the next unmark number in this case three and do the same as we did with the two and so forth with the next unmarked numbers, we stops when the prime that we are evaluating raised by two is grather than our limit and we stops here because for that moment because all the multiples of that number are also multiplies of smallest primes so they are already marked. For example we want know all the primes given a limit of 20 so he have a list like this:

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20

and we apply the algorithm so first we mark all multiples of 2 

1, **2**, 3, **4**, 5, **6**, 7, **8**, 9, **10**, 11, **12**, 13, **14**, 15, **16**, 17, **18**, 19, **20**

then the three multiplies

1, **2**, 3, **4**, 5, **6**, 7, **8**, **9**, **10**, 11, **12**, 13, **14**, **15**, **16**, 17, **18**, 19, **20**
the four is marked so we skip it and goes to the 5 but if we see 5*5 is equal to 25 so we stop at this point but look the numbers, in this case 10, 15 and 20 are multiples of 25 but they are marked cause 10 is multiple of 2 and 5 is multiple of 3 and 20 is of 2. The next multiple of 5 is 25 but is out of our limit, the same happens with the seven and all the other unmarked numbers so for this point we have all the primes that's why we stop here.

Also here is a gif for more clarity:
![](Sieve_of_Eratosthenes_animation.gif.gif)

Well so beautiful but we only see the abstract idea now the question is how is the algorithm implemented in the code? before anwser if you feel that you don't have too clear the algorithm here is a link to a short, clear and visual explanation of it [Khan Academy](https://es.khanacademy.org/computing/computer-science/cryptography/comp-number-theory/v/sieve-of-eratosthenes-prime-adventure-part-4) 


 first we declare an array of booleans and then we set all the array to true indexed by integers 2 to n. But wait, what it means for probably non programmers or beginners that for chance arrives here? (well just for clarity I consider myself as a beginner and this as an excersice to practice and relax my mind) back to the question that means that you'll need a list of ones and zeros, the list to store in order and zeros and ones because they are the boolean values.  
```python
# hello I'm a comment and this is an array of booleans:
x = [0,1,0,1,1,0] 
```
I'll would love explains to the more basic stuff like variables but probably I'll never end this readme if I do that so for simplicity x is just the variable where we store the array so we can manipulate it in the program, changing the values. The next step in the sieve is the real key, we have to mark the values that are not primes the logic is simple, if a number is not mark then is 