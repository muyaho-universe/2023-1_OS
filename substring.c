/*
	Read a text from the user and extract all words from the input string into an array of 'Substring' structures.
	A word is defined as a sequence of characters separated by whitespace characters (space, tab, new line, etc).

	Example)
		Input a text: Welcome to HGU!		// "Welcome to HGU!" is the input string
		Totally, 3 substrings.
		0) 0 - 7, "Welcome"
		1) 8 - 10, "to"
		2) 11 - 15, "HGU!"

	You can use the following function to decide whether a character 'ch' is a whitespace character or not.
		int isspace(int ch);		// returns 1 if ch is a whitespace character, otherwise, 0	

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// Use the following structure to store the start position, end position, and string.
typedef struct {
	int start, end;					// location of the substring (start and end indices)
	char *string;					// pointer to dynamically allocate memory to store string
} Substring;

Substring sub[128];					// array of substrings
int no_string = 0;					// # of substrings

void substring(char text[], int len);
void call_free();

int main()
{
	char text[512] = "";

	printf("Input a text: ");
	fgets(text, 511, stdin);		// read a text line
	int len = strlen(text) - 1;
	text[len] = 0;					// trim '\n'

	// TO DO: extract all words from the input text into sub.
	//		  store the number of the extracted substrings in no_string.
	//		  dynamically allocate memory to store substring in the 'string' field.

    substring(text, len);
    

	// DO NOT modify the following three lines
	printf("Totally, %d substrings.\n", no_string);
	for(int i = 0; i < no_string; i++)
		printf("%d) %d - %d, \"%s\"\n", i, sub[i].start, sub[i].end, sub[i].string);

	// TO DO: deallocate all dynamic memory blocks
    call_free();

	no_string = 0;		// for safety
	
	return 0;
}

void substring(char text[], int len){
    int first = 0;
    for (int i = 0; i < len; i++){
        if (text[i] == ' '){
            sub[no_string].start = first;
            sub[no_string].end = i;
            sub[no_string].string = (char *) malloc(sizeof(char) * (i - first + 1));
            int k = 0;
            for (int j = first; j < i; j++){
                sub[no_string].string[k] = text[j];
                k++;
            }
            
            no_string++;
            first = i + 1;
        }
        if (i == len - 1){
            sub[no_string].start = first;
            sub[no_string].end = i + 1;
            sub[no_string].string = (char *) malloc(sizeof(char) * (i - first + 1));
            int k = 0;
            for (int j = first; j < i + 1; j++){
                sub[no_string].string[k] = text[j];
                k++;
            }
            no_string++;
        }
    }
    return;
}


void call_free(){
    for (int i = 0; i < no_string; i++){
        free(sub[i].string);
    }
    return;
}