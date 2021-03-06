#include <stdio.h>
#include "desarray.h"

// This is a I/O test client for desarray.c

// check_result(result) returns false if result is 1
//   otherwise true
// effects: prints a message
bool check_result(int result) {
  if (result != 1) {
    printf("Something went wrong, bad input!\n");
    return true;
  }
  return false;
}

int main(void) {
  char c;
  int n;
  struct destack *des;
  
  des = destack_create();
  while(1) {
    if (check_result(scanf(" %c", &c))) break;
  
    // You should add more cases here for I/O testing
    if (c == 'p') { // push
      if (check_result(scanf(" %c", &c))) break;
      if (check_result(scanf("%d", &n))) break;
      if (c == 't') {
        destack_push_top(n, des);
      } else if (c == 'b') {
        destack_push_bot(n, des);
      } else {
        printf("Invalid parameter for PUSH operation.\n");
        continue;
      }
    } else if (c == '1') { // pop
      if (check_result(scanf(" %c", &c))) break;
      if (c == 't') {
        destack_pop_top(des);
      } else if (c == 'b') {
        destack_pop_bot(des);
      } else {
        printf("Invalid parameter for POP operation.\n");
        continue;
      }
    } else if (c == 'r') { // print
      destack_print(des);
    } else if (c == 'q') { // quit
      break;
    } else if (c == 'a') { //top
      if (destack_is_empty(des)) printf("it is empty\n");
      else printf("%d\n",destack_top(des));
    } else if (c == 'b') { //bot
      if (destack_is_empty(des)) printf("it is empty\n");
      else printf("%d\n",destack_bot(des));
    } else if (c == 'e') { //empty
      if (destack_is_empty(des)) printf("it is empty\n");
      else printf("not empty\n");
    } else {
      printf("Invalid operation request.\n");
      continue;
    }
  }
  destack_destroy(des);
}
    
