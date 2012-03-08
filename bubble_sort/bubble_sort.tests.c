#include "bubble_sort.h"
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void print_int_arrary(const char* prefix, int* array, int len)
{
  printf("%s", prefix);

  for(int i = 0; i < len; i++)
  {
    printf("%d", *(array+i));
  }
  printf("\n");
}

bool EXPECT_DATA(int* expected, int* actual, int len)
{
  int i;
  for(i = 0; i < len; i++)
  {
    if(*(expected + i) != *(actual + i))
    {
      print_int_arrary("expected: ", expected, len);
      print_int_arrary("but actual: ", actual, len);
      return false;
    }
  }
  return true;
}

#define EXECUTE_AND_CHECK(data, expected, len) {bubble_sort(data, len); assert(EXPECT_DATA(expected, data, len)); }

static void test_sort_one_int(void)
{
	int data[1] = {1};
	int expected[1] = {1};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

static void test_sort_two_equal_int(void)
{
  int data[] = {0, 0};
  int expected[] = {0, 0};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

static void test_sort_two_acsending_int(void)
{
  int data[] = {1, 2};
  int expected[] = {1, 2};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

static void test_sort_two_descending_int(void)
{
  int data[] = {2, 1};
  int expected[] = {1, 2};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

static void test_sort_213(void)
{
  int data[] = {2, 1, 3};
  int expected[] = {1, 2, 3};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

static void test_sort_321(void)
{
  int data[] = {3, 2, 1};
  int expected[] = {1, 2, 3};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

static void test_sort_complex(void)
{
  int data[] = {24, 13, 25, 1, 5, 2, 1};
  int expected[] = {1, 1, 2, 5, 13, 24, 25};
  int len = sizeof(data)/sizeof(int);

  EXECUTE_AND_CHECK(data, expected, len);
}

typedef void test(void);

static test * tests[ ] =
{
  test_sort_one_int,
  test_sort_two_equal_int,
  test_sort_two_acsending_int,
  test_sort_two_descending_int,
  test_sort_213,
  test_sort_321,
  test_sort_complex,
  (test*)0,
};

int main(void)
{
  size_t at = 0;
  while (tests[at])
  {
      tests[at++]();
      putchar('.');
  }
  printf("\n%zd tests passed", at);
  return 0;
}

