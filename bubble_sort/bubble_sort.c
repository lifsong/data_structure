#include "bubble_sort.h"

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int* data, int len)
{
  while(len)
  {
    for(int i=0; i < len-1; i++)
    {
      if(*(data + i) > *(data + i + 1) ) swap(data + i, data + i + 1);
    }
    len--;
  }
}

