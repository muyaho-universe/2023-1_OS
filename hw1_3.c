#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 256
#define MAX_LEN 128
#define SIZE 512

typedef struct {
	int start, end;
	char substr[MAX_LEN];
} Substring;

Substring words[SIZE];
int no_word = 0;

void substring(char text[], int len);
void call_free();
int isspace(char t);

int main()
{
	char *prompt = "input a text: ";
	int prompt_len = strlen(prompt);

	char text[MAX_TEXT] = "";
	fgets(text, MAX_TEXT, stdin);
	int len = strlen(text) - 1;
	text[len] = 0;
	
	substring(text, len);

	int j = 0;
	for(int i = 0; i < len + 1; i++){
		if(words[j].start == i){
			printf("[");
		}
		else if(words[j].end == i){
			printf("]");
			j++;
		}
		else {
			printf(" ");
		}
	}
	
	putchar('\n');
	putchar('\n');
	for(int i = 0; i < no_word; i++)
		printf("words[%d] = (%d, %d, %s)\n", i, words[i].start, words[i].end, words[i].string);
	
	printf("Bye!\n");
	
	call_free();
	no_word = 0;

	return 0;
}

int isspace(char t){
	if(t == ' ') return 1;
	return 0;
}

void substring(char text[], int len){
	int first = 0;
	
	int is_first = 0, is_end = 0, is_still_blank = 0;

	if(!isspace(text[0])){
		is_first = 1;
		if(isspace(text[1])){
			is_end = 1;
		}
	}

	for(int i = 0; i < len; i++){
		if(i != len - 1){
			if(isspace(text[i]) && isspace(text[i+1])){
				is_still_blank = 1;
				is_first = 0;
				is_end = 0;
			}
			else if (isspace(text[i]) &&!isspace(text[i + 1])){
				is_first = 1;
				first = i + 1;
			}
			else if (!isspace(text[i])&& isspace(text[i + 1])){
				is_end = 1;			
			}

			if(is_first && is_end){
				is_first = 0;
				is_end = 0;
				words[no_word].start = first;
				words[no_word].end = i + 1;
				int k = 0;
				for(int j = first; j < i + 1; j++){
					words[no_word].substr[k] = text[j];
					k++;
				}
				no_word++;
			}
		
		}
		
		else{
			words[no_word].start = first;
			words[no_word].end = i + 1;
			words[no_word].substr = (char *) malloc(sizeof(char) * (i - first + 1));
			int k = 0;
			for(int j = first; j < i + 1; j++){
				words[no_word].substr[k] = text[j];
				k++;
			}
			no_word++;
		}
	}
	return;
}

void call_free(){
	for(int i = 0; i < no_word; i++){
		free(words[i].substr);
	}
	return;
}
