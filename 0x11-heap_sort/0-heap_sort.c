#include <stdio.h>
#include "sort.h"

/**
 * swap - aux function that inteexchange the values
 * @val_a: type pointer of first value
 * @val_b: type pointer of second value
 */

void swap(int *val_a, int *val_b)
{
	int v1 = *val_a;
	int v2 = *val_b;

	*val_a = v2;
	*val_b = v1;
}

/**
 * heapify - binary sort
 * @array: type pointer of the array
 * @size: type size_t size
 * @i: type size_t posiition
 * @total_size: type size_t total size of the array
 */

void heapify(int *array, size_t size, size_t i, size_t total_size)
{
	size_t big = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[big])
		big = left;

	if (right < size && array[right] > array[big])
		big = right;

	if (big != i)
	{
		swap(&array[i], &array[big]);
		print_array(array, total_size);
		heapify(array, size, big, total_size);
	}
}

/**
 * heap_sort - heap sort algo
 * @array: Type array
 * @size: n-elements at the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	size_t total_size = size;

	if (array)
	{
		for (i = size / 2 - 1; (int)i >= 0; i--)
			heapify(array, size, i, total_size);
		for (i = size - 1; i > 0; i--)
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
			heapify(array, i, 0, total_size);
		}
	}
}#include "sort.h"

/**
 * swap_values - interchange 2 values of a given list
 * @array: list of numbers
 * @i: index of the value1 to swap
 * @j: index of the value2 to swap
 * @size: original len arr
 * Return: nothing
 */
void swap_values(int *array, int i, int j, int size)
{
	int temp = 0;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * heapify - organize the given list into max heap
 * @array: list of integers
 * @si: len of the heap sort arr
 * @bin: parent node
 * @size: original len array
 * Return: nothing
 */
void heapify(int *array, int si, int bin, int size)
{
	int largt = bin, left = (bin * 2) + 1, rigth = (bin * 2) + 2;

	if (left < si && array[left] > array[largt])
		largt = left;

	if (rigth < si && array[rigth] > array[largt])
		largt = rigth;

	if (largt != bin)
	{
		swap_values(array, bin, largt, size);
		heapify(array, si, largt, size);
	}
}

/**
 * heap_sort - sort a given list using heapsort
 * @array: list of integers
 * @size: len of the array
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int bin = 0, si = size;

	for (bin = (size / 2) - 1; bin >= 0; bin--)
		heapify(array, si, bin, size);

	for (bin = size - 1; bin >= 0; bin--)
	{
		if (bin != 0)
			swap_values(array, bin, 0, size);
		heapify(array, bin, 0, size);
	}
}
