#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Creation for the Node of LINKED LIST
struct Node
{
  int data;
  struct Node *next;
} *first = NULL; // global pointer for initialization

// CREATE function
void Create(int A[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));

  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

// ITERATIVE DISPLAY FUNCTION
void Display(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

// RECURSIVE DISPLAY FUNCTION
void RDisplay(struct Node *p)
{
  if (p != NULL)
  {
    RDisplay(p->next);
    printf("%d ", p->data);
  }
}

// RECURSIVELY COUNT THE NODES
int RCount(struct Node *p)
{
  if (p != NULL)
    return RCount(p->next) + 1;
  return 0;
}

// ITERATIVELY COUNT THE NODES
int Count(struct Node *p)
{
  int l = 0;
  while (p != NULL)
  {
    l++;
    p = p->next;
  }
  return l;
}

// Maximum of the function
int Max(struct Node *p)
{
  int max = INT_MIN;
  while (p)
  {
    if (p->data > max)
      max = p->data;
    p = p->next;
  }
  return max;
}

int RMax(struct Node *p)
{
  int x = 0;
  if (p == 0)
    return INT_MIN;
  x = RMax(p->next);
  if (x > p->data)
    return x;
  else
    return p->data;
}

struct Node *LSearch(struct Node *p, int key)
{
  struct Node *q;
  while (p != NULL)
  {
    if (p->data == key)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

void Insert(struct Node *p, int index, int val)
{
  struct Node *t;
  if (index < 0 || index > Count(p))
  {
    printf("Index out of bounds");
    return;
  }
  // below step is crucial otherwise it throws error!!
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = val;
  if (index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

void SortedInsert(struct Node *p, int x)
{
  struct Node *t, *q = NULL;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  if (first == NULL)
    first = t;
  else
  {
    while (p && p->data < x)
    {
      q = p;
      p = p->next;
    }
    if (p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
  }
}

int Delete(struct Node *p, int index)
{
  struct Node *q = NULL;
  int x = -1, i;
  if (index < 1 || index > Count(p))
    return -1;
  if (index == 1)
  {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  }
  else
  {
    for (i = 0; i < index - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int isSorted(struct Node *p)
{
  int x = INT_MIN;
  while (p != NULL)
  {
    if (p->data < x)
      return 0;
    x = p->data;
    p = p->next;
  }
  return 1;
}

void RemoveDuplicate(struct Node *p)
{
  struct Node *q = p->next;
  while (q != NULL)
  {
    if (p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

void Reverse1(struct Node *p)
{
  int *A, i = 0;
  struct Node *q = p;
  A = (int *)malloc(sizeof(int) * Count(p));

  while (q != NULL)
  {
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q != NULL)
  {
    q->data = A[i];
    q = q->next;
    i--;
  }
}

void Reverse2(struct Node *p)
{
  struct Node *q, *r;
  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

void Reverse3(struct Node *p, struct Node *q)
{
  if (p)
  {
    Reverse3(p, p->next);
    p->next = q;
  }
  else
    first = q;
}

int isLoop(struct Node *f)
{
  struct Node *p, *q;
  p = q = f;

  do
  {
    p = p->next;
    q = q->next;
    q = q ? q->next : q;
  } while (p && q && p != q);
  if (p == q)
    return 1;
  else
    return 0;
}

int main()
{
  int A[] = {3, 4, 5, 6, 7, 8, 9};
  Create(A, 7);
  SortedInsert(first, 55);
  SortedInsert(first, 44);
  SortedInsert(first, 10);
  SortedInsert(first, 1);

  // struct Node *t1, *t2;
  // t1 = first->next->next;
  // t2 = first->next->next->next->next;
  // t2->next = t1;

  printf("%d", isLoop(first));
  return 0;
}