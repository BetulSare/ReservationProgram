#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdbool.h>
#include "common.h"
char *foodsTxt = "Foods.txt";
char *ordersTxt = "Orders.txt";
char *closedOrdersTxt = "ClosedOrders.txt";
char *takenOrdersTxt = "TakenOrders.txt";
char *logTtxt = "log.txt";
int numberOfFoods = 4;

void writeToLogFile(char text[])
{
	FILE *file = fopen(logTtxt,"a+");
	fprintf(file,"%s",text);
	fclose(file);
}





//Kaan Hacýkerimli
void displayMenu(){
FILE *file=fopen(foodsTxt,"rb");
Food food;
fread(&food,sizeof(food),1,file);
while(!feof(file)){

    printf("Food name: %s \n",food.name);
    printf("Food id: %d \n",food.id);
    printf("Food fee: %f \n\n",food.fee);

fread(&food,sizeof(food),1,file);
}
fclose(file);

        char text[200];
        sprintf(text,"Menu displayed..\n");
        writeToLogFile(text);
}




//Fatma Betül Sare
void displayOrderList(char tableId[]) {
    DIR *dir;
    struct dirent *ent;
    char cwd[100];

    if ((dir = opendir(tableId)) != NULL) {
        getcwd(cwd, sizeof(cwd));
        strcat(cwd, "//");
        strcat(cwd, tableId);
        strcat(cwd, "//Orders.txt");

        FILE *file = fopen(cwd, "rb+");
        if (file != NULL) {
            TakenOrder current;
            fread(&current, sizeof(TakenOrder), 1, file);

            printf("-------------- %s Table's Orders --------------\n", tableId);

            while (!feof(file)) {
                printf("Table ID: %s\n", current.tableId);
                printf("Food ID: %d\n", current.f.id);
                printf("Food name: %s\n", current.f.name);
                printf("Food number : %d\n", current.quantity);
                printf("Fee: %2.3f\n",current.f.fee);
                printf("Order is active? : %s\n", current.isActive ? "Yes" : "No");
                printf("Order is confirmed? : %s\n", current.isConfirmed ? "Yes" : "No");

                fread(&current, sizeof(TakenOrder), 1, file);
            }
            fclose(file);
        } else {
            printf("Failed to open Orders.txt file!\n");
        }
        closedir(dir);
    } else {
        printf("There is no table with the given name!!!\n");
    }
}
