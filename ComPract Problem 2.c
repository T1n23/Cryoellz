#include <stdio.h>

typedef struct{
	int dayNumber;
	char location[50];
	float temperature;
	float humidity;
}Weather;

void fileSaver( Weather info[], int count){
	FILE *fptr = fopen("weather_data.txt", "w");
	
	if(fptr == NULL){
		printf("Error opening file...");
		return;
	}
	
	
	for(int i = 0 ; i < count; i++){
		
		fprintf(fptr," %d", &info[i].dayNumber);
		
		fprintf(fptr," %s\n", info[i].location);
		
		fprintf(fptr," %.2f°C\n", info[i].temperature);
		
		fprintf(fptr, "Humidity: %.2f%\n", info[i].humidity);
	}
	
	fclose(fptr);
	
	printf("Weather records saved successfully to weather_data.txt");	
}

void fileReader( Weather info[], int count){
	FILE *fptr = fopen("weather_data.txt", "r");
	
	if(fptr == NULL){
		printf("Error opening file...");
		return;
	}
	
	for(int i = 0 ; i < count; i++){
		
		fscanf(fptr," %d", &info[i].dayNumber);
		
		fscanf(fptr," %s\n", info[i].location);
		
		fscanf(fptr," %.2f°C\n", info[i].temperature);
		
		fscanf(fptr, "Humidity: %.2f%\n", info[i].humidity);
	}
	
	fclose(fptr);
}

void addNewrecord(Weather info[], int *count){
	*count += 1;
	int i = *count - 1;
	
	printf("=====ADD NEW RECORD=====\n");
	printf("Enter day number: ");
	scanf("%d", &info[i ].dayNumber);
		
	printf("Enter location: ");
	scanf("%s", info[i].location);
		
	printf("Enter temperature(°C): ");
	scanf("%f", &info[i].temperature);
		
	printf("Enter humidity(%): ");
	scanf("%f", &info[i].humidity);
	
}

void updateRecord( Weather info[], int count){
	int day = 0;
	
	printf("Enter day number to update: ");
	scanf("%d", &day);
	
	for(int i = 0 ; i < count; i++){
		if( day == info[i].dayNumber){
			printf("\nEnter new location: ");
			scanf("%s", info[i].location);
		
			printf("Enter new temperature(°C): ");
			scanf("%f", &info[i].temperature);
		
			printf("Enter new humidity(%): ");
			scanf("%f", &info[i].humidity);
		}	
	}
}



void displayRecord( Weather info[], int count){
	printf("\n=====WEATHER RECORDS=====\n");
	for(int i = 0 ; i < count; i++){
		
		printf("Day %d\n", &info[i].dayNumber);
		
		printf("Location %s\n", info[i].location);
		
		printf("Temperature: %.2f°C\n", info[i].temperature);
		
		printf("Humidity: %.2f%\n", info[i].humidity);
	}
}

int main(){
	int count = 0;
	Weather info[100];
	
	printf("Enter how many weather records will be entered: ");
	scanf("%d", &count);
	
	for(int i = 0 ; i < count; i++){
		printf("\nEnter details for Weather Record %d\n", i + 1);
		
		printf("\nEnter day number: ");
		scanf("%d", &info[i].dayNumber);
		
		printf("Enter location: ");
		scanf("%s", info[i].location);
		
		printf("Enter temperature(°C): ");
		scanf("%f", &info[i].temperature);
		
		printf("Enter humidity(%): ");
		scanf("%f", &info[i].humidity);
	}
	
	fileSaver(info, count);
	displayRecord(info, count);
	
	printf("=====WEATHER DATA ANALYZER=====\n\n");
	printf("1. Display All Weather Records\n");
	printf("2. Add New Weather Record\n");
	printf("3. Update Weather Record by Day Number\n");
	printf("4. Save Weather Records to File\n");
	printf("5. Read Weather Records from File\n");
	printf("6. Exit\n");
	
	int choice = 0;
	do{
		printf("Enter Choice: ");
		scanf("%d", &choice);
		
		if(choice == 1){
			displayRecord(info, count);
		}else if(choice == 2){
			addNewrecord(info, &count);
		}else if(choice == 3){
			updateRecord(info, &count);
		}else if(choice == 4){
			fileSaver(info, count);
		}else if(choice == 5){
			fileReader( info, count);
		}else{
			printf("Exiting...");
			break;
		}
	}while( choice == 0 && choice >= 7);
	
	return 0;
}