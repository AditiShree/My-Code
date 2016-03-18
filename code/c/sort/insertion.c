#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
  int *a;
  int n, i, j, found, tmp, len, t;
  int *s;
  int x,y;

  clock_t start, end;
  double diff;

  printf("Enter no of elem\n" );
  scanf("%d", &n);

  a = malloc(n*sizeof(int));
  s = malloc(n*sizeof(int));

  printf("Enter %d elem\n", n);
  for(i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  found = 0;
  len = 1;
  s[0] = a[0];

  start = clock();
  for (i=1; i<n; i++) {
    if (a[i]>s[len-1]) {

      s[len] = a[i];
      len++;

    }else{
      found = -1;

        for (j=0; j<len; j++) {
          if (a[i] < s[j]) {
            found = j;
            break;
          }
        }

      if (found==0) {
        //shift all by 1
        tmp = a[i];
        for (j=(len-1); j>=0; j--) {
          s[j+1] = s[j];
        }
        len++;
        s[0] = tmp;

      }else{
        //shift after j all by 1
        for (j=(len-1); j>=found; j--) {
          s[j+1] = s[j];
        }
        s[found] = a[i];
        len++;

      }

    }
  }
  end = clock();

  for(x=0; x<n; x++) {
    printf("%d\t", s[x]);
  }

  diff = (double)(end-start)/ CLOCKS_PER_SEC;
  printf("Time Diff : %e\n", diff);

}
