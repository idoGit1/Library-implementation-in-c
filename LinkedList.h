#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
	int value;
	struct Node* next;
};

typedef struct Node Node;


// Node Constructor


Node newNode(int value)
{
	Node node = { value, NULL };
	return node;
}


// Add Node at end:


void addNode(Node* src, Node newNode)
{

	while (src->next != NULL)
	{
		src = src->next;
	}
	src->next = &newNode;
}


// Remove Last Node


void removeLastNode(Node* src)
{
	while (src->next != NULL)
	{
		src = src->next;
	}
	src->next = NULL;
}


// Copy list of Nodes


Node copyNode(Node src)
{
	Node cpy = newNode(src.value);
	Node* iterator = &cpy;
	src = *(src.next);

	while (src.next != NULL)
	{
		addNode(iterator, (Node){ src.value, NULL });
		src = *(src.next);
		iterator = (*iterator).next;
	}

	addNode(iterator, (Node) { src.value, NULL });
	return cpy;
}


// Print List


void printList(Node src)
{
	while (src.next != NULL)
	{
		printf("%d -> ", src.value);
		src = *(src.next);
	}
	printf("%d", src.value);
}


// Add Node at the satrt


void addNodeAtStart(Node* src, Node newNode)
{
	addNode(&newNode, *src);
	*src = newNode;
}


// List Length


int length(Node src)
{
	int n = 1;
	while (src.next != NULL)
	{
		src = *src.next;
		n++;
	}
	return n++;
}
