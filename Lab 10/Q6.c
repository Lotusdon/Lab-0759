#include <stdio.h>

struct Package{
	char name[30];
	char destination[40];
	int duration;
	int cost;
	int seats_available;
};

int main(){
	struct Package arr[5] = {{"Umrah Regular","Saudi Arabia",15,525000,50},{"Umrah Premium","Saudi Arabia",22,850000,35},{"Turkish Amazement","Turkey",12,980000,20},{"Breezey Summer","Maldives",10,1050000,25},{"Freezy Winters","Canada",14,790000,15}};
	int s, i;
	printf("Available Packages: \n\n");
	for(i=0;i<5;i++){
		printf("Package Number %d:\n", i + 1);
		printf("Name: %s\n", arr[i].name);
		printf("Destination: %s\n", arr[i].destination);
		printf("Duration: %d days\n", arr[i].duration);
		printf("Price: PKR %d\n", arr[i].cost);
		printf("Seats Available: %d\n\n", arr[i].seats_available);
	}
	printf("Enter Package Number you want to select: ");
	scanf("%d", &s);
	printf("You have selected %s. Enjoy your trip to %s", arr[s - 1].name, arr[s - 1].destination);
}
