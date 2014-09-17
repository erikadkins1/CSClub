#include<stdio.h>
#include<stdio.h>

struct linked_list_node {
int data;
struct linked_list_node *next;
};

struct linked_list {
int size;
struct linked_list_node *root;
};

// deletes all nodes starting at node
void deleteNodes(struct linked_list_node *node) {

if( node != NULL ) {

// deallocate next, if it exists
if( node->next != NULL ) {
deleteNodes(node->next);

// lose the pointer
node->next = NULL;
}

// deallocate node
free(node);
}
}

// deletes the given linked list
void deleteLinkedList(struct linked_list *list) {

if( list != NULL ) {

// delete nodes
deleteNodes(list->root);

// lose the pointer
list->root = NULL;

// delete actual list
free(list);
}
}

// returns a pointer to a new linked list node with the given data
struct linked_list_node* createLinkedListNode(const int data) {

// allocate memory for new node
struct linked_list_node *newNode = malloc(sizeof(struct linked_list_node));

// initialize
newNode->data = data;
newNode->next = NULL;

return newNode;
}

// adds a new node to the end of list with the given data
void addNode(struct linked_list *list, const int data) {

if( list != NULL ) {

if( list->root == NULL ) {

// with an empty list, replace root
list->root = createLinkedListNode(data);

}else {

// find last node to append to
struct linked_list_node *current = list->root;
while(current->next != NULL) {
current = current->next;
}

current->next = createLinkedListNode(data);

}

++(list->size);
}
}

// prints list to stdout
void printLinkedList(const struct linked_list *list) {

if( list == NULL ) {

printf("null list\n");

}else {

printf("%d:[", list->size);

if( list->root != NULL ) {

struct linked_list_node *current = list->root;
printf("%d", current->data);
while( current->next != NULL ) {
current = current->next;
printf(", %d", current->data);
}

}

printf("]\n");

}
}

// returns a pointer to a new linked list
struct linked_list* createLinkedList() {

// allocate memory for new list
struct linked_list *newList = malloc(sizeof(struct linked_list));

// initialize
newList->size = 0;
newList->root = NULL;

return newList;
}

// returns the data located at node i
// returns -1 if list is null/empty or if i is outside the bounds of list
int getDataAt(const struct linked_list *list, const int i) {

if( list 0) (i < 0) (i >= list->size) ) {
return -1;
}

struct linked_list_node *current = list->root;
int currentIndex;

// move to list[i]
for(currentIndex = 0; currentIndex < i; ++currentIndex) {
current = current->next;
}

return current->data;
}

// inserts a node at position i with the given data
// does nothing if list is null or if i is outside the bounds of list
void insertNode(struct linked_list *list, const int i, const int data) {

if( list 0 ) {

// create new node
struct linked_list_node *newNode = createLinkedListNode(data);
newNode->next = list->root;

list->root = newNode;
++(list->size);

return;
}

struct linked_list_node *current = list->root;
int currentIndex;

// move to list[i]
for(currentIndex = 0; currentIndex < i; ++currentIndex) {
current = current->next;
}

// create new node
struct linked_list_node *newNode = createLinkedListNode(data);
newNode->next = current->next;

current->next = newNode;
++(list->size);

}

// removes the node at position i and returns the data from that node
// returns -1 if list is null/empty or if i is outside the bounds of list
int removeNode(struct linked_list *list, const int i) {

if( list 0 ) {

// store data
const int data = list->root->data;
struct linked_list_node *temp = list->root;

// cut out the root
list->root = list->root->next;

// cleanup
temp->next = NULL;
deleteNodes(temp);

--(list->size);

return data;
}

struct linked_list_node *current = list->root;
int currentIndex;

// get last node before the specified one
for(currentIndex = 1; currentIndex < i; ++currentIndex) {
current = current->next;
}

// store data
const int data = current->next->data;
struct linked_list_node *temp = current->next;

// cut out the node
current->next = current->next->next;

// cleanup
temp->next = NULL;
deleteNodes(temp);

--(list->size);

return data;
}


// example of use
int main(int argc, char** argv) {

// create a new linked list
struct linked_list *list = createLinkedList();

// print out the empty list
printLinkedList(list);

// fill it with some numbers, printing as we go
int i;
for( i = 0; i < 10; ++i ) {
addNode(list, i);
printLinkedList(list);
}printf("\n");

// get some data
printf("list[0] = %2d\n", getDataAt(list, 0));
printf("list[5] = %2d\n", getDataAt(list, 5));
printf("list[9] = %2d\n", getDataAt(list, 9));
printf("list[10] = %2d\n", getDataAt(list, 10));
printf("list[11] = %2d\n", getDataAt(list, 11));
printf("list[-1] = %2d\n", getDataAt(list, -1));
printf("\n");

// remove some data
printf("remove[9]: %2d\t", removeNode(list, 9));
printLinkedList(list);
printf("remove[5]: %2d\t", removeNode(list, 5));
printLinkedList(list);
printf("remove[0]: %2d\t", removeNode(list, 0));
printLinkedList(list);
printf("remove[11]:%2d\t", removeNode(list, 11));
printLinkedList(list);
printf("remove[-1]:%2d\t", removeNode(list, -1));
printLinkedList(list);
printf("\n");

// insert some data
insertNode(list, 3, 5);
printf("\t\t"); printLinkedList(list);
insertNode(list, 0, 0);
printf("\t\t"); printLinkedList(list);
printf("\n");

// dealloc all memory assigned to list
deleteLinkedList(list);
list = NULL; // REMEMBER: lose our pointer so we don't try to use it again by accident

// print null list
printLinkedList(list);


return 0;
} 