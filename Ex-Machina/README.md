#### Before starting...

I tried to be as faithful as possible to the original code so I keep the comments in the code, I just modify two parts, first the shebang to run the code in local and the function int in the range (n, **int**(n/2)) because without this the code in python 3.5.2 collapse. Also I tried to be as clear as possible so this explanation is intended to be understood by people who are starting in the code or by non-programmers so it could be redundant and is intentional. I hope that you enjoy it

## Algorithm: :mag:

The algorithm that Caleb use is called Κόσκινον Ερατοσθένους or The Sieve of Eratosthenes that he mentioned in the comments, this algorithm attributed to the greek polymath: mathematician, geographer, poet, astronomer, and music theorist Ἐρατοσθένης ὁ Κυρηναῖος (Eratosthenes of Cyrene) has its earliest mention in the book *Introduction to Arithmetic* by Nicomachus of Gerasa's, this algorithm is used to calculate all the prime numbers up to any given limit. So for example if I have the number eight in the classic algorithm my result is 2,3,5,7 all the prime numbers given my limit eight, the way that the algorithm calculates the prime numbers is actually quite simple, we have all the values from 2 (that is the first prime) to n and we marked the numbers that are not primes, so at the final all unmarked numbers are primes. We start with all numbers unmarked, so two the first number is unmarked so is prime then we mark every 2nd number in the list after 2 by counting up from 2 in increments of 2 (this numbers finally are all the multiples of two and we are counting 2, 4, 6... etc), then we move to the next number that is three it is unmarked so is prime we do the same thing as before and we mark all the multiples of three but look something interesting 6 is already marked because is multiple of 2 so exist an optimization that starts to mark the numbers after the square of the actual prime. then we go to the next unmark number in this case three and do the same as we did with the two and so forth with the next unmarked numbers, we stop when the prime that we are evaluating raised by two is greater than our limit and we stop here because for that moment because all the multiples of that number are also multiples of smallest primes so they are already marked. For example, we want to know all the primes given a limit of 20 so we have a list like this:

2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20

And we apply the algorithm so first we mark all multiples of 2 

2, 3, **4**, 5, **6**, 7, **8**, 9, **10**, 11, **12**, 13, **14**, 15, **16**, 17, **18**, 19, **20**

Then the three multiples

 2, 3, **4**, 5, **6**, 7, **8**, **9**, **10**, 11, **12**, 13, **14**, **15**, **16**, 17, **18**, 19, **20**

The four is marked so we skip it and goes to the 5 but if we see 5*5 is equal to 25 so we stop at this point but look the numbers, in this case, 10, 15 and 20 are multiples of 25 but they are marked cause 10 is multiple of 2 and 5 is multiple of 3 and 20 is of 2. The next multiple of 5 is 25 but is out of our limit, the same happens with the seven and all the other unmarked numbers so for this point we have all the primes that exist until 20 that’s why we stop here.

Also here is a gif for more clarity:

![](Sieve_of_Eratosthenes_animation.gif)

Well so beautiful but we only see the abstract idea now the question is how is the algorithm implemented in the code? before answer, if you feel that you don't have too clear the algorithm here is a link to a short, clear and visual explanation of it [Khan Academy](https://es.khanacademy.org/computing/computer-science/cryptography/comp-number-theory/v/sieve-of-eratosthenes-prime-adventure-part-4) 


## All about the code: :octocat:

The code of Caleb is divide in 3 parts two of theme are functions created by himself and you can reconigze it because at first are declare with the keyword def, and the third is the implementation of the functions to get and print the code. So we start with some basic points, if you don't know a lot of programming don't worry the goal is that you undrestand the general idea of how the program works you don't need to undrestand all you see at first. We are gona go trought the functions first and look line by line what does the code.

### Sieve:

Yeah this is the implemantation of the algorithm of Erathostenes, and is all the blockcode between the 7 and the 19 lines and if we pay attention Caleb call this function in the 34 line, take a look and you'll see this:

`x = sieve(10000)`

So this line in words says, apply the function to the number 10000 and asing the result in a variable call x so if x stores the return of the operation we can see what it stores just using a simple print (the language used in the program is Python), but because we don't know what is gonna to print just let me try with a smallest number like 10, so I said

```python
x = sieve(10) #asing the result in x
print(x) #show me whatevers x have
```
The phrases that starts with # are coments in the code. Above the two imagine there is the blockcode of sieve. Then I run my code and in the screen I saw this

`[1, 0, 1, 1, 0, 1, 0, 1, 0, 0]`

Wait the algorithm must tell me the prime numbers given a limit, why I see just 0 and 1?
Well first this is called a list or an array and is a data structure where you store as its name says data, this data are Boolean values and the Boolean values are just True or False that are represent by ones and zeros. and if we take a look closer actually the code and the algorithm is working, they tell us the primes numbers represent as ones and zeros for more clarity, each one or zeros is actually a number betwen 0 and 9 just as we can see below

````python
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
[1, 0, 1, 1, 0, 1, 0, 1, 0, 0]
````
And if you notice the patern after is that all prime numbers are represent by ones and the rest are represent by 0, with the zero sincerely I don't find a explanation why Caleb take it as a prime number, so the algorithm does exactly what it supose to do, it marks the true values for the prime numbers and return the list with the marks, to know how the code do that just see a little bit closer line by line but with the example of n = 10 as we did before.

````python
def sieve(n): #this is our first functión that return the list of zeros and ones
'''
Actually a function should comment like this
and the comment should say what the function does
in this case we have a function named sieve that takes one 
argument call n wich is the number that say how many or until what number
it will calculate the primes in this case n is going to be 10
'''

    x = [1]*n # X is equal to a matrix of size n 
	'''
	in this case wich n is 10 this first line set a matrix full of ones of size n
	if we print it we see that in this point our list look like this
	[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
	'''
    x[1] = 0 # the matrix in the position one is equal to 0
	'''
	here we set the position so the list in this point look like this
	[1, 0, 1, 1, 1, 1, 1, 1, 1, 1]
	Because we count from 0 
	'''

    for i in range(2,int(n/2)):
	# We set the counter i to 2 and while i is less than n divide 2 do the instructions below
	'''
	So in our first iteration i is equals to 2
	'''
        j = 2*i # set j equals to i multiply 2
		'''
		and here j is equals to 2 multiply by i wich is 2 so j is 4
		'''
        while j < n: 
		# this is a nested loop while j is less than n we do the next instructions
		'''
		here comes something intersting this while is faster than the for loop 
		so j is 4 and 4 is less than 10 so entry in the loop
		''' 
            x[j] = 0 # here we set the non prime numbers to 0, x in the position j is equals to 0
			'''
			So actually the loop unmark the non prime numbers here j is 4 and the list in the position 4 is unmarked or set to 0 and our list looks in this point like this
			[1, 0, 1, 1, 0, 1, 1, 1, 1, 1]
			wich is equivalent to this
			[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
			'''
            j = j+i # and we sum 1 to j
			'''
			and here j is 4+1 so is 5
			'''
    return x # Return the list
````
This is a little bit tricky even looking line by line it could be confuse wha