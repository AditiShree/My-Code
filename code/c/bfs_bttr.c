#include <stdio.h>

int n;
int visited[20], order[20], queue[20];
int oc = 0;
int start = -1, end = -1;
//oc is order count

/*void bfs(int **m, int head) {
  enqueue(head);
}*/

void enqueue(int elem) {

  if((start == -1) && (end == -1)) {
    start++;
    queue[start] = elem;
    end++;
  }else{
    end++;
    queue[end] = elem;

  }

}

int dequeue() {
  int elem;

  if((start == -1) && (end == -1)) {
    printf("Queue underflow\n");
    return -10;
  }

  elem = queue[start];
  start++;

  return elem;
}

int visit() {
  //printf("In visit\n");
  int i;
  for(i=0; i<n; i++) {
    if(visited[i] != 1) {
      return 0;
    }
  }
  return 1;
}



main() {
  int i, j, head;
  printf("Enter the no of nodes\n");
  scanf("%d", &n);

  int *m[n];
  for(i=0; i<n; i++){
    m[i] = (int*) malloc(n*sizeof(int));
  }

  printf("Enter %dx%d elem\n", n, n);
  for(i=0; i<n; i++){
    printf("Row = %d\n", i);
    for(j=0; j<n; j++){
      printf("Col = %d\t\t", j);
      scanf("%d", &m[i][j]);
    }
  }

  printf("Entered array is\n");
  for(i=0; i<n; i++) {
    printf("Row = %d-->\t\t", i);
    for(j=0; j<n; j++) {
      printf("%d\t", m[i][j]);
    }
    printf("\n");
  }

  printf("Enter the head node\n");
  scanf("%d", &head);
  printf("Head = %d\n", head);

  for(i=0; i<n; i++) {
    visited[i] = order[i] = queue[i] = -1;
  }

  visited[head] = 1;
  order[oc] = head;
  oc++;
  enqueue(head);

  int deq, vis, c = 0;
  //c is for checking if graph is connected or not

  while(!(vis = visit())) {
    c++;
    if(c>n) {
      c = -1;
      printf("Graph not connected\n");
      break;
    }
    deq = dequeue();
    if(deq == -10) {
      printf("Queue underflow\n");
    }
    //printf("Deq elem = %d\n", deq);
    for(i=0; i<n; i++) {
      if((m[deq][i] == 1) && (visited[i] != 1)) {
        visited[i] = 1;
        order[oc] = i;
        /*for(j=0; j<n; j++){
          printf("%d\t", order[j]);
        }*/
        oc++;
        enqueue(i);
      }
    }
  }
  if(c != -1) {
    for(i=0; i<n; i++){
      printf("%d\t", order[i]);
    }
  }


}
