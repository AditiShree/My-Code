#include <stdio.h>

main () {
  char str[] = {'h','e','l','l','o', '\0'};

  //char *str = "hello";

  //printf("%d\n", sizeof(s));
  printf("%d\n", sizeof(str));

  printf("1st %d\n", &str);

  printf("2nd %d\n", str);
  //printf("3rd %s\n", &(s+1));

}
