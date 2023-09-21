#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/*
list_t - type definition for a linked list itself. It returns a pointer to the head of the list.
node_t - A type definition for the nodes of the linked list. Each node contains a value of type elem and a pointer to the next node.
*/

int main() {
  printf("Test 1\n");
  //list_add_to_front
  //list_add_to_back
  //list_add_at_index
  //list_print
  //list_length
  //list_remove_from_back
  //list_remove_from_front
  //list_remove_at_index
  //list_is_in
  //list_get_elem_at
  //list_get_index_of

  list_t *my_list = list_alloc();

  /*
  list_add_to_front
  */
  list_add_to_front(my_list,20);
  list_add_to_front(my_list,10);

  /*
  list_add_to_back
  */
  list_add_to_back(my_list,30);
  list_add_to_back(my_list, 40);

  /*
  list_add_to_index
  last parameter is the index, starting from 0.
  */
  list_add_at_index(my_list,0,0);
  list_add_at_index(my_list,1,1);
  list_add_at_index(my_list,1,6);
  // simply not added to the list
  list_add_at_index(my_list,8,8);

  /*
  list_print
  */
  list_print(my_list);

  /*
  list_length
  */
  printf("%d\n",list_length(my_list));

  /*
  list_remove_from_back
  */
  printf("%d\n",list_remove_from_back(my_list));
  printf("%d\n",list_remove_from_back(my_list));
  list_print(my_list);

  /*
  list_remove_from_front
  */
  printf("%d\n",list_remove_from_front(my_list));
  printf("%d\n",list_remove_from_front(my_list));
  printf("Check\n");
  list_print(my_list);

  /*
  list_remove_at_index
  */
  list_t *list_1 = list_alloc();
  // returns -1 since the list is empty
  printf("%d\n",list_remove_at_index(list_1,0));
  // returns -1 since the list is out of index
  printf("%d\n",list_remove_at_index(my_list,5));
  printf("%d\n",list_remove_at_index(my_list,0));
  printf("%d\n",list_remove_at_index(my_list,1));

  /*
  list_is_in
  */
  list_t *list_2 = list_alloc();
 list_add_to_back(list_2,0);
  list_add_to_back(list_2,1);
  list_add_to_back(list_2,2);
  list_add_to_back(list_2,3);
  list_add_to_back(list_2,4);
  list_add_to_back(list_2,5);
  printf("Is %d in the list?: %d\n", 0, list_is_in(list_2, 0));
  printf("Is %d in the list?: %d\n", 6, list_is_in(list_2, 6));

  /*
  list_get_elem_at
  */
  list_print(list_2);
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(list_2, 0));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(list_2, 5));
 // returns -1 since the list is out of index
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(list_2, 6));

  /*
  list_get_index_of
  */
  printf("Index of %d?: %d\n", 0, list_get_index_of(list_2, 0));
  printf("Index of %d?: %d\n", 5, list_get_index_of(list_2, 5));
 // returns -1 since the element is not found in the linked list
  printf("Index of %d?: %d\n", 10, list_get_index_of(list_2, 10)); 


  printf("Test 2\n");
  list_t *list_a = list_alloc();

  list_add_to_front(list_a, 30);
  list_add_to_front(list_a, 20);
  list_add_to_back(list_a, 40);
  list_add_to_back(list_a, 60);
  list_add_at_index(list_a, 10, 0);
  list_add_at_index(list_a, 50, 4);
  list_add_at_index(list_a, 70, 6);
  list_add_at_index(list_a, 90, 8);
  list_print(list_a);
  list_free(list_a);
  list_print(list_a);

  printf("Test 3 - Negative indices test cases for add_to_index\n");
  list_t *list_b = list_alloc();
  list_add_to_back(list_b, 2);
  list_add_to_back(list_b, 3);
  list_add_to_back(list_b, 4);
  list_add_to_back(list_b, 5);
  list_add_at_index(list_b, 1, 0);
  list_add_at_index(list_b, 6, -1);
  list_add_at_index(list_b, 0, -6);
  list_add_at_index(list_b, 0, -8);  
  list_print(list_b);

  printf("Test 4 - Negative indices test cases for remove_at_index\n");
  list_t *list_c = list_alloc();
  list_add_to_back(list_c, 1);
  list_add_to_back(list_c, 2);
  list_add_to_back(list_c, 3);
  list_add_to_back(list_c, 4);
  list_add_to_back(list_c, 5);
  list_remove_at_index(list_c, -6);
  list_remove_at_index(list_c, -5);
  list_remove_at_index(list_c, -1);
  list_print(list_c);
  return 0;
}

