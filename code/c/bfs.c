#include <stdio.h>

int visited[20], order[20] ;
int n, count = 0;

void bfs(int **m, int head) {

  int tmp[20], tcount = 0, i;
  for(i=0; i<n; i++) {
    tmp[i] = -1;
  }

  for(i=0; i<n; i++) {
      if ( (m[head][i] == 1) && (visited[i] != 1) ) {

        //store (who all to b clld recusively) in tmp[]
        tmp[tcount] = i;
        tcount++;

        visited[i] = 1;
        order[count] = i;
        count++;
      }
  }

  for(i=0; i<tcount; i++) {
    bfs(m, tmp[tcount]);
  }


}

main() {
  int  i, j;
  printf("Enter the no of nodes in graph\n");
  scanf("%d", &n);

  int *m[n];
  for(i=0; i<n; i++) {
    m[i] = (int*) malloc(n*sizeof(int));
  }

  printf("Enter the elem\n");
  for(i=0; i<n; i++) {
    printf("Row - %d\n", i);
    for(j=0; j<n; j++) {
      printf("Row-> %d, Col-> %d\t", i,j);
      scanf("%d", &m[i][j]);
    }
   }

   printf("Entered elem are\n");
   for(i=0; i<n; i++) {
     for(j=0; j<n; j++) {
       printf("%d\t", m[i][j]);
     }
     printf("\n");
   }

   int head;
   printf("Enter the start vertex\n");
   scanf("%d", &head);
   printf("%d\n", head);
   if(head>n) {
     printf("Head vertex out of range\n");
   }

   for(i=0; i<n; i++) {
     visited[i] = -1;
     order[i] = -1;

   }

   //algo starts

   visited[head] = 1;
   order[count] = head;
   count++;

   bfs(m ,head);

   int brk = 0;
   printf("Visited or not\n" );
   for(i=0; i<n; i++) {
     printf("%d\n", visited[i]);
     if(visited[i]!=1){
       brk = 1;
       printf("Not connected graph\n");
       break;
     }
   }

   if(!brk) {
     printf("Visited in order-\n");
     for(i=0; i<n; i++) {
       printf("%d\t", order[i]);
     }
   }




}
