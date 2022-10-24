/*
 * finalproject.c
 *
 * Ali Farhangi - N00881073
 *
 * Sources used:
 *
 * https://www.educative.io/edpresso/splitting-a-string-using-strtok-in-c
 * I researched on how to split words and store them into the list when there is a space between them.
 *
 *
 * https://www.programiz.com/c-programming/library-function/ctype.h/isdigit
 * https://stackoverflow.com/questions/17292545/how-to-check-if-the-input-is-a-number-or-not-in-c
 * I also researched on how to use isdigit to check if the input is a number or not.
 *
 *
 * Aiming for a grade of a 100
 * I used Windows to build and test my program
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "list.h"
#include "myfunction.h"


int main(int argc, char* argv[])
{

	int numoflines = 0;
	char txtfile[80] = "";
	char delword[80] = "";
	bool filefound = false;
	bool numoflinefound = false;
	bool delfound = false;
	Node *headstack = NULL;
	Node *headqueue = NULL;


	for(int i = 0; i < argc; i++)
	{

		if(strcmp(argv[i] , "-f") == 0)
		{
			strcpy(txtfile, argv[i+1]);
			filefound = true;
		}


		if(strcmp(argv[i] , "-h") == 0)
		{
			printf("Use this program as such:\n");
			printf("\n");
			printf("reading from the file: ");
			printf("%s", argv[0]);
			printf("%s" , " -f input.txt\n");
			printf("\n");
			printf("reading from standard input until end of file: ");
			printf("%s", argv[0]);
			printf("\n");
			return 0;

		}


		if(strcmp(argv[i] , "-n") == 0)
		{
			char input[100] = "";
			int length;
			strcpy(input, argv[i+1]);
			length = strlen (input);

			for (int i = 0; i < length; i++)
			{

				// it checks character by character to see if it's a number or not. if it returns false, then it's not a number.
				if (!isdigit(input[i]))
				{
					printf("Incorrect usage. Please use a positive number. Use this program as such:\n");
					printf("\n");
					printf("%s", argv[0]);
					printf("%s" , " -n 10 -f input.txt\n");
					printf("This will read up to 10 lines or end of file(whichever comes first) of input.txt\n");
					printf("\n");
					printf("%s", argv[0]);
					printf("%s" , " -n 5\n");
					printf("This will read up to 5 lines or end of file(whichever comes first) of standard input\n");
					return 0;
				}

			 }

			numoflines = atoi(argv[i+1]);

			if(numoflines <= 0)
			{

				printf("Incorrect usage. Please use a positive number. Use this program as such:\n");
				printf("\n");
				printf("%s", argv[0]);
				printf("%s" , " -n 10 -f input.txt\n");
				printf("This will read up to 10 lines or end of file(whichever comes first) of input.txt\n");
				printf("\n");
				printf("%s", argv[0]);
				printf("%s" , " -n 5\n");
				printf("This will read up to 5 lines or end of file(whichever comes first) of standard input\n");
				return 0;

			}

			else
			{
				numoflinefound = true;
			}

		}


		if(strcmp(argv[i] , "-d") == 0)
		{

			strcpy(delword, argv[i+1]);
			delfound = true;

		}

	}




	if(filefound)
	{

		FILE *fp;
		fp = fopen(txtfile, "r");

		if(!fp)
		{
			printf("error opening file");
			return 0;
		}

		else
		{

			int count = 0;
			char *ptr;
			char *c = malloc(sizeof(char)*80);

			while(fgets(c, 80, fp))
			{

				// it passes the string that we want to split and a particular delimiter which is space
				ptr = strtok(c, " ");

				// it loops through the string in order to split each word
				while(ptr != NULL)
				{
					ptr = delnewlinecursor(ptr);

					// after splitting, now we push and enqueue
					headstack = push(headstack, ptr);
					headqueue = enqueue(headqueue, ptr);

					ptr = strtok(NULL, " ");

				}
				count++;

				if(numoflinefound)
				{
					if(count == numoflines)
					{
						break;
					}
				}

			}


			fclose(fp);
			free(c);

		}

	}

	else
	{
	    int count = 0;
	    char *input;
	    char *s;

	    while(!feof(stdin))
	    {
	    	s = malloc(sizeof(char)*80);
	    	fgets(s,80,stdin);

	    	// it passes the string that we want to split and a particular delimiter which is space
	    	input = strtok(s, " ");

	    	// it loops through the string in order to split each word
	    	while(input != NULL)
	    	{
	    		input = delnewlinecursor(input);

	    		// after splitting, now we push and enqueue
	    		headstack = push(headstack, input);
	    		headqueue = enqueue(headqueue, input);

	    		input = strtok(NULL, " ");

	    	}

	    	count++;

			if(numoflinefound)
			{
				if(count == numoflines)
				{
					break;
				}
			}


	    }

	    fclose(stdin);
	    free(s);

	}

    printf("printing stack:\n") ;
    printlist(headstack);

    printf("printing queue:\n") ;
    printlist(headqueue);



	if(delfound)
	{
		headstack = deleteword(headstack, delword);
		printf("printing stack after removing %s: \n" , delword);
		printlist(headstack);

		headqueue = deleteword(headqueue, delword);
		printf("printing queue after removing %s: \n" , delword);
		printlist(headqueue);

	}


	deletelist(headstack);
	headstack = NULL;
	deletelist(headqueue);
	headqueue = NULL;


	return 0;
}

