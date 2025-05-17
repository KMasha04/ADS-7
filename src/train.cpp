// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
first = nullptr;
countOp = 0;
}

void Train::addCar(bool light) {
  Car* node = new Car;
  if (!first) {
  node->light = light;
  node->prev = node;
  node->next = node;
  first = node;
  } else {
  node->light = light;
  node->next = first;
  node->prev = first->prev;
  first->prev->next = node;
  first->prev = node;
  }
}

int Train::getLength() {
  if (!first) return 0;
   int carriages = 1;
  countOp = 0;
  first->light = true;
  Car* current = first->next;
  while (!current->light) {
    current = current->next;
    carriages++;
    countOp += 2; 
  }
  return carriages;
}
int Train::getOpCount() {
  return countOp;
}
