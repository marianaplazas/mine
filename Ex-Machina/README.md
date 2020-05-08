I tried to be as faithful as possible to the original code so i keeped the coments in the code, I just modify two parts, first the shebang to run the code in local and the function int in the range (n, **int**(n/2)) because without this the code in python 3.5.2 collapse.

**Algorithm:** :mag:

the algorithm that Caleb use is called Κόσκινον Ερατοσθένους or The Sieve of Eratosthenes that he mencioned in the coments, this algorithm attributed to the greek polymath: mathematician, geographer, poet, astronomer, and music theorist Ἐρατοσθένης ὁ Κυρηναῖος (Eratosthenes of Cyrene) has it's earliest mention in the book *Introduction to Arithmetic* by Nicomachus of Gerasa's, this algorithm is used to calculated all the prime numbers up to any given limit. So for example if I have the number eight in the classic algorithm my result is that 2,3,5,7 are all the prime numbers given my limit eight, the way that the algorithm calculates the prime numbers is actually quite simple, first
