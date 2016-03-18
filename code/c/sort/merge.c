#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
  int i,j,k;
  int n, tmp, p, rem, seg;

  int *a;
  int *ta;

  printf("Enter the no of elem\n" );
  scanf("%d", &n);

  a = malloc(n*sizeof(int));
  ta = malloc(n*sizeof(int));

  printf("enter %d elem\n", n);
  for(i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  ta = a;

  for(i=0; i<n; i++) {
    printf("%d\t", ta[i]);
  }

  seg = n;
  rem = n%2;

  while (seg != 1) {
    if (rem == 0) {

      for (i=0; i<seg; i+2) {
          
      }

      seg = seg/2;
      rem = seg%2;
    }else{


      seg = (seg/2) + 1;
      rem = seg%2;
    }
  }




}
