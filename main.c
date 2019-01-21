//Vlad Sharpov
//Algorithms and data structures
//Homework 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h),
//где m – масса тела в килограммах, h – рост в метрах.
double massIndex(double h, double m)
{
	return m / (h * h);
}

//2. Найти максимальное из четырёх чисел. Массивы не использовать.
int findMaxFrom4(int a, int b, int c, int d)
{
	return findMaxFrom2(findMaxFrom2(a, b), findMaxFrom2(c, d));
}
int findMaxFrom2(int a, int b)
{
	return (a >= b) ? a : b;
}

//3. Написать программу обмена значениями двух целочисленных переменных :
//a.С использованием третьей переменной.
void swap1(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//b. *Без использования третьей переменной.
void swap2(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *b ^ *a;
}

//4. Написать программу нахождения корней заданного квадратного уравнения.
int solveSquareEquation(int a, int b, int c, float* x1, float* x2)
{
	double D = b * b - 4 * a * c;
	printf("D = %.2lf \n", D);

	if (a == 0)
	{
		*x1 = -c / b;
		*x2 = *x1;

		return 0;
	}
	else if (D < 0)
	{
		return -1;
	}
	else if (D == 0)
	{
		*x1 = -b / (2 * a);
		*x2 = *x1;

		return 0;
	}
	else //if(D > 0)
	{
		*x1 = ((-b + sqrt(D)) / (2 * a));
		*x2 = ((-b - sqrt(D)) / (2 * a));

		return 1;
	}
}

//5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
void monthToYear()
{
	int month = 0;
	printf("\n5) Enter month: \n");
	scanf("%d", &month);

	if (month == 12 || month == 1 || month == 2)
	{
		printf("%02d month belongs to winter!\n", month);
	}
	else if (month >= 3 && month <= 5)
	{
		printf("%02d month belongs to spring!\n", month);
	}
	else if (month >= 6 && month <= 8)
	{
		printf("%02d month belongs to summer!\n", month);
	}
	else if (month >= 9 && month <= 11)
	{
		printf("%02d month belongs to autumn!\n", month);
	}
	else
	{
		printf("Error: invalid input\n");
	}
}

//6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
void age()
{
	int age;
	printf("\n6) Enter age from 1 to 150: ");
	scanf("%d", &age);
	if (age >= 1 && age <= 150)
	{
		int remainder = age % 10;

		if (remainder == 1)
		{
			printf("%d god\n", age);
		}
		else if (remainder >= 2 && remainder <= 4)
		{
			printf("%d goda\n", age);
		}
		else
		{
			printf("%d let\n", age);
		}
	}
	else
	{
		printf("Error: invalid input\n");
	}
}

//7. С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).
//Требуется определить, относятся ли к поля к одному цвету или нет.
int checkColorSimilarity(int x1, int y1, int x2, int y2)
{
	return (((x1 + y1) % 2) == ((x2 + y2) % 2)) ? 1 : 0;
}

//8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
void squaresAndCubes(int a, int b)
{
	double squareRoot, cubeRoot;
	double e = 0.0000001;

	for (int i = a; i <= b; i++)
	{
		squareRoot = sqrt(i);
		cubeRoot = cbrt(i);

		if (fabs(squareRoot - roundf(squareRoot)) < e)
		{
			printf("%d ", i);
		}
		else if (fabs(cubeRoot - roundf(cubeRoot)) < e)
		{
			printf("%d ", i);
		}
	}

	printf("\n");
}

//9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания,
//найти частное от деления нацело N на K, а также остаток от этого деления.
void division(int N, int K)
{
	int counter = -1;
	while (N > 0)
	{
		N -= K;
		counter++;
	}

	int remainder = N += K;

	printf("N / K = %d\n", counter);
	printf("N %% K = %d\n", N);
}


//10. Дано целое число N > 0. С помощью операций деления нацело и взятия остатка от деления определить,
//имеются ли в записи числа N нечётные цифры. Если имеются, то вывести True, если нет – вывести False.
void checkIfHasOddDigits(int N)
{
	while (N > 0)
	{
		int digit = N % 10;
		if (digit % 2 == 1)
		{
			printf("This number has odd digit(s)\n");
			return;
		}
		N /= 10;
	}

	printf("This number doesn't have odd digit(s)\n");
}

//11. С клавиатуры вводятся числа, пока не будет введён 0.
//Подсчитать среднее арифметическое всех положительных чётных чисел, оканчивающихся на 8.
void calculateMeanNumber()
{
	printf("\n11) Enter numbers. To end enter 0\n");

	int input = 0;
	int sum = 0, counter = 0;

	do
	{
		scanf("%d", &input);
		if ((input > 0) && (input % 10 == 8))
		{
			sum += input;
			counter++;
		}
	} while (input != 0);

	if (sum != 0)
	{
		printf("Mean number is %f\n", ((float)sum / counter));
	}
	else
	{
		printf("Error: no numbers entered\n");
	}
}

//12. Написать функцию нахождения максимального из трёх чисел.
void findMaxFrom3(int a, int b, int c)
{
	int max = findMaxFrom2(a, findMaxFrom2(b, c));
	printf("\n12) Max from {%d,%d,%d} is %d\n", a, b, c, max);
}

//13. * Написать функцию, генерирующую случайное число от 1 до 100: 
//a.С использованием стандартной функции rand().
void generateRandomNumberWithRand()
{
	int number = rand() % 100 + 1;
	printf("\n13) From 1 to 100 with rand(): %d\n", number);
}
//b.Без использования стандартной функции rand().
int randInit = 0;
void generateRandomNumberWithoutRand()
{
	int x = randInit;
	int A = 7, B = 3, M = 100;
	x = (A*x + B) % M + 1;
	printf("From 1 to 100 without rand(): %d\n", x);
	randInit++;
}

//14. * Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
//Например, 25 \ :sup: '2' = 625. Напишите программу,
//которая получает на вход натуральное число N и выводит на экран все автоморфные числа, не превосходящие N.

void findAutomorphicNumbers(int N)
{
	printf("\n14) Automorphic numbers < %d:\n", N);
	for (int i = 1; i <= N; i++)
	{
		int digits = calculateDigits(i);
		int divider = 1;

		while (digits > 0)
		{
			divider *= 10;
			digits--;
		}

		if (i == (i*i % divider))
		{
			printf("%d ", i);
		}
	}
}
int calculateDigits(int number)
{
	int counter = 0;
	while (number > 0)
	{
		number /= 10;
		counter++;
	}
	return counter;
}

int main()
{
	//1
	double h = 1.72, m = 60.0;
	printf("\n1) Height: %.2lfm; mass: %.1lfkg; index: %.2lf \n", h, m, massIndex(h, m));

	//2
	int a = 5, b = -18, c = 11, d = 0;
	int n = 4;
	printf("\n2) Max from {%d,%d,%d,%d} is %d \n", a, b, c, d, findMaxFrom4(a, b, c, d));

	//3
	a = -2, b = 13;
	printf("\n3) Before swap: a = %d, b = %d\n", a, b);
	swap1(&a, &b);
	printf("After swap1: a = %d, b = %d\n", a, b);
	swap2(&a, &b);
	printf("After swap2: a = %d, b = %d\n", a, b);

	//4
	a = 3, b = 8, c = 4;
	float root1, root2;
	printf("\n4) Equation: %d*x^2 + %d*x + %d = 0\n", a, b, c);
	if (solveSquareEquation(a, b, c, &root1, &root2) > -1)
	{
		printf("Solvation: x1 = %f, x2 = %f\n", root1, root2);
	}
	else
	{
		printf("D < 0, no solvation\n");
	}

	//5
	monthToYear();

	//6
	age();

	//7
	int x1 = 5, y1 = 7;
	int x2 = 3, y2 = 6;
	if (checkColorSimilarity(x1, y1, x2, y2) == 1)
	{
		printf("\n7) (%d, %d) and (%d, %d) have similar color\n", x1, y1, x2, y2);
	}
	else
	{
		printf("\n7) (%d, %d) and (%d, %d) have different color\n", x1, y1, x2, y2);
	}

	//8
	a = 1, b = 100;
	printf("\n8) Squares and cubes from %d to %d:\n", a, b);
	squaresAndCubes(a, b);

	//9
	int N = 39, K = 6;
	printf("\n9) N = %d, K = %d\n", N, K);
	division(N, K);

	//10
	N = 3208;
	printf("\n10) N = %d\n", N);
	checkIfHasOddDigits(N);

	//11
	calculateMeanNumber();

	//12
	a = -28, b = 0, c = 3;
	findMaxFrom3(a, b, c);

	//13
	generateRandomNumberWithRand();
	generateRandomNumberWithoutRand();
	generateRandomNumberWithoutRand();
	generateRandomNumberWithoutRand();

	//14
	N = 10000;
	findAutomorphicNumbers(N);

	return 0;
}