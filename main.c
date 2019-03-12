/*
* Program: Area and volume calculator
*	
* Module: header.h
*	
* Purpose: A header file with neccessary headers, prototypes, variables and definations.
*/


/* Decleration */

#include "header.h"

/* Declarations of functions prototypes */

int areaEngine(void);
int volumeEngine(void);
int startEngine(void);
void printError(char errorString[]);

int main()
{
	/* This starts the function startEngine */
	
	startEngine();
	return 0;
}

/* A function that prints error message for user. */

void printError(char printString[])
{
	printf("Error! : %s The program will now exit...\n", printString);
}

int startEngine(void)
{
	/* Local Variable */
	
	int startChoice;
	
	/* 
	 * A macro block which cheks which OS is it and then it clears the screen of
	 * Terminal or Command Prompt
	*/
	
	#ifdef __linux__
			system("clear");
	#elif _WIN32
			system("cls");
	#else
			system("clear");
	#endif
	
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
		printError("Invalid choice!");
	}
	
	return 0;
}

int areaEngine(void)
{
	/* Local Variable */
	
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
		
		/*
		 * If the user selects wrong choice then it will give error to the user and will end
		 * the program
		*/
		
		if(shapeChoice > 6)
		{
			printError("Invalid choice!");
			exit(0);
		}
	
		/*
		 * If the user chooses shape as sphere, this part of code will be ignored since
		 * sphere has only one formula. It is done by else if statement.
		*/
		
		else if(shapeChoice != 5)
		{
			printf("What type of surface area do you want to find?\n");
			printf("1. Curved Surface Area\n");
			printf("2. Total Surface Area\n\n");
			scanf("%i", &areaChoice);
			if(areaChoice > 2)
			{
				printError("Invalid choice!");
				exit(0);
			}
		}

		/* This is the switch case for int variable shapeChoice */
		
		switch(shapeChoice)
		{
			case 1:
			{
				printf("Enter the length of the side -\n");
				scanf("%f", &side);
			
				if(areaChoice == 1)
					printf("The C.S.A of the cube is = %.02f units.\n", 4 * side);
			
				else if(areaChoice == 2)
					printf("The T.S.A of the cube is = %.02f units.\n", 6 * side);
				
				break;
			}
		
			case 2:
			{
				printf("Enter the length -\n");
				scanf("%f", &length);
				printf("Enter the breadth \n");
				scanf("%f", &breadth);
				printf("Enter the height -\n");
				scanf("%f", &height);
			
				if(areaChoice == 1)
					printf("The C.S.A of the cuboid is = %.02f units.\n", 2 * (length + breadth) * height);
				
				else if(areaChoice == 2)
					printf("The T.S.A of the cuboid is = %.02f units.\n", 2 * (length * breadth + length * height + breadth * height));
				
				break;
			}
				
			case 3:
			{
				printf("Enter the radius -\n");
				scanf("%f", &radius);
				printf("Enter the height -\n");
				scanf("%f", &height);
				
				if(areaChoice == 1)
					printf("The C.S.A of the cylinder is = %.02f units.\n", 2 * PI * radius * height);
				
				else if(areaChoice == 2)
					printf("The T.S.A of the cylinder is = %.02f units.\n", 2 * PI * radius * (radius + height));
				
				break;
			}
				
			case 4:
			{
				printf("Enter the radius -\n");
				scanf("%f", &radius);
				printf("Enter the slant height -\n");
				scanf("%f", &slantHeight);
				
				/*
				 * If the user entered radius which is greater than slant height then this part of 
				 * code will give error to the user and will end the program.
				*/
				
				if(slantHeight < radius)
				{
					printError("Radius cannot be greater than the slant height!");
					exit (0);
				}
				
				if(areaChoice == 1)
					printf("The C.S.A of the cone is = %.02f units.\n", PI * radius * slantHeight);
				
				else if(areaChoice == 2)
					printf("The T.S.A of the cone is = %.02f units.\n", PI * radius * (radius + slantHeight));
				
				break;
			}
				
			case 5:
			{
				printf("Enter the radius -\n");
				scanf("%f", &radius);
				
				printf("The area of the sphere is = %.02f units.\n", 4 * PI * SQUARE(radius));
				break;
			}
			
			case 6:
			{
				printf("Enter the radius -\n");
				scanf("%f", &radius);
				
				if(areaChoice == 1)
					printf("The C.S.A of the hemisphere is = %.02f units.\n", 2 * PI * SQUARE(radius));
				
				else if(areaChoice == 2)
					printf("The T.S.A of the hemisphere is = %.02f units.\n", 3 * PI * SQUARE(radius));
				
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
	/* This is the switch case for int variable shapeChoice */

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
					scanf("%f", &side);
					
					printf("The volume of the cube is = %.02f units.\n", CUBE(side));
					break;
				}

			case 2:
				{
					printf("Enter the length -\n");
					scanf("%f", &length);
					printf("Enter the breadth -\n");
					scanf("%f", &breadth);
					printf("Enter the height -\n");
					scanf("%f", &height);
					
					printf("The volume of the cuboid is = %.02f units.\n", length * breadth * height);
					break;
				}
				
			case 3:
				{
					printf("Enter the radius -\n");
					scanf("%f", &radius);
					printf("Enter the height -\n");
					scanf("%f", &height);
					
					printf("The volume of the cylinder is = %.02f units.\n", PI * SQUARE(radius) * height);
					break;
				}
			
			case 4:
				{
					printf("Enter the radius -\n");
					scanf("%f", &radius);
					printf("Enter the height -\n");
					scanf("%f", &height);
					
					printf("The volume of the cone is = %.02f units.\n", 1/3 * PI * SQUARE(radius) * height);
					break;
				}
				
			case 5:
				{
					printf("Enter the radius -\n");
					scanf("%f", &radius);
					
					printf("The volume of the sphere is = %.02f units.\n", 4/3 * PI * CUBE(radius));
					break;
				}
				
			case 6:
				{
					printf("Enter the radius -\n");
					scanf("%f", &radius);
					
					printf("The volume of the hemisphere is = %.02f units.\n", 2/3 * PI * CUBE(radius));
					break;
				}
			
			/*
			 * If the user selects wrong choice then it will give error to the user and will end
			 * the program
			*/	
			
			default:
				{
					printError("Invalid choice!");
					exit (0);
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

