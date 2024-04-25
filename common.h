#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <stdbool.h>


// Foods
typedef struct {
    int id;
    char name[50];
    float fee;
} Food;

// TakenOrder
typedef struct {
    Food f;
    int quantity;
    char tableId[250];
    bool isConfirmed;
    bool isActive;
} TakenOrder;

// Ortak fonksiyonlar�n imzalar�
void displayMenu();
void displayOrderList(char tableId[]);
void writeToLogFile(char text[]);

#endif // COMMON_H_INCLUDED
