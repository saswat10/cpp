#include <stdio.h>
#include <stdlib.h>

struct Element
{
  int i, j, x;
};

struct Sparse
{
  int m, n, num;
  struct Element *element;
};

void Create(struct Sparse *s)
{
  printf("Enter dimensions: ");
  scanf("%d %d", &s->m, &s->n);
  printf("\nNumber of non-zero elements:");
  scanf("%d", &s->num);

  s->element = (struct Element *)malloc(s->num * sizeof(struct Element));
}

int main()
{
  return 0;
}