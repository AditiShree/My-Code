#include <stdio.h>

int start = -1, end = -1;
int q[6];

void enqueue() {
  int elem;
  printf("Enter the no to insert\n");
  scanf("%d", &elem);

  if((start == -1) && (end == -1)) {
    start++;
    q[start] = elem;
    end++;
  }else if ((end == 5) && (start > 0)) {
    q[0] = elem;
    end = 0;
  }else if ((start == (end+1)) || ((start == 0) && (end == 5))) {
    printf("Dequeue to enter a new element\n");
  }else {
    end++;
    q[end] = elem;
  }

}

int dequeue() {
  int deq;
  if((start == -1) && (end == -1)) {
    printf("Queue underflow\n");
    return 987;
  }else if ((start == 5) && (end != 5)) {
    deq = q[start];
    start = 0;
  }else if((start == end) && ((start != -1) && (end != -1))) {

    deq = q[start];
    start = -1;
    end = -1;

  }else{
    deq = q[start];
    start++;
  }

  return deq;

}

void display() {
  int s, e, i;
  s = start;
  e = end;

  if(s<e) {
    for(i=s; i<=e; i++) {
      printf("%d\t", q[i]);
    }
  }else if(s>e) {
    i = start;
    while(i) {
      printf("%d\t", q[i]);
      i++;
      if(i == 5) {
        printf("%d\t", q[i]);
        i = 0;
      }
    }

    for(i=0; i<=end; i++) {
      printf("%d\t", q[i]);
    }


  }else if((s == -1) && (e == -1)){
    printf("Empty queue\n");
  }else{
    printf("%d\t", q[s]);
  }



}

main() {
  int choice, i, j, done = 0;
  int deq;

  while(!done) {

    printf("Enter the choice \n");
    printf("1.Enqueue\t 2.Dequeue\t 3.Display\t 4.Exit \n");
    scanf("%d", &choice);

    switch(choice) {
      case 1 : enqueue();
        break;
      case 2 : deq = dequeue();
        printf("Dequeued elem is %d\n", deq);
        break;
      case 3 : display();
        break;
      case 4 : done = 1;

    }
  }


}
