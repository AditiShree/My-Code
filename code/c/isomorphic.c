#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
  char  *s1, *s2;
  char c;
  int i, j, n, p;
  int l1, l2;

  clock_t start, end;
  double diff;
  p = 0;


  printf("Enter the len of string1\n" );

  scanf("%d", &n);

  s1 = malloc(n*sizeof(char));
  s2 = malloc(n*sizeof(char));
  l1 = l2 = 0;
  printf("Enter the s1\n" );
  getchar();
  while ((c = getchar()) != '\n') {
    s1[l1] = c;
    l1++;
  }
  printf("Its s1: %s\n", s1);
  s1[l1] = '\0';

  printf("Enter the s2\n" );
  //getchar();
  while ((c = getchar()) != '\n') {
    s2[l2] = c;
    l2++;
  }
  printf("Its s2: %s\t", s2);
  s2[l2] = '\0';

  start = clock();
  if (l1 == l2) {

    for(i=0; i<l1; i++) {
      for(j=i+1; j<l1; j++) {
        if(s1[i] == s1[j]){
          if(s2[i] == s2[j]) {
            continue;
          }else {
            p = 1;
          }
        }
      }
      if(p==1) {

        break;
      }
    }
    if(p==0) {
      printf("Matched\n" );
    }else{
      printf("Not matched\n" );
    }
  }else{
    printf("Not matched\n" );
  }
  end = clock();
  diff = (double)(end-start);
  printf("Its difference %f\n", diff);

}
