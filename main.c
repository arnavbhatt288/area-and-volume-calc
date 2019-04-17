/*
* Program: Area and volume calculator
*	
* Module: header.h
*	
* Purpose: A header file with neccessary headers, prototypes, variables and definations.
*/


/* Decleration */

#include "header.h"

/* Global Variables */

double radius;
double length;
double breadth;
double height;
double side;
double slantHeight;
int shapeChoice;
int continuation;

/* A function that prints error message for user. */

void printError(char printString[])
{
	printf("Error! : %s", printString);
}

int startEngine(void)
{
	int startChoice;
	
	/* A piece of code which clears the screen. */
	
	printf("\e[1;1H\e[2J");

	/* A welcome string. */
	
	printf("+-------------------------------------+\n");
	printf("|                                     |\n");
	printf("|Welcome to Area and Volume Calculator|\n");
	printf("|                                     |\n");
	printf("+-------------------------------------+\n");
	printf("What do you want to calculate?\n");
	printf("1. Surface Area\n");
	printf("2. Volume\n\n");
	scanf("%i", &startChoice);
	
	/*
	 * If the user select choices correctly, then the user will proceed to the function
	 * they required. Otherwise they will get error message and the program will get
	 * terminated.
	*/

	if(startChoice == 1)
	{
		areaEngine();
	}
	else if(startChoice == 2)
	{
		volumeEngine();
	}
	else
	{
		printError("Invalid choice! The program will now exit...\n");
		exit (0);
	}
	
	return 0;
}

int areaEngine(void)
{
	int areaChoice;

	do
	{
		printf("Choose the shape -\n");
		printf("1. Cube\n");
		printf("2. Cuboid\n");
		printf("3. Cylinder\n");
		printf("4. Cone\n");
		printf("5. Sphere\n");
		printf("6. Hemisphere\n\n");
		scanf("%i", &shapeChoice);
		
		if(shapeChoice > 6)
		{
			printError("Invalid choice! Please try again -\n\n");
			continue;
		}
	
		/*
		 * If the user chooses shape as sphere, this part of code will be ignored since
		 * sphere has only one formula.
		*/
		
		else if(shapeChoice != 5)
		{
			printf("What type of surface area do you want to find?\n");
			printf("1. Curved Surface Area\n");
			printf("2. Total Surface Area\n\n");
			scanf("%i", &areaChoice);
			if(areaChoice > 2)
			{
				printError("Invalid choice! Please try again -\n\n");
				continue;
			}
		}

		/* This is the switch case for int variable shapeChoice */
		
		switch(shapeChoice)
		{
			case 1:
			{
				printf("Enter the length of the side -\n");
				scanf("%lf", &side);
			
				if(areaChoice == 1)
					printf("The C.S.A of the cube is = %.02lf units.\n", 4 * side);
			
				else if(areaChoice == 2)
					printf("The T.S.A of the cube is = %.02lf units.\n", 6 * side);
				
				break;
			}
		
			case 2:
			{
				printf("Enter the length -\n");
				scanf("%lf", &length);
				printf("Enter the breadth \n");
				scanf("%lf", &breadth);
				printf("Enter the height -\n");
				scanf("%lf", &height);
			
				if(areaChoice == 1)
					printf("The C.S.A of the cuboid is = %.02lf units.\n", 2 * (length + breadth) * height);
				
				else if(areaChoice == 2)
					printf("The T.S.A of the cuboid is = %.02lf units.\n", 2 * (length * breadth + length * height + breadth * height));
				
				break;
			}
				
			case 3:
			{
				printf("Enter the radius -\n");
				scanf("%lf", &radius);
				printf("Enter the height -\n");
				scanf("%lf", &height);
				
				if(areaChoice == 1)
					printf("The C.S.A of the cylinder is = %.02lf units.\n", 2 * PI * radius * height);
				
				else if(areaChoice == 2)
					printf("The T.S.A of the cylinder is = %.02lf units.\n", 2 * PI * radius * (radius + height));
				
				break;
			}
				
			case 4:
			{
				printf("Enter the radius -\n");
				scanf("%lf", &radius);
				printf("Enter the slant height -\n");
				scanf("%lf", &slantHeight);
				
				if(slantHeight < radius)
				{
					printError("Radius cannot be greater than the slant height! Please try again\n\n");
					continue;
				}
				
				if(areaChoice == 1)
					printf("The C.S.A of the cone is = %.02lf units.\n", PI * radius * slantHeight);
				
				else if(areaChoice == 2)
					printf("The T.S.A of the cone is = %.02lf units.\n", PI * radius * (radius + slantHeight));
				
				break;
			}
				
			case 5:
			{
				printf("Enter the radius -\n");
				scanf("%lf", &radius);
				
				printf("The area of the sphere is = %.02lf units.\n", 4 * PI * SQUARE(radius));
				break;
			}
			
			case 6:
			{
				printf("Enter the radius -\n");
				scanf("%lf", &radius);
				
				if(areaChoice == 1)
					printf("The C.S.A of the hemisphere is = %.02lf units.\n", 2 * PI * SQUARE(radius));
				
				else if(areaChoice == 2)
					printf("The T.S.A of the hemisphere is = %.02lf units.\n", 3 * PI * SQUARE(radius));
				
				break;
			}
		}
		
		/* A string which asks user to whether continue or not */
		
		printf("Do you want to continue?\n");
		printf("1. Yes\n");
		printf("2. No\n\n");
		scanf("%i", &continuation);
	}
	
	while(continuation != 2);
	return 0;
}

int volumeEngine(void)
{
	do
	{
		printf("Choose the shape -\n");
		printf("1. Cube\n");
		printf("2. Cuboid\n");
		printf("3. Cylinder\n");
		printf("4. Cone\n");
		printf("5. Sphere\n");
		printf("6. Hemisphere\n\n");
		scanf("%i", &shapeChoice);

		switch(shapeChoice)
		{
			case 1:
				{
					printf("Enter the length of the side -\n");
					scanf("%lf", &side);
					
					printf("The volume of the cube is = %.02lf units.\n", CUBE(side));
					break;
				}

			case 2:
				{
					printf("Enter the length -\n");
					scanf("%lf", &length);
					printf("Enter the breadth -\n");
					scanf("%lf", &breadth);
					printf("Enter the height -\n");
					scanf("%lf", &height);
					
					printf("The volume of the cuboid is = %.02lf units.\n", length * breadth * height);
					break;
				}
				
			case 3:
				{
					printf("Enter the radius -\n");
					scanf("%lf", &radius);
					printf("Enter the height -\n");
					scanf("%lf", &height);
					
					printf("The volume of the cylinder is = %.02lf units.\n", PI * SQUARE(radius) * height);
					break;
				}
			
			case 4:
				{
					printf("Enter the radius -\n");
					scanf("%lf", &radius);
					printf("Enter the height -\n");
					scanf("%lf", &height);

				printf("The volume of the cone is = %.02lf units.\n", PI * SQUARE(radius) * height / 3);
					break;
				}
				
			case 5:
				{
					printf("Enter the radius -\n");
					scanf("%lf", &radius);
					
					printf("The volume of the sphere is = %.02lf units.\n", 4/3 * PI * CUBE(radius));
					break;
				}
				
			case 6:
				{
					printf("Enter the radius -\n");
					scanf("%lf", &radius);
					
					printf("The volume of the hemisphere is = %.02lf units.\n", 2/3 * PI * CUBE(radius));
					break;
				}

			default:
				{
					printError("Invalid choice! Please try again -\n\n");
					continue;
				}
		}
		
		/* A string which asks user to whether continue or not */
		
		printf("Do you want to continue?\n");
		printf("1. Yes\n");
		printf("2. No\n\n");
		scanf("%i", &continuation);
	}
	
	while (continuation != 2);
	return 0;
}

int main()
{
	/* This calls the function startEngine */
	
	startEngine();
	return 0;
}
