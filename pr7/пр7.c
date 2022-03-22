#include <stdio.h>
#include <stdlib.h>

// Функция быстрой сортировки
void quickSort(int *mas, int l, int r, FILE *f, int n1) {

    for (int k = 0; k < n1; k++)
          fprintf (f, "%d ", mas[k]);
      fprintf (f, "\n");

    int tmp;
    int x = mas[l+(r-l)/2];
    int i = l;
    int j = r;
    while (i <= j)
    {
      while (mas[i] < x)
          i++;

      while (mas[j] > x)
          j--;

      if(i <= j)
      {
        tmp = mas[i];
        mas[i] = mas[j];
        mas[j] = tmp;
        i++;
        j--;
        for (int k = 0; k < n1; k++)
          fprintf (f, "%d ", mas[k]);
      fprintf (f, "\n");
      }
    }

    if(i < r)
      quickSort(mas, i, r, f, n1);
    
    if(l < j)
      quickSort(mas, l, j, f, n1);    
}

void siftDown(int *mas, int root, int bottom, FILE *f1, int n)
{
    for (int i = 0; i < n; i++)
        fprintf (f1, "%d ", mas[i]);
    fprintf (f1, "\n");

  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована

  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {

    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (mas[root * 2] > mas[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка

    if (mas[root] < mas[maxChild]) 
    {
      int temp = mas[root]; // меняем их местами
      mas[root] = mas[maxChild];
      mas[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}

// Функция пирамидальной сортировки
void heapSort(int *mas, int n, FILE *f1) 
{
  // Формируем нижний ряд пирамиды
  for (int i = (n / 2); i >= 0; i--)
    siftDown(mas, i, n - 1, f1, n);

  // Просеиваем через пирамиду остальные элементы
  for (int i = n - 1; i >= 1; i--)
  {
    int temp = mas[0];
    mas[0] = mas[i];
    mas[i] = temp;
    siftDown(mas, 0, i - 1, f1, n);
  }
}

int main()
{
// файлы для записи в них значений
FILE *f; 
f = fopen("quicksort.log", "w");

FILE *f1; 
f1 = fopen("heapsort.log", "w");

int n;
    scanf("%d", &n);
    int mas[n];
    int mas1[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &mas[i]);

    for (int i = 0; i < n; i++)
        mas1[i] = mas[i];

quickSort(mas, 0, n-1, f, n); // вызов функции сортировки
for (int k = 0; k < n; k++)
          fprintf (f, "%d ", mas[k]); // запись в файл
      fprintf (f, "\n");

heapSort(mas1, n, f1); // вызов функции сортировки
for (int k = 0; k < n; k++)
          fprintf (f1, "%d ", mas1[k]); // запись в файл
      fprintf (f1, "\n");

// Вывод элементов массива после сортировки
for (int i = 0; i < n; i++)
    printf("%d ", mas[i]);
printf("\n");

for (int i = 0; i < n; i++)
    printf("%d ", mas1[i]);
printf("\n");
return 0;
}
