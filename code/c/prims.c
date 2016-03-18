#include <stdio.h>

int n;
int done[20], ndone[20], cost[20], index1[200], min = 0;
int d = -1, count = -1, inc = 0;

main() {
  int i, j, k, head;

  printf("Enter the tot no of nodes of graph\n");
  scanf("%d", &n);

  int *c[n];
  for(i=0; i<n; i++) {
    c[i] = (int*) malloc(n*sizeof(int));
  }

  printf("Enter the cost (if present) else 0\n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      scanf("%d", &c[i][j]);
    }
  }

  printf("Input\n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      printf("%d\t", c[i][j]);
    }
    printf("\n");
  }

  printf("Enter head\n");
  scanf("%d", &head);
  printf("Head = %d\n", head);

  for(i=0 ;i<n; i++) {
    done[i] = -1;
    ndone[i] = 1;
    cost[i] = -1;
  }
  int curr, p;
  curr = head;
  d++;
  done[d] = curr;
  ndone[curr] = -1;

  int id1;

  while((++d) != (n)) {
    //clearing the cost storage and its count
    count = 0;
    for(i=0; i<20; i++) {
      cost[i] = 0;
    }
    //inc = 0;

    for(i=0; i<d; i++) {
      curr = done[i];
      for(j=0; j<n; j++) {

        index1[inc] = c[curr][j];
        inc++;

        if (ndone[j] == 1) {
          if(c[curr][j] != 0) {
            cost[count] = c[curr][j];
            count++;
          }
        }

      }
    }

    int small;
    small = cost[0];
    for (i=1; i<count; i++) {
      if(cost[i] < small) {
        small = cost[i];
      }
    }

    printf("inc = %d\n", inc);
    for(i=0; i<inc; i++) {
      if(index1[i] == small) {
        id1 = i%n;

        printf("\ni = %d, id1 = %d\n",i, id1);
        break;
      }
      index1[i] = 0;
    }

    printf("\ncount = %d, small = %d n cost-->\n", count, small);
    for(p=0; p<count; p++) {
      printf("%d\t", cost[p]);
    }

    done[d] = id1;
    printf("\ndone[%d] = %d\n\n", d, id1);
    ndone[id1] = -1;


  }
  printf("\n");
  for(i=0; i<d; i++) {
    printf("%d\t", done[i]);
  }

}
