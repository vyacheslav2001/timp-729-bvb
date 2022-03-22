#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// сортировака расческа
int racheska(int *arr, int arr_len, FILE *f)
{
    int j = arr_len;
    bool step = true;
    int tmp;
    int k = 0;
    while (j > 1 || step == true)
    {
        if (j > 1)
            j /= 1.247f;
        step = false;
        for (int i = 0; i + j < arr_len; ++i)
        {
            k++;
            if (arr[i + j] < arr[i])
            {
                tmp = arr[i];
                arr[i] = arr[i + j];
                arr[i + j] = tmp;
                step = 1;
                k++;
            }
            for (int i = 0; i < arr_len; i++)
            fprintf (f, "%d ", arr[i]);
            fprintf (f, "\n");
        }
    }
    return k;
}

// сортировка методом Шелла
int Shella(int *arr, int arr_len, FILE *f1)
{
    int step, tmp, j;
    int k = 0;
    for (step = arr_len / 2; step > 0; step /= 2)
        for (int i = step; i < arr_len; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                k++;
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
            k++;
            for (int i = 0; i < arr_len; i++)
            fprintf (f1, "%d ", arr[i]);
            fprintf (f1, "\n");
        }
    return k;
}

int main()
{
// создание файлов
FILE *f; 
f = fopen("racheskasort.log", "w");

FILE *f1; 
f1 = fopen("Shellasort.log", "w");

int n;
    scanf("%d", &n);
    int mas[n];
    int mas1[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &mas[i]);

    for (int i = 0; i < n; i++)
        mas1[i] = mas[i];

racheska(mas, n, f); // вызов функции сортировки
for (int k = 0; k < n; k++)
          fprintf (f, "%d ", mas[k]); // запись в файл
      fprintf (f, "\n");

Shella(mas1, n, f1); // вызов функции сортировки
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
