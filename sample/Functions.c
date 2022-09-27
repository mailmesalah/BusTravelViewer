#include<stdio.h>
#include<conio.h>

//Definition
extern float oneroom[];
extern float tworoom[];
extern float threeroom[];
extern float fourroom[];
extern float fiveroom[];
//End

void showMenu(void)
{
	printf("Please input your selection .\n");
	printf("A : Display the average water consumption for a selected household across 12 months .\n");
	printf("B : Display the water consumption a selected household and month .\n");
	printf("C : Display the difference between average water consumption\n    and water consumption of each household for a selected month .\n");
	printf("D : Display the quarterly total of a selected household .\n");
	printf("E : Display the lowest water consumption from Jan to Dec .\n");
	printf("F : Display the difference in water consumption of HDB 5-Room in each consecutive month .\n");
}

void averageselected(void)
{
	int j;
	float total, average;
	char selection;
	total = 0;

	printf("\n");
	do
	{
		printf("Please select household \n");
		printf("1)1Room 2)2Room 3)Room\n");
		printf("4)4Room 5)5Room\n");
		selection = getch();
	} while (selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5');

	if (selection == '1')
	{
		for (j = 0; j < 12; j++)
		{
			total = total + oneroom[j];
		}
	}
	if (selection == '2')
	{
		for (j = 0; j < 12; j++)
		{
			total = total + tworoom[j];
		}
	}
	if (selection == '3')
	{
		for (j = 0; j < 12; j++)
		{
			total = total + threeroom[j];
		}
	}
	if (selection == '4')
	{
		for (j = 0; j < 12; j++)
		{
			total = total + fourroom[j];
		}
	}
	if (selection == '5')
	{
		for (j = 0; j < 12; j++)
		{
			total = total + fiveroom[j];
		}
	}
	average = total / j;

	printf("The average water consumption for the selected household type is %.2f .\n", average);
	printf("\n");
}
void selectedhouseselectedmonth(void)
{
	int j, month;
	float value;
	char selection;

	printf("\n");
	do
	{
		printf("Please select household \n");
		printf("1)1Room 2)2Room 3)Room\n");
		printf("4)4Room 5)5Room\n");
		selection = getch();
	} while (selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5');

	printf("\n");
	do
	{
		printf("Please select month \n");
		printf("1)Jan 2)Feb 3)Mar\n");
		printf("4)Apr 5)May 6)Jun\n");
		printf("7)Jul 8)Aug 9)Sep\n");
		printf("10)Oct 11)Nov 12)Dec\n");
		scanf("%d", &month);
	} while (month < 1 || month > 12);
	month--;

	if (selection == '1')value = oneroom[month];
	if (selection == '2')value = tworoom[month];
	if (selection == '3')value = threeroom[month];
	if (selection == '4')value = fourroom[month];
	if (selection == '5')value = fiveroom[month];

	printf("The water consumption for the selected household and month is %.2f .\n", value);
	printf("\n");
}
void averagedifference(void)
{
	int month, j;
	float total, average, difference;

	printf("\n");
	do
	{
		printf("Please select month \n");
		printf("1)Jan 2)Feb 3)Mar\n");
		printf("4)Apr 5)May 6)Jun\n");
		printf("7)Jul 8)Aug 9)Sep\n");
		printf("10)Oct 11)Nov 12)Dec\n");
		scanf("%d", &month);
	} while (month < 1 || month > 12);
	month--;

	total = oneroom[month] + tworoom[month] + threeroom[month] + fourroom[month] + fiveroom[month];
	average = total / 5;

	difference = oneroom[month] - average;
	if (difference < 0)difference = average - oneroom[month];
	printf("The difference between one room and average is %.2f .\n", difference);
	difference = tworoom[month] - average;
	if (difference < 0)difference = average - tworoom[month];
	printf("The difference between two room and average is %.2f .\n", difference);
	difference = threeroom[month] - average;
	if (difference < 0)difference = average - threeroom[month];
	printf("The difference between three room and average is %.2f .\n", difference);
	difference = fourroom[month] - average;
	if (difference < 0)difference = average - fourroom[month];
	printf("The difference between four room and average is %.2f .\n", difference);
	difference = fiveroom[month] - average;
	if (difference < 0)difference = average - fiveroom[month];
	printf("The difference between five room and average is %.2f .\n", difference);
	printf("\n");
}
void quarterlytotal(void)
{
	char selection;
	int j;
	float total[4];


	printf("\n");
	do
	{
		printf("Please select household \n");
		printf("1)1Room 2)2Room 3)Room\n");
		printf("4)4Room 5)5Room\n");
		selection = getch();
	} while (selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5');

	if (selection == '1')
	{
		total[0] = oneroom[0] + oneroom[1] + oneroom[2];
		total[1] = oneroom[3] + oneroom[4] + oneroom[5];
		total[2] = oneroom[6] + oneroom[7] + oneroom[8];
		total[3] = oneroom[9] + oneroom[10] + oneroom[11];

		for (j = 0; j < 4; j++)
		{
			if (j == 0)printf("Total for Jan - Mar is %.2f .\n", total[j]);
			if (j == 1)printf("Total for Apr - Jun is %.2f .\n", total[j]);
			if (j == 2)printf("Total for Jun - Sep is %.2f .\n", total[j]);
			if (j == 3)printf("Total for Oct - Dec is %.2f .\n", total[j]);
		}
	}
	if (selection == '2')
	{
		total[0] = tworoom[0] + tworoom[1] + tworoom[2];
		total[1] = tworoom[3] + tworoom[4] + tworoom[5];
		total[2] = tworoom[6] + tworoom[7] + tworoom[8];
		total[3] = tworoom[9] + tworoom[10] + tworoom[11];

		for (j = 0; j < 4; j++)
		{
			if (j == 0)printf("Total for Jan - Mar is %.2f .\n", total[j]);
			if (j == 1)printf("Total for Apr - Jun is %.2f .\n", total[j]);
			if (j == 2)printf("Total for Jun - Sep is %.2f .\n", total[j]);
			if (j == 3)printf("Total for Oct - Dec is %.2f .\n", total[j]);
		}
	}
	if (selection == '3')
	{
		total[0] = threeroom[0] + threeroom[1] + threeroom[2];
		total[1] = threeroom[3] + threeroom[4] + threeroom[5];
		total[2] = threeroom[6] + threeroom[7] + threeroom[8];
		total[3] = threeroom[9] + threeroom[10] + threeroom[11];

		for (j = 0; j < 4; j++)
		{
			if (j == 0)printf("Total for Jan - Mar is %.2f .\n", total[j]);
			if (j == 1)printf("Total for Apr - Jun is %.2f .\n", total[j]);
			if (j == 2)printf("Total for Jun - Sep is %.2f .\n", total[j]);
			if (j == 3)printf("Total for Oct - Dec is %.2f .\n", total[j]);
		}
	}
	if (selection == '4')
	{
		total[0] = fourroom[0] + fourroom[1] + fourroom[2];
		total[1] = fourroom[3] + fourroom[4] + fourroom[5];
		total[2] = fourroom[6] + fourroom[7] + fourroom[8];
		total[3] = fourroom[9] + fourroom[10] + fourroom[11];

		for (j = 0; j < 4; j++)
		{
			if (j == 0)printf("Total for Jan - Mar is %.2f .\n", total[j]);
			if (j == 1)printf("Total for Apr - Jun is %.2f .\n", total[j]);
			if (j == 2)printf("Total for Jun - Sep is %.2f .\n", total[j]);
			if (j == 3)printf("Total for Oct - Dec is %.2f .\n", total[j]);
		}
	}
	if (selection == '5')
	{
		total[0] = fiveroom[0] + fiveroom[1] + fiveroom[2];
		total[1] = fiveroom[3] + fiveroom[4] + fiveroom[5];
		total[2] = fiveroom[6] + fiveroom[7] + fiveroom[8];
		total[3] = fiveroom[9] + fiveroom[10] + fiveroom[11];

		for (j = 0; j < 4; j++)
		{
			if (j == 0)printf("Total for Jan - Mar is %.2f .\n", total[j]);
			if (j == 1)printf("Total for Apr - Jun is %.2f .\n", total[j]);
			if (j == 2)printf("Total for Jun - Sep is %.2f .\n", total[j]);
			if (j == 3)printf("Total for Oct - Dec is %.2f .\n", total[j]);
		}
	}
	printf("\n");
}
void lowestjantodec(void)
{
	int j;
	float lowest = 10000;

	printf("\n");
	for (j = 0; j < 12; j++)
	{
		if (oneroom[j] < lowest)lowest = oneroom[j];
		if (tworoom[j] < lowest)lowest = tworoom[j];
		if (threeroom[j] < lowest)lowest = threeroom[j];
		if (fourroom[j] < lowest)lowest = fourroom[j];
		if (fiveroom[j] < lowest)lowest = fiveroom[j];
	}

	for (j = 0; j < 12; j++)
	{
		if (oneroom[j] == lowest)printf("The lowest is %.2f and it comes from one room at the %d month .\n", lowest, j + 1);
		if (tworoom[j] == lowest)printf("The lowest is %.2f and it comes from two room at the %d month .\n", lowest, j + 1);
		if (threeroom[j] == lowest)printf("The lowest is %.2f and it comes from three room at the %d month .\n", lowest, j + 1);
		if (fourroom[j] == lowest)printf("The lowest is %.2f and it comes from four room at the %d month .\n", lowest, j + 1);
		if (fiveroom[j] == lowest)printf("The lowest is %.2f and it comes from five room at the %d month .\n", lowest, j + 1);
	}
	printf("\n");
}
void differencefiveroom(void)
{
	int j;
	float difference[11], highest;
	highest = 0;

	printf("\n");
	for (j = 0; j < 11; j++)
	{
		difference[j] = fiveroom[j + 1] - fiveroom[j];
		if (difference[j] < 0)difference[j] = fiveroom[j] - fiveroom[j + 1];
	}

	for (j = 0; j < 11; j++)
	{
		if (j == 0)printf("The difference between Jan - Feb is %.2f .\n", difference[j]);
		if (j == 1)printf("The difference between Feb - Mar is %.2f .\n", difference[j]);
		if (j == 2)printf("The difference between Mar - Apr is %.2f .\n", difference[j]);
		if (j == 3)printf("The difference between Apr - May is %.2f .\n", difference[j]);
		if (j == 4)printf("The difference between May - Jun is %.2f .\n", difference[j]);
		if (j == 5)printf("The difference between Jun - Jul is %.2f .\n", difference[j]);
		if (j == 6)printf("The difference between Jul - Aug is %.2f .\n", difference[j]);
		if (j == 7)printf("The difference between Aug - Sep is %.2f .\n", difference[j]);
		if (j == 8)printf("The difference between Sep - Oct is %.2f .\n", difference[j]);
		if (j == 9)printf("The difference between Oct - Nov is %.2f .\n", difference[j]);
		if (j == 10)printf("The difference between Nov - Dec is %.2f .\n", difference[j]);
	}

	printf("\n");

	for (j = 0; j < 11; j++)
	{
		if (difference[j] > highest)highest = difference[j];
	}

	for (j = 0; j < 11; j++)
	{
		if (difference[j] == highest)
		{
			if (j == 0)printf("The highest difference is between Jan - Feb .\n");
			if (j == 1)printf("The highest difference is between Feb - Mar .\n");
			if (j == 2)printf("The highest difference is between Mar - Apr .\n");
			if (j == 3)printf("The highest difference is between Apr - May .\n");
			if (j == 4)printf("The highest difference is between May - Jun .\n");
			if (j == 5)printf("The highest difference is between Jun - Jul .\n");
			if (j == 6)printf("The highest difference is between Jul - Aug .\n");
			if (j == 7)printf("The highest difference is between Aug - Sep .\n");
			if (j == 8)printf("The highest difference is between Sep - Oct .\n");
			if (j == 9)printf("The highest difference is between Oct - Nov .\n");
			if (j == 10)printf("The highest difference is between Nov - Dec .\n");
		}
	}
	printf("\n");
}
