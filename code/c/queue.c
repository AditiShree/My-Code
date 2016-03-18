#include <stdio.h>

int start = -1, end = -1;
int a[20], count = 0;

void enqueue() {
  int elem;
  printf("Enter the elem to insert\n");
  scanf("%d", &elem);

  if((start == -1) && (end == -1)) {
    start++;
    end++;
    a[end] = elem;
  }else if(end<=18){
    end++;
    a[end] = elem;
  }else{
    printf("Queue overflow\n");
  }

}

int dequeue() {
  int elem;

  if((start == -1) && (end == -1)) {
    //printf("Queue underflow\n");
    return 98765;
  }else{
    elem = a[start];
    start++;
  }

  return elem;
}

void display() {
  int i;
  for(i=start; i<=end; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
}

main() {
  int choice, i, j;
  int done = 0;
  int dqelem;

  while(!done) {

    printf("Enter the choice\n");
    printf("1.Enqueue\t 2.Dequeue\t 3.Display\t 4.Exit\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1 : enqueue();
        break;
      case 2: dqelem = dequeue();
        if(dqelem == 98765){
          printf("Queue underflow\n");
        }else{
          printf("Dequeued elem is %d\n", dqelem);
        }
        break;
      case 3: display();
        break;
      case 4: done = 1;
    }
  }



}
