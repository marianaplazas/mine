#include <stdio.h>
#include <stdlib.h>
/**
 *cards: the first function prints the deck is hot
 *Return: void
 */
void cards(void)
{
	int card_count = 11; // Here we declare and initialize the variable card_count of type int and value 11
	if (card_count > 10) // Here we put a condition if the variable is grather than 10 do something
 		puts("The deck is hot. Increase bet."); // if the condition is true then print The deck is hot. Increase bet.
}
/**
 *punishment: the second print 10 times I must not write code in class
 *Return: void
 */
void punishment(void)
{
	int c = 10; // declare and initialize the variable c of type int and value 10
	while (c > 0) // declare a loop while with exit condition c grather than 0 
	{
	 	puts("I must not write code in class"); // print I must not write code in class during the loop
 		c = c - 1; //in each iteration subtract one to C and go back to evaluate the condition with the new value
	}
} 
/**
 *bye_bye: function that takes a cmd line argument an print something
 *Return void
 */
void bye_bye(void)
{
	/* Assume name shorter than 20 chars. */ // And that is a comment too
	char ex[20]; //declare a buffer of max 20 characters
	puts("Enter boyfriend's name: "); // print in screen the message
	scanf("%19s", ex); //scan the argument by cmd
	printf("Dear %s.\n\n\tYou're history.\n", ex); // print a message with the argument taken by cmd
}
/**
 *switchs: looks for the case given in this case H and print hearts
 *Return: void
 */
void switchs(void)
{
	char suit = 'H'; //Declare and initialize the variable suit of type char with value H
	switch(suit) // Pass the variable to the switch case and look for the case 
	{
		case 'C': //if the variable has the value C then enter in this case
 			puts("Clubs"); // print clubs
 			break; //and just break the process finish the program
		case 'D': // if the variable has the value D then enter in this case
 			puts("Diamonds"); // print Diamonds
			break; // and just break the process finish the program
		case 'H': // if the variable has the value H then enter in this case (enter here)
 			puts("Hearts"); // print Hearts
 			break;// finish the program
		default: //if the variable don't have any of the values of the cases then enter here
 			puts("Spades"); // prints spades
	}
}
/**
 * this is the main function where all of the functions 
 * And this is the first set of problems
 * main: the entry point
 * return: 0
 */
int main(void)
{
	cards();
	punishment();
	bye_bye();
	switchs();	
}