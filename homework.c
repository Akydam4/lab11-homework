#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");

	int n;
	printf("Введите количество элементов массива: ");
	scanf("%d", &n);

	if (n <= 0 || n > 100)
	{
		printf("Некорректный размер массива\n");
		return 0;
	}

	int a[100];
	printf("Введите %d элементов массива:\n", n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	int min_val = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min_val)
		{
			min_val = a[i];
		}
	}

	long sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != min_val)
		{
			sum += a[i];
			count++;
		}
	}

	printf("Минимальный элемент: %d\n", min_val);
	if (count > 0)
	{
		double avg = (double)sum / count;
		printf("Количество элементов кроме минимального: %d\n", count);
		printf("Сумма элементов: %ld\n", sum);
		printf("Среднее арифметическое (кроме минимального): %.2lf\n", avg);
	}
	else
	{
		printf("Все элементы массива равны минимальному значению\n");
	}

	return 0;
}
