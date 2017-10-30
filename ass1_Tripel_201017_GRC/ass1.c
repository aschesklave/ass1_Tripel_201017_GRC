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
					float tmp = triangle_triplets[i][sort_pos];//swap elements
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
			continue;
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
	char input_str[80];
	int  triangle_quantity = 0;
	float triangle_triplets[UCHAR_MAX][3];
	int input_error = 0;
	int point_cnt = 0;

	while(TRUE)
	{
		input_error = 0;
		printf("Please enter the number of triangles to check: ");
		gets(input_str);
		
		for (int i = 0;; i++)
		{
			if (input_str[i] == '\0')
			{
				break;
			}
			if (input_str[i] >= 48 && input_str[i] <= 57)
			{
				triangle_quantity = triangle_quantity * 10 + input_str[i] - 48;
				continue;
			}
			else
			{
				input_error = 1;
				break;
			}
		}

		if (input_error != 0 || triangle_quantity < 1 || triangle_quantity > UCHAR_MAX)
		{
			printf("[ERR] Invalid number of triangles.\n");
			continue;
		}
		//printf("Anzahl: %d", triangle_quantity);
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

		while (TRUE)
		{
			triangle_triplets[i / 3][i % 3] = 0;
			input_error = 0;
			gets(input_str);

			for (int j = 0;; j++)
			{
				if (input_str[j] == '\0')
					break;
				if (input_str[j] == '.')
					if (point_cnt <= 1)
					{
						input_error = 1;
						break;
					}
					else
						point_cnt++;

				if (input_str[j] < 48 || input_str[j] > 58)
				{
					input_error = 1;
					break;
				}
			}
			sscanf(input_str, "%f", &triangle_triplets[i / 3][i % 3]);

			if (input_error != 0 || triangle_quantity < 1 || triangle_quantity > UCHAR_MAX)
			{
				printf("[ERR] Invalid number for the triplet.\n");
				i--;
			}
			break;
		}
	}

	return 0;
}