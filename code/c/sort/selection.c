#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {
    int n, i, j, sml, p, tmpj;
    int *a;

    clock_t start, end;
    double timeDiff;

    printf("enter size of array\n");
    scanf("%d", &n);

    a = malloc(n*sizeof(int));
    printf("Enter the %d len array\n", n);

    //method frst to get input
    //scanf("%s", s);

    //method 2 to get input
    /*getchar();
    while ((a = getchar()) != '\n') {
      s[len] = a;
      len++;
    }*/
    getchar();

    for (i=0; i<n; i++) {
      scanf("%d", &a[i]);
    }
    /*printf("\n" );
    for (i=0; i<n; i++) {
      printf("%d\n", s[i]);
    }*/

    start = clock();
    for(i=0; i<n-1; i++) {
      sml = a[i];
      for (j=i; j<n-1; j++) {
          if (sml>a[j+1]) {
            sml = a[j+1];
            tmpj = j+1;
          }
      }

      if(sml != a[i]) {
        p = a[i];
        a[i] = a[tmpj];
        a[tmpj] = p;
      }
    }
    end = clock();
    timeDiff = (double)(end - start);

    printf("\n" );
    for (i=0; i<n; i++) {
      printf("%d\n", a[i]);
    }
    printf("\n" );
    printf("Time :  %e\n", timeDiff);


}
