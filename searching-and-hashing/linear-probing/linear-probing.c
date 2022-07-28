#include<stdio.h>
#include<stdlib.h>
#include "linear.h"

int hash(int key) {
  return (key%TSIZE);
}

void insert(struct student rec, struct Record table[]) {
  int i, location, h;
	
  int key = rec.studentId;	
  h = hash(key);				
	
  location = h;	

  for(i=1; i<TSIZE; i++) {
    if(table[location].status == EMPTY || table[location].status == DELETED) { 
      table[location].info = rec;
      table[location].status = OCCUPIED;	
      printf("Record inserted\n\n");
      return;
    }
    if(table[location].info.studentId == key) {
      printf("Duplicate key\n\n");
      return;
    }
    debug ("location = %d", location);
    location = ( h + i) % TSIZE;
    debug ("location = %d", location);
  }
  printf("Record can't be inserted : Table overFlow\n\n");
}


int search(int key, struct Record table[]) {
  int i, h, location;
  h = hash(key);				

  location = h;

  for(i=1; i<TSIZE; i++) {
    if(table[location].status == EMPTY) 
      return -1;
    if(table[location].info.studentId == key)
      return location;
    location = ( h + i ) % TSIZE;								
  }
  return -1;
}

void displayTable(struct Record table[]) {
  int i;
  for(i=0; i<TSIZE; i++) {
    printf("[%d]  : ",i );
    if(table[i].status==OCCUPIED) 
      printf("Occupied : %d   %s\n",table[i].info.studentId, table[i].info.studentName);
    else if(table[i].status==DELETED)
      printf("Deleted\n");
    else
      printf("Empty\n");
  }
}

void del(int key, struct Record table[]) {
  int location = search(key, table);
  if(location == -1)
    printf("Key not found\n");
  else
    table[location].status = DELETED;
}
