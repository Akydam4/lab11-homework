#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define N 10
#define SIZE 100

float calc_func(float x)
{
	return x * x + (float)sin(5.0 * x);
}

int main()
{
	setlocale(LC_ALL, "");

	printf("--- Задание 1 ---\n");
	float A[N];
	float B[N];
	float temp;
	float sum_a = 0.0f;

	for (int i = 0; i < N; i++)
	{
		printf("a[%d] = ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
		B[i] = temp * 2.0f;
		sum_a += temp;
	}

	printf("\n| %-6s | %-17s | %-14s |\n", "индекс", "исходное значение", "новое значение");
	printf("-------------------------------------------------\n");
	for (int i = 0; i < N; i++)
	{
		printf("| %-6d | %-17.2f | %-14.2f |\n", i, A[i], B[i]);
	}
	printf("-------------------------------------------------\n");
	printf("Среднее арифметическое элементов массива: %.2f\n", sum_a / N);

	printf("\n--- Задание 2 ---\n");
	float arr_vals[SIZE];
	float step = 2.0f / (SIZE - 1);
	float sum_pos = 0.0f;
	float sum_neg = 0.0f;
	int count_pos = 0;
	int count_neg = 0;

	for (int i = 0; i < SIZE; i++)
	{
		float cur_x = i * step;
		arr_vals[i] = calc_func(cur_x);
		if (arr_vals[i] > 0.0f)
		{
			sum_pos += arr_vals[i];
			count_pos++;
		}
		else if (arr_vals[i] < 0.0f)
		{
			sum_neg += arr_vals[i];
			count_neg++;
		}
	}

	float avg_pos = 0.0f;
	if (count_pos > 0)
	{
		avg_pos = sum_pos / count_pos;
	}

	printf("Имя массива: arr_vals; Сумма полож.: %.4f; Сумма отриц.: %.4f; Кол-во полож.: %d; Кол-во отриц.: %d; Среднее полож.: %.4f\n",
		sum_pos, sum_neg, count_pos, count_neg, avg_pos);

	return 0;
}
