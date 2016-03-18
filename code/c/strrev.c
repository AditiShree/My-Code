#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main(){

  int n, i, c;
  char *s;
  char tmp, x;

  printf("enter len of array\n" );
  scanf("%d", &n);

  s = (char*) malloc((n+1)*sizeof(char));

  printf("Enter %d len string\n", n);
  c = 0;
getchar();
  while( ( s[c] = getchar() ) != '\n') {
    //s[c] = x;
    printf("%d\n",c);
    c++;
  }
  //s[c] = '\0';
  printf("%s\n", s);
//  printf("%d\n", strlen(s));

  for (i=0; i<n; i++) {
    printf("%c", s[i]);
  }
  printf("\n" );

  for (i=0; i<(n/2); i++) {
    tmp = s[i];
    s[i] = s[n-i-1];
    s[n-i-1] = tmp;
  }

  printf("%s\n", s);

}
