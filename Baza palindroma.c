#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define SIZE 1024

void clean_string(char s[]) {
  int i, n = 0;

  for (i = 0; i < strlen(s); i++) {
    if (!isalpha(s[i])) {
      n++;
    } else {
      s[i - n] = tolower(s[i]);
    }
  }
  s[i - n] = '\0';
}

int check_palindrome(char s[]) {
  int l = strlen(s);

  for (int i = 0; i < l / 2; i++) {
    if (s[i] != s[l - i -1]) {
      return 0;
    }
  }  

  return 1;
}

int main() {
  char line[SIZE];
  int br = 0;
  
  FILE *fp;
  fp = fopen("input.dat", "r");

  while(fgets(line, SIZE, fp) != NULL) {
    clean_string(line);
    br += check_palindrome(line);
  }
  
  printf("%d\n", br);
  
  return 0;
}
