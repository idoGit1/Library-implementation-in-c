#pragma once
#include <stdio.h>
#include <stdlib.h>
struct map
{
	char* keys;
	int* values;
	int size;
};

typedef struct map map;

map newMap()
{
	map new_map = { NULL, NULL, 0};
	return new_map;
}


int at(map src, char key)
{

}


void append(map* src, char key, int value)
{
	int n = (*src).size;
	(*src).keys = (char*)realloc((*src).keys, (n + 1) * sizeof(char));
	(*src).values = (int*)realloc((*src).values, (n + 1) * sizeof(int));
	if ((*src).keys == NULL || (*src).values == NULL)
	{
		printf("Failed reallocating. Program is shutting down...");
		exit(1);
	}
	*((*src).keys + n) = key;
	*((*src).values + n) = value;
	(*src).size++;
}


void printMap(map src)
{
	for (int i = 0; i < src.size; i++)
	{
		printf("No.%d\tKey: %c\t\tValue: %d\n", i + 1, *(src.keys + i), *(src.values + i));
	}
}