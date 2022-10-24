/*
 * myfunction.c
 *
 * Ali Farhangi - N00881073
 */


#include <string.h>
#include <stdbool.h>

/* delnewlinecursor --
 * this function removes any occurrences of '\n' or '\r'.
 * I call this method in main every time before pushing and enqueuing inputs to the stack and queue.
 * I wrote this function in order to make the program work when running via either eclipse or command prompt.
 *
 * Two reasons for writing this function:
 * 1- if we run this program via the eclipse, we will have extra empty lines in some part of the output because of the '\n'.
 * That's why I remove '\n' to have a more clear output and also to make the deletword method work properly.
 *
 * 2- If we don't remove '\r', strcmp method won't work properly within the deletword method.
 * For example, if "cat\r" is in the linked list and we pass "cat" to deleteword function, strcmp won't return 0 because they are not the same.
 *
 *
 *
 * para:
 * px, the new item that we want to add it to stack and queue
 *
 * return:
 * if the new item (char *px) has '\r' or '\n', it removes it and a new char pointer named pp points to it. It then returns pp.
 *
 *
 *
 *
 */
char* delnewlinecursor (char *px)
{
	char *pp;

	// points to the parameter
	pp = px;

	// copies the px to data array in order to be able to modify it
	char data[80];
	strcpy(data,px);
	int i = 0;
	bool newlinefound = true;
	while(newlinefound)
	{

		if(data[i] == '\n' || data[i] == '\r')
		{
			// it sets '\r' or '\n' to NULL
			data[i] = '\0';

			// points to the data array which was just modified.
			pp = data;
		}

		// this happens if it reaches end of the string
		else if(data[i] == '\0')
		{
			break;
		}

		i++;
	}

	return pp;

}
