#include <stdio.h>
#include <stdlib.h>

//структура для хранение ссылок на потомков
typedef struct tree {
  struct tree *Right; // ссылка на правого потомка
  struct tree *Left; // ссылка на левого потомка
  struct tree *parent; // ссылка на предка
  double key; // значение
} tree;

// Инициализация дерева
void init(tree **n) {
  *n = malloc(sizeof(tree));
  (*n) -> Right = NULL;
  (*n) -> Left = NULL;
}

// Удалить все элементы из дерева
void clean(tree *n) {
  if (n) {    
    if (n -> Left)
    clean(n -> Left);
    if (n -> Right)
    clean(n -> Right);
    free(n);
  }
}

// Поиск элемента по значению
tree* find(tree *n, int value) {
  if (n -> key == value)
  return n;
  else {
    if (value < n -> key) {
      if (n -> Left)
      return(find(n -> Left, value));
      else
      return NULL;
    }
    else {
      if (n->Right != NULL)
      return(find(n->Right, value));
      else
      return NULL;
    }
  }
}

// Вставка значения в дерево
int insert(tree *n, int value) {
  if (n -> key == 0) {
    n -> key = value;
    return 0;
  }
  if (n -> key == value)
  return 1;
  if (value > n -> key) {
    if (n -> Right)
    return(insert(n -> Right, value));
    else {
      n -> Right = malloc(sizeof(tree));
      n -> Right -> Right = NULL;
      n -> Right -> Left = NULL;
      n -> Right -> key = value;
      return 0;
    }
  }
  else {
    if (n -> Left)
    return(insert(n -> Left, value));
    else {
      n -> Left = malloc(sizeof(tree));
      n -> Left -> Right = NULL;
      n -> Left -> Left = NULL;
      n -> Left -> key = value;
      return 0;
    }
  }
return 2;
}

//глубина дерева
int deep(tree *n) {
  int r = 0, l = 0;
  if (n -> Right)
  r = deep(n -> Right);
  if (n -> Left)
  l = deep(n -> Left);
  if (r > l)
  return (r + 1);
  return (l + 1);
}

// Удалить элемент из дерева
int remove_node(tree **n, int value) {
  if ((*n) -> key == value) {
    if ((*n) -> Right) {
      tree *current = (*n) -> Right, *current2;
      if (current -> Left) {
        while (current -> Left -> Left)
        current = current -> Left;
        (*n) -> key = current -> Left -> key;
        current2 = current -> Left;
        current -> Left = current2 -> Right;
        free(current2);
      }
        else {
          tree *current;
          (*n) -> key = (*n) -> Right -> key;
          current = (*n) -> Right;
          (*n) -> Right = (*n) -> Right -> Right;
          free(current);
        }
      }
    else {
      tree *current;
      current = (*n);
      (*n) = (*n) -> Left;
      free(current);
      current = NULL;
  }
    return 0;
  }
  else {
    if (value < (*n) -> key) {
      if ((*n) -> Left)
      return(remove_node(&((*n) -> Left), value));
      else
      return 1;
    }
    else {
      if ((*n) -> Right)
      return(remove_node(&((*n) -> Right), value));
      else
      return 1;
    }
  }
}

// Удалить минимальный элемент из поддерева, корнем которого является n
int remove_min(tree *n) {
  tree *current = n, *current2;
  if (current -> Left) {
    while (current -> Left -> Left)
    current = current -> Left;
    current2 = current -> Left;
    current -> Left = current2 -> Right;
    free(current2);
  }
  else {
    current = n -> Right;
    free(n);
    n = current;
  }
  return 0;
}

// Выполнить правое вращение поддерева
int rotate_right(tree **n) {
  if (!(*n))
  return 1;
  tree *n1, *n2, *n3 = (*n) -> Right, *root1 = (*n) -> Left, *root2 = (*n),
  *current = malloc(sizeof(tree));
  if (root1) {
    n1 = root1 -> Left;
    n2 = root1 -> Right;
  }
  else
  return 1;
  current -> Right = root2;
  current -> Left = n1;
  current -> Right->Left = n2;
  current -> Right->Right = n3;
  current -> key = root1 -> key;
  free(root1);
  (*n) = current;
  return 0;
}

// Выполнить левое вращение поддерева
int rotate_left(tree **n) {
  if (!(*n))
  return 1;
  tree *n1 = (*n) -> Left, *n2, *n3, *root1 =
  (*n), *root2 = (*n) -> Right,
  *current= malloc(sizeof(tree));
  if (root2) {
    n2 = root2 -> Left;
    n3 = root2 -> Right;
  }
  else
  return 1;
  current -> Right = n3;
  current -> Left = root1;
  current -> Left -> Right = n2;
  current -> Left -> Left = n1;
  current -> key = root2 -> key;
  free(root2);
  (*n) = current;
  return 0;
}

// Вывести все значения из поддерева
void print(tree *n) {
  if (!n) {
    printf("-\n");
    return;
  }
  tree *current = n;
  int levels = 0, count_levels, count_elements, dir_indicator, y;
  int *revolt;
  levels = deep(n);
  revolt = (int*)malloc(sizeof(int)); 
  for (count_levels = 0; count_levels < levels; count_levels++) { 
    if (count_levels != 0) {
      revolt = (int*)realloc(revolt, count_levels* sizeof(int));
      for (count_elements = 0; count_elements < count_levels; count_elements++)
      revolt[count_elements] = 0;
    }
    count_elements = 1;
    y = count_levels;
    for (; y > 0; y--) {
      count_elements = count_elements * 2;
    }
    while (count_elements != 0) {
      dir_indicator = 0;
      current = n;
      for (dir_indicator = 0; dir_indicator < count_levels; dir_indicator++) {
        if (revolt[dir_indicator] == 0) {  
          if (current -> Left)
          current = current -> Left;
          else {
            dir_indicator = -1;
            break;
          }
        }
        else {
          if (current -> Right)
          current = current -> Right;
          else {
            dir_indicator = -1;
            break;
          }
        }
      }
    if (count_levels != 0) {
      y = count_levels - 1;
      revolt[y]++;
      while (1) {
        if (revolt[y] == 2) {
          revolt[y] = 0;
          y--;
          if (y < 0)
          break;
          else
          revolt[y]++;
        }
        else
        break;
      }
    }
    if (dir_indicator == -1)
    printf("_");
    else
    printf("%d", (int) current -> key);
    count_elements--;
    if (count_elements != 0)
    printf(" ");
    }
    printf("\n");
  }
  return;
}

// Вывести все значения дерева t
void print_tree(tree *t) {
  if (!t) {
    printf("-\n");
    return;
  }
  else {
    print(t);
  }
}

//подсчёт уровней дерева
int calc_count(tree *n) {
  if (!n)
  return 0;
  int right, left;
  left = calc_count(n -> Left);
  right = calc_count(n -> Right);
  return (left + right + 1);
}

//поиск и вывод
int find_and_print(tree *n, int value) {
  if (n -> key == value) {
    printf("_ ");
    if (n -> Left)
    printf("%d ", (int)n -> Left -> key);
    else
    printf("_ ");
    if (n -> Right)
    printf("%d", (int)n -> Right -> key);
    else
    printf("_");
  }
  else {
    if (value < n -> key) {
      if (n -> Left) {
        if (n -> Left -> key == value) {
          printf("%d ", (int)n -> key);
          if (n -> Left -> Left)
          printf("%d ", (int)n -> Left -> Left -> key);
          else
          printf("_ ");
          if (n -> Left -> Right)
          printf("%d", (int)n -> Left -> Right -> key);
          else
          printf("_");
        }
        else
        return(find_and_print(n -> Left, value));
      }
      else
      return 1;
    }
    else {
      if (n -> Right) {
      if (n -> Right -> key == value) {
        printf("%d ", (int)n -> key);
        if (n -> Right -> Left)
        printf("%d ", (int)n -> Right -> Left -> key);
        else
        printf("_ ");
        if (n -> Right -> Right)
        printf("%d", (int)n -> Right -> Right -> key);
        else
        printf("_");
      }
      else
      return(find_and_print(n -> Right, value));
      }
      else
      return 1;
      }
    }
  return 0;
}


int main() {
  tree *t;
  int i;
  double m1, m2, m3;
  double a_i;
  
  init(&t);
  for (i = 0; i < 4; i++) {
    scanf("%lf", &a_i);
    insert(t, a_i);
  }
  print_tree(t);
  printf("\n");
  
  for (i = 0; i < 3; i++) {  
    scanf("%lf", &a_i);
    insert(t, a_i);
  }
  print_tree(t);
  printf("\n");
  
  scanf("%lf", &m1);
  m1 = find_and_print(t, m1);
  if (m1 == 1)
  printf("-");
  printf("\n\n");
  
  scanf("%lf", &m2);
  m2 = find_and_print(t, m2);
  if (m2 == 1)
  printf("-");
  printf("\n\n");
  
  scanf("%lf", &m3);
  remove_node(&t, m3);
  print_tree(t);
  printf("\n");
  
  for (; ;) { 
    a_i = rotate_left(&t);
    if (a_i == 1)
    break;
  }
  print_tree(t);
  printf("\n");
  
  while (1) { 
    a_i = rotate_right(&t);
    if (a_i == 1)
    break;
  }
  print_tree(t);
  printf("\n");
  
  printf("%d\n\n", calc_count(t));
  
  clean(t);
  t = NULL;
  print_tree(t);
  return 0;
}
