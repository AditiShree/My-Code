#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
  int n, i, c, p1, p2, ps, pe;
  char *s;
  char p, tmp;
  int e = EOF;
  p1 = 0;
  p2 = 0;

  printf("Enter no of elem\n" );
  scanf("%d", &n);

  s = (char*) malloc((n+1)*sizeof(char));

  printf("Enter %d elem\n", n);
  scanf("%s", s);

  printf("%s\n", s);

  printf("Its by char wise\n" );
  for(i=0; i<n; i++) {
    printf("%c", s[i]);
  }
  printf("\n" );

  ps = 0;
  pe = n-1;
  while (ps<pe) {
    printf("Its ps : %d\n", ps);
    printf("Its pe : %d\n", pe);
    p1 = 0;
    p2 = 0;

    if ( (s[ps]!='a') && (s[ps]!='e') && (s[ps]!='i') && (s[ps]!='o') && (s[ps]!='u') ) {
      p1 = 1;
    }
    if ( (s[pe]!='a') && (s[pe]!='e') && (s[pe]!='i') && (s[pe]!='o') && (s[pe]!='u') ) {
      p2 = 1;
    }
    if ((p1==1) && (p2==1)) {
      tmp = s[ps];
      s[ps] = s[pe];
      s[pe] = tmp;
      ps++;
      pe--;
    }else if((p1==1) && (p2==0)) {
      pe--;
    }else if((p1==0) && (p2==1)) {
      ps++;
    }
    printf("%s\n", s);

  }
  printf("%s\n", s);
  /*for (i=0; i<n; i++) {
    if (( (s[i]!='a') || (s[i]!='e') || (s[i]!='i') || (s[i]!='o') || (s[i]!='u') ) {
      p1 = 1;
    }
    if ((s[n-1-i]!='a') || (s[n-1-i]!='e') || (s[n-1-i]!='i') || (s[n-1-i]!='o') || (s[n-i-1]!='u')) {
      p2 = 1;
    }
    if ((p1==1) && (p2==1)) {
      tmp = s[i];
      s[i] = s[n-i-1];
      s[n-i-1] = tmp;
    }else if((p1==1) && (p2==0)) {

    }
  }*/

}
