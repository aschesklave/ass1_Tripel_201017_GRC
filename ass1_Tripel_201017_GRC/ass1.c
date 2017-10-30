#include <stdio.h>
#include <limits.h>
#include <float.h>
#define TRUE 1

void sortTriplets(float triangle_triplets[UCHAR_MAX][3], int triangle_quantity)
{
	int array_changed = 0;

	for (int i = 0; i < triangle_quantity; i++)
	{
		do //bubblesort
		{
			array_changed = 0;
			for (int sort_pos = 0; sort_pos < 2; sort_pos++)
			{
				if (triangle_triplets[i][sort_pos] > triangle_triplets[i][sort_pos + 1])
				{
					int tmp = triangle_triplets[i][sort_pos];//swap elements
					triangle_triplets[i][sort_pos] = triangle_triplets[i][sort_pos + 1];
					triangle_triplets[i][sort_pos + 1] = tmp;

					array_changed++;
				}
			}
		} while (array_changed != 0);
	}
}

void checkTriangle(float triangle_triplets[UCHAR_MAX][3], int triangle_quantity)
{
  int a, b, c;
  for (int count = 0; count < triangle_quantity; count++)
  {
    a = triangle_triplets[count][0];
    b = triangle_triplets[count][1];
    c = triangle_triplets[count][2];
    if (a + b > c)
    {
      printf("Triplet %d (a=%d, b=%d, c=%d) is a triangle.\n", count + 1, a, b, c);
    }
    else
    {
      printf("Triplet %d (a=%d, b=%d, c=%d) is NO triangle.\n", count + 1, a, b, c);
    }

    if (a == b && b == c && a == c)
    {
      printf("  It is an equilateral triangle.\n");
    }
    else if(a == b)
    {
      printf("  It is an isosceles triangle.\n");
    }
    else if((a * a) + (b * b) == (c * c))
    {
      printf("  It is a right triangle.\n");
    }
  }
}


int main(void)
{
	int  triangle_quantity = 0;
	float triangle_triplets[UCHAR_MAX][3];
	int cnt = 0;

	while(TRUE)
	{
		printf("Please enter the number of triangles to check: ");
		cnt = scanf("%d", &triangle_quantity);

		if (cnt != 1 || triangle_quantity < 1 || triangle_quantity > UCHAR_MAX)
		{
			printf("[ERR] Invalid number of triangles.\n");
			continue;
		}
		break;
	}

	for (int i = 0; i < triangle_quantity * 3; i++)
	{
			switch (i % 3)
			{
				case 0: printf("Please enter the first number of the triplet: ");
					break;
				case 1: printf("Please enter the second number of the triplet: ");
					break;
				case 2: printf("Please enter the third number of the triplet: ");
					break;
				default: printf("[ERR] Undefined Error.\n");
					return 1;
			}

			cnt = scanf("%f", &triangle_triplets[i / 3][i % 3]);

			if (cnt != 1 || triangle_triplets[i / 3][i % 3] < 0 || triangle_triplets[i / 3][i % 3] > FLT_MAX)
			{
				printf("[ERR] Invalid number for the triplet.\n");
				i--;
				continue;
			}
	}
	return 0;
}