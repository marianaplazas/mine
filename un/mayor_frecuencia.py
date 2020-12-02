#!/usr/bin/python3

numbers = input()
numbers = numbers.split()
for i in range(len(numbers)):
    numbers[i] = int(numbers[i])

mp = {}  
for i in range(len(numbers)): 
    if numbers[i] not in mp: 
        mp[numbers[i]] = 0
    mp[numbers[i]] += 1  

t = list(mp.items())
t.sort(reverse=True, key = lambda x: x[1])

nl = []
mx = t[0][1]

for i in range(len(t)):
    if t[i][1] == mx:
        nl.append(t[i]) 
    else:
        break

nl.sort(reverse=True, key= lambda x : x[0])

print(nl[0][0], nl[0][1])
