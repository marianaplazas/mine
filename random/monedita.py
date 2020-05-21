#!/usr/bin/env python3

import random


def monedita_sueca(floor,ceiling, games):
	max = len(games)
	if (floor < 0):
		print("Be serious")
	elif (ceiling > max):
		print("There's no so many games!")
	else:
		position = (random.randint(floor, ceiling))
		print("And the chosen one is: " + games[position])

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
