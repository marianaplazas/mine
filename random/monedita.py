#!/usr/bin/env python3

import random


def monedita_sueca(floor,ceiling, games):
	max = len(games)
	first = (random.randint(floor, ceiling))
	second = (random.randint(floor, ceiling))
	if (first > second):
		position = first / second 
	elif (second > first):
		position = second / first
	else:
		position = 0
	
	while(position > max):
		position = position - 2
		
	position = int(position)
	print("And the chose one is: " + games[(position)])

def add_games():
	games = []
	while (True):
		i = (input("Hi!, add a new game: "))
		if (i == "Stop" or i == "stop"):
			break
		else:
			games.append(i)
	return(games)

games = add_games()
if (len(games) < 0):
	print("Your list games are empty")
else:
	floor = int(input("Tell me the min: "))
	ceiling = int(input("Tell me the max: "))
	monedita_sueca(floor, ceiling, games)
