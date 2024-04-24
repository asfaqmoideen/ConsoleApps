#include <stdio.h>
#include <string.h>


void diplayMainMenu();
int getOptionFromTheUser();
int executeMainMenu(int);
void addProduct();
void displayProducts();
void getProductDetails();

struct Product
{
    int productId;
    char productName[100];
    float productPrice;
};

struct Product products [2];
int productId = 0;

int main (){

    int exitFlaq = 0;

    while (!exitFlaq)
    {
      diplayMainMenu();
      int option = getOptionFromTheUser();
      exitFlaq = executeMainMenu(option);
    }

    printf("\n Exiting the application...");
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
    scanf("\n%d", &option);
    return option;
}

int executeMainMenu(int option){
    switch (option)
    {
    case 1:
        displayProducts();
    case 2:
        addProduct();
        break;
    case 0:
        return 1;
    default:
        break;
    }
    return 0;
}

void addProduct(){
    productId ++;
    char productName[100];
    float productPrice;
    
    printf("Enter Product Name : ");
    scanf("%s", productName);
    
    printf("Enter Product Price for %s: ", productName);
    scanf("%f", &productPrice);
    
    products[productId].productId = productId;
    strcpy( products[productId].productName, productName);
    products[productId].productPrice = productPrice;

    printf("The Product %s with Price %.2f has been successfully Added with ID : %d\n", productName, productPrice, productId);
}

void displayProducts(){

    if(products == NULL){
        printf("No Products were added yet");
        return;
    }

    for(int i = 1; i<sizeof(products); i++){
        printf("\n Product Id :%d",products[i].productId);
        printf("\n Product Name : %s",products[i].productName );
        printf("\n Product Price : %.2f", products[i].productPrice);
    }

}