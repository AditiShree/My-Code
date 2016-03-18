#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
  int *a;
  int n, i, j, big, k, p, q;

  clock_t start, end;
  double diff;

  printf("Enter size of array\n");
  scanf("%d", &n);

  a = malloc(n*(sizeof(int)));

  printf("ENter %d elem\n", n);

  for(i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  start = clock();
  for (i=0; i<n-1; i++) {
    for (j=0; j<n-1-i; j++) {
      if (a[j] > a[j+1]) {
        p = a[j+1];
        a[j+1] = a[j];
        a[j] = p;
      }
    }
  }
  end = clock();
  for (i=0; i<n; i++) {
    printf("%d\t", a[i]);
  }

  diff = (double)(end-start);
  printf("Time diff : %e\n", diff);
}
