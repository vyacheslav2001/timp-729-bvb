// Обход в ширину



#include <stdlib.h>

#include <stdio.h>

int N = 0;



typedef struct node {

  int key;

  struct node *parent;

  struct node *left;

  struct node *right;

} node;



typedef struct tree { node *root; } tree;



void init(tree **t) {

  *t = (tree *)malloc(sizeof(tree));

  (*t)->root = NULL;

}



int insert(tree *t, int value) {

  node *tmp_new = (node *)malloc(sizeof(node));

  tmp_new->key = value;

  tmp_new->left = NULL;

  tmp_new->right = NULL;



  if (t->root) {

    node *tmp = t->root;

    while (tmp) {

      if (tmp->key == value)

        return 1;

      else if (tmp_new->key > tmp->key) {

        if (tmp->right) {

          tmp = tmp->right;

        } else {

          tmp->right = tmp_new;

          tmp_new->parent = tmp;

          N++;

          return 0;

        }

      } else if (tmp_new->key < tmp->key) {

        if (tmp->left) {

          tmp = tmp->left;

        } else {

          tmp->left = tmp_new;

          tmp_new->parent = tmp;

          N++;

          return 0;

        }

      }

    }

  } else {

    t->root = tmp_new;

    N++;

    tmp_new->parent = NULL;

    return 0;

  }

}



void shirina(node *n) {

  node **arr = (node **)malloc(sizeof(node *) * N);

  int last, first;

  arr[0] = n;

  last = 0;



  node *tmp;

  for (first = 0; first < N; first++) {

    tmp = arr[first];

    if (tmp->left) {

      arr[last + 1] = tmp->left;

      last++;

    }

    if (tmp->right) {

      arr[last + 1] = tmp->right;

      last++;

    }

  }

  for (int i = 0; i < N; i++) {

    printf("%i", arr[i]->key);

    printf(" ");

  }

  printf("\n");

}



int main() {

  tree *t;

  init(&t);



  int a;

  for (int i = 0; i < 7; i++) {

    (void)scanf("%i", &a);

    insert(t, a);

  }

  shirina(t->root);

  return 0;

}
