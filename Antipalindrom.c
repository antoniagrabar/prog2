#include <stdio.h>
#include <string.h>

#ifndef DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#endif

#define M 256

// Napisati funkciju za provjeru radi li se o palindromu
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
  char str[M];

  scanf("%s", str);

  // Napisati dio koda koji brise znakove dok god se radi o palindromu
  while(strlen(str) > 0 && check_palindrome(str)) {
    str[strlen(str) - 1] = '\0';
  }

  printf("%d", (int) strlen(str));

  return 0;
}
