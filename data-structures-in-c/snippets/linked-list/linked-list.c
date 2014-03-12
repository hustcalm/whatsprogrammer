#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define IS_EMPTY(ptr) (!(ptr))

typedef struct list_node *list_pointer;

typedef struct list_node {
	//size_t data_member;
	int data;
	list_pointer link;
}list_node;


/**
 * create a linked list with two nodes 
 */
list_pointer create2()
{
	list_pointer first, second;
	first = (list_pointer)malloc(sizeof(list_node));
	second = (list_pointer)malloc(sizeof(list_node));

	second->link = NULL;
	second->data = 20;

	first->data = 10;
	first->link = second;

	return first;
}

/**
 * insert a new node with data = 50 into the list
 */
void insert(list_pointer *ptr, list_pointer node)
{
	list_pointer temp;
	temp = (list_pointer)malloc(sizeof(list_node));

	if(IS_EMPTY(temp)) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}

	temp->data = 50;

	if(*ptr) {
		temp->link = node->link;
		node->link = temp;
	}
	else {
		temp->link = NULL;
		*ptr = temp;
	}
}

/**
 * delete node from the list, trail is the preceding node
 * ptr is the head of the list
 */
void delete(list_pointer *ptr, list_pointer trail, list_pointer node)
{
	if (trail) 
		trail->link = node->link;
	else
		*ptr = (*ptr)->link;

	free(node);
}

/**
 * output the linked list
 */
void print_list(list_pointer ptr)
{
	printf("The list contains: ");
	for (; ptr; ptr = ptr->link)
		printf("%4d",ptr->data);
	printf("\n");
}
	
/**
 * invert the list pointed by lead
 */
list_pointer invert(list_pointer lead)
{
	list_pointer middle, trail;
	middle = NULL;

	while(lead) {
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}

	return middle;
}

/**
 * produce a new list that contains the list ptr1 followed
 * by the list ptr2. The list pointed by ptr1 is changed permanently
 */
list_pointer concatenate(list_pointer ptr1, list_pointer ptr2)
{
	list_pointer temp;
	if (IS_EMPTY(ptr1)) return ptr2;
	else {
		if(!IS_EMPTY(ptr2)) {
			for(temp = ptr1; temp->link; temp = temp->link)
				;
			temp->link = ptr2;
		}

	return ptr1;

	}
}
	
int main(int argc, char** argv)
{
	/*
	list_pointer ptr = NULL;

	ptr = (list_pointer)malloc(sizeof(list_node));
	strcpy(ptr->data, "bat");
	ptr->link = NULL;
	*/

	list_pointer testList;
	testList = create2();
	print_list(testList);

	insert(&testList, testList->link);
	print_list(testList);

	list_pointer trail, node;
	trail = testList->link;
	node = trail->link;

	delete(&testList, trail, node);
	print_list(testList);

	list_pointer inverseList;
	inverseList = invert(testList);
	print_list(inverseList);

	
	list_pointer concatenateList;
	concatenateList = concatenate(testList, inverseList);
	print_list(concatenateList);
	

	return 0;
}

