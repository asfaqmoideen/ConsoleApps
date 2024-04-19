#include <stdio.h>
#include <string.h>

void diplayMainMenu();
int getOptionFromTheUser();
int executeMainMenu(int);
void addProduct();
void getProductDetails();

struct product
{
    int productId;
    char productName[100];
    float productPrice;
};


int main (){

    int exitFlaq = 0;

    while (!exitFlaq)
    {
      diplayMainMenu();
      int option = getOptionFromTheUser();
      exitFlaq = executeMainMenu(option);
    }

    return 0;
}


void diplayMainMenu(){
    printf("\n 1. View all products");
    printf("\n 2. Add a products");
    printf("\n 3. Remove a product");
    printf("\n 4. Update a products");
    printf("\n 1. Generate product log");
    printf("\n 0. Quit");
    printf("\n Enter a option to proceed : ");
}

int getOptionFromTheUser(){
    int option;
    scanf("%d ", &option);
    return option;
}

int executeMainMenu(int option){
    switch (option)
    {
    case 2:
        addProduct();
        break;
    case 0:
        return 0;
    default:
        break;
    }
}

void addProduct(){
    printf("\n Will code later");
}