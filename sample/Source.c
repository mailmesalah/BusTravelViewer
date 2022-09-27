#include<conio.h>
#include<stdio.h>
void main(void)
{
	//Define all my inputs and outputs
	char input;
	//End of definition

	while (1)
	{
		//show menu
		showMenu();
		input = getch();

		//Selection
		switch (input)
		{

		case'a':
		case'A':
			averageselected();
			break;

		case'b':
		case'B':
			selectedhouseselectedmonth();
			break;

		case'c':
		case'C':
			averagedifference();
			break;

		case'd':
		case'D':
			quarterlytotal();
			break;

		case'e':
		case'E':
			lowestjantodec();
			break;

		case'f':
		case'F':
			differencefiveroom();
			break;

		default: printf("\nSorry, You have input a wrong key .\n");

		}
	}
}
