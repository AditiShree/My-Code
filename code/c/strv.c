#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
  int n, i, c;
  char *s;
  char p, tmp;
  int e = EOF;

  printf("Enter no of elem\n" );
  scanf("%d", &n);

  s = (char*) malloc((n+1)*sizeof(char));

  printf("Enter %d elem\n", n);
  scanf("%s", s);

  printf("%s\n", s);

  for (i=0; i<(n/2); i++) {
    tmp = s[i];
    s[i] = s[n-i-1];
    s[n-i-1] = tmp;
  }

  printf("%s\n", s);


}
