#include <stdio.h>
#include <stdlib.h>


int * ChangeFloor(int start, int final, int floors[])
{
	
	int difference = final - start;
	int i = start;
	
	//decrease if change in floors is negative
	if (difference < 0) 
	{
		for(int i = start; i > final; i--) 
		{
			printf("%d, ", floors[i-2]);
		}	
	}
	//increase if change in floors is positive
	else
	{
		for(int i = start; i < final; i++)
		{
			printf("%d, ", floors[i]);
		}
	}
	printf("Ding!\n");

	//allocate memory to return the new floor value
	
	int * newFloor = (int*)calloc(1, sizeof(int));
	* newFloor = final;
	
	return newFloor;
	
	//free memory
	free(newFloor);
}

int main() 
{
	int floors[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	char again = 'y';
	int currentFloor = floors[0];
	
	do 
	{
		int chosenFloor = 1;
		
		printf("You are currently on floor %d. The top floor is 15.\n", currentFloor);
		printf("Which floor would you like to go to? ");
		
		scanf("%d", &chosenFloor);

		//incorrect floor chosen
		if(chosenFloor > 15 || chosenFloor < 0) 
		{
			printf("That is not a valid floor! Choose between 1-15.\n");
		}

		//same floor chosen
		else if(chosenFloor == currentFloor) 
		{
			printf("You're already on that floor!\n");;
		}
		
		//proper floor chosen
		else
		{
			int * updatedFloor =  ChangeFloor(currentFloor, chosenFloor, floors);
			currentFloor = * updatedFloor;
		}

		
		printf("Would you like to change floors? Enter y if yes or any other key if not.\n");

		scanf("%s", &again);

		printf("\n");

	} while(again == 'y');

	return 0;

}
