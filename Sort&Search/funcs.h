#pragma once
#include <iostream>
using namespace std;

void swap(int& i, int& j);
void bubbleSort(int* a, int n);
void cocktailSort(int* a, int n);
void selectionSort(int* a, int n);
int partition(int* a, int low, int high);
void quickSort(int* a, int low, int high);
void merge(int* a, int low, int mid, int high);
void mergeSort(int* a, int low, int high);