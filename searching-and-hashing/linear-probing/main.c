#include "linear.h"

int main() {
  struct Record table[TSIZE];
	
  struct student rec;

  int i,key,choice;
	
  for(i=0; i<=TSIZE-1; i++)
    table[i].status = EMPTY;
		
  while(1) {
    printf("1. Insert a record\n");
    printf("2. Search a record\n");
    printf("3. Delete a record\n");
    printf("4. Display table\n");
    printf("5. Exit\n");

    printf("Enter your choice\n");
    scanf("%d",&choice);

    switch(choice) {
    case 1 : 
      printf("Enter studentId  : ");
      scanf("%d",&rec.studentId);
      printf("Enter student name : ");
      scanf("%s",rec.studentName);
      insert(rec,table);
      break;
    case 2 : 
      printf("Enter a key to be searched : ");
      scanf("%d", &key);
      i = search(key, table);
      if(i==-1)
	printf("Key not found\n");
      else {
	printf("Key found at index %d\n", i);
	printf("%d %s", table[i].info.studentId, table[i].info.studentName);
      }
      break;
    case 3: 
      printf("Enter a key to be deleted\n");
      scanf("%d",&key);
      del(key, table);
      break;
    case 4:
      displayTable(table);
      break;
    case 5:
      exit(1);
      break;
    default :
      debug ("Wrong Entry!");
      break;
    }
  }
}
