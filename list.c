// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t *p;
  p =(list_t*)malloc(sizeof(list_t)); 
  p->head = NULL;
  return p;
}

void list_free(list_t *l) {
  if (!l){
    return;
  }
  node_t *curr = l->head;
  while (curr){
    node_t *temp = curr;
    curr = curr->next;
    free(temp);
  }
}

void list_print(list_t *l) {
  node_t *curr = l->head;
  while (curr != NULL){
    printf("%d\n",curr->value);
    curr = curr->next;
  }
}

int list_length(list_t *l) {
  int count = 0;
  node_t *curr = l->head;
  while (curr != NULL){
    count += 1;
    curr = curr->next;
  } 
  return count; 
}

void list_add_to_back(list_t *l, elem value) {
  if (l->head){
    node_t *curr = l->head;
    while (curr->next){
      curr = curr->next;
    }
    node_t* new_node;
    new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    curr->next = new_node;
    new_node->next = NULL;
  } else {
    list_add_to_front(l,value);
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t* new_node;
  new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  if(l->head){
    new_node->next = l->head;
    l->head = new_node;
  } else {
    new_node->next = NULL;
    l->head = new_node;
  }
}

void list_add_at_index(list_t *l, elem value, int index) {
  int length = list_length(l);

  // Handle negative indices
  if (index < 0) {
    if (index == -length) {
      index = length + index;
    }
    else if (index > -length) {
      index = length + index + 1;
    }
    else {
      printf("index is out of range\n");    
    }
  }

  if (index == 0 || l->head == NULL){
    list_add_to_front(l,value);
    return;
  }

  if (index > length) {
    printf("index is out of range\n");
    return;
  }

  int count = 0;
  node_t *curr = l->head;
  while (curr){
    if (count == index-1){
      node_t* new_node;
      new_node = (node_t*)malloc(sizeof(node_t));
      new_node->value = value;
      new_node->next = curr->next;
      curr->next = new_node;
    }
    count += 1;
    curr = curr->next;
  }
}

elem list_remove_from_back(list_t *l) {
  int removedVal;
  node_t *curr = l->head;
  if (curr == NULL){
    return -1;
  }
  while (curr->next->next != NULL) {
      curr = curr->next;
  }
  removedVal = curr->next->value;
  free(curr->next);
  curr->next = NULL;
  return removedVal;
}

elem list_remove_from_front(list_t *l) { 
  elem removedVal = -1;
  node_t *curr = l->head;
  if (curr == NULL){
    return removedVal;
  }
  l->head = curr->next;
  removedVal = curr->value;
  free(curr);
  return removedVal;
}

elem list_remove_at_index(list_t *l, int index) {
  int length = list_length(l);

  // Handle negative indices
  if (index < 0) { 
    if (index == -length) {
      index = length + index;
    }
    else if (index > -length) {
      index = length + index;
    }
    else {
      printf("index is out of range\n");
      return -1;    
    }
    printf("The value of index is %d\n", index);
  }

  if (index > length || index < 0) {
    printf("index is out of range\n");
    return -1;
  }

  if (length == 0) {
    printf("The given linked list is empty\n");
    return -1;    
  }

  int count = 0;
  node_t *curr = l->head;
  node_t *prev = NULL;

  while (curr) {
    if (count == index) {
      elem removedVal = curr->value;

      // If the node to be removed is the head node
      if (prev == NULL) {
        l->head = curr->next;
      }
      else {
          prev->next = curr->next;
        }

      free(curr);
      return removedVal;
    }
    count += 1;
    prev = curr;
    curr = curr->next;
  }
}

bool list_is_in(list_t *l, elem value) { 
  node_t *curr = l->head;
  while (curr != NULL){
    if (curr->value == value){
      return true;
    }
    curr = curr->next;
  } 
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  int count = 0;
  node_t *curr = l->head;
  while (curr != NULL){
    if (count == index){
      return curr->value;
    }
    count += 1;
    curr = curr->next;
  } 
  return -1;
}

int list_get_index_of(list_t *l, elem value) {
  int count = 0;
  node_t *curr = l->head;
  while(curr != NULL){
    if (curr->value == value){
      return count;
    }
    count += 1;
    curr = curr->next;
  }
  return -1; 
}