//Vlad Sharpov
//Homework 2

#include <stdio.h>
#include <stdlib.h>

//1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
void from10To2Recursive(int n)
{
	if (n == 1)
	{
		printf("%d", n);
	}
	else
	{
		from10To2Recursive(n / 2);
		printf("%d", n % 2);
	}
}

//2. Реализовать функцию возведения числа a в степень b:
//a. Без рекурсии.
int myPow(int a, int b)
{
	int result = 1;
	while (b > 0)
	{
		result *= a;
		b--;
	}
	return result;
}
//b. Рекурсивно.
int myPowRecursive(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else
	{
		return a * myPowRecursive(a, b - 1);
	}
}
//c. *Рекурсивно, используя свойство чётности степени.
int myPowRecursiveFast(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b % 2 == 0)
	{
		return myPowRecursiveFast(a * a, b / 2);
	}
	else
	{
		return a * myPowRecursive(a, b - 1);
	}
}

//3. **Исполнитель «Калькулятор» преобразует целое число, записанное на экране. У исполнителя две команды, каждой присвоен номер: 
//1) Прибавь 1.
//2) Умножь на 2.
//Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.
//Определить, сколько существует программ, которые преобразуют число 3 в число 20
int calculator(int a, int b, int ways)
{
	if (a == b)
	{
		return 1;
	}
	else if (a > b)
	{
		return 0;
	}
	else //if (a < b)
	{
		ways += ( calculator(a + 1, b, ways) + calculator(a * 2, b, ways) );
		return ways;
	}
}

int main()
{
	//1
	int n = 34;
	printf("1. %d in binary is ", n);
	from10To2Recursive(n);
	printf("\n");

	//2
	int a = 3;
	int b = 4;
	printf("\n2. No recursion: %d ^ %d = %d\n", a, b, myPow(a, b));
	printf("With recursion: %d ^ %d = %d\n", a, b, myPowRecursive(a, b));
	printf("With recursion and fast: %d ^ %d = %d\n", a, b, myPowRecursiveFast(a, b));

	//3
	a = 3, b = 20;
	printf("\n3. Number of ways: %d", calculator(a, b, 0));

	return 0;
}