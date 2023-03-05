#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int start, end;
  char *string;
} Substring;

Substring sub[128];
int no_string = 0;

void substring(char text[], int len);
void call_free();

int main() {
  char text[512] = "";
  fgets(text, 511, stdin);
  int len = strlen(text) - 1;
  text[len] = 0;

  substring(text, len);

  int j = 0;
  for (int i = 0; i < len + 1; i++) {
    if (sub[j].start == i) {
      printf("[");
    } else if (sub[j].end == i) {
      printf("]");
      j++;
    } else {
      printf(" ");
    }
  }

  no_string = 0;

  return 0;
}

void substring(char text[], int len) {
  int first = 0;

  int is_first = 0, is_end = 0, is_still_blank = 0;

  if (text[0] != ' ') {
    is_first = 1;
    if (text[1] == ' ') {
      is_end == 1;
    }
  }

  for (int i = 0; i < len; i++) {
    if (i != len - 1) {
      if (text[i] == ' ' && text[i + 1] == ' ') {
        is_still_blank = 1;
        is_first = 0;
        is_end = 0;
      } else if (text[i] == ' ' && text[i + 1] != ' ') {
        is_first = 1;
        first = i + 1;
       
      } else if (text[i] != ' ' && text[i + 1] == ' ') {
        is_end = 1;
      }

      if (is_first && is_end) {
        is_first = 0;
        is_end = 0;
        sub[no_string].start = first;
        sub[no_string].end = i + 1;
        no_string++;
      }
    }

    else {
      sub[no_string].start = first;
      sub[no_string].end = i + 1;
      no_string++;
    }
  }
}

void call_free() {}
