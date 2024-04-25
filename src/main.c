#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products

struct Product {
    int productId;
    char productName[100];
    float productPrice;
};

struct Product *products = NULL; // Pointer to dynamically allocated array
int productId = 0;

void displayMainMenu();
int getOptionFromTheUser();
int executeMainMenu(int);
void addProduct();
void displayProducts();
void removeProduct();
void updateProduct();
int findProduct(char[100]);

int main() {
    int exitFlag = 0;

    while (!exitFlag) {
        displayMainMenu();
        int option = getOptionFromTheUser();
        exitFlag = executeMainMenu(option);
    }

    printf("\nExiting the application...");
    free(products); // Free dynamically allocated memory
    return 0;
}

void displayMainMenu() {
    printf("\n1. View all products");
    printf("\n2. Add a product");
    printf("\n3. Remove Product");
    printf("\n4. Update Product");
    printf("\n0. Quit");
    printf("\nEnter an option to proceed: ");
}

int getOptionFromTheUser() {
    int option;
    scanf("%d", &option);
    return option;
}

int executeMainMenu(int option) {
    switch (option) {
        case 1:
            displayProducts();
            break;
        case 2:
            addProduct();
            break;
        case 3: 
            removeProduct();
            break;
        case 4: 
            updateProduct();
            break;
        case 0:
            return 1;
        default:
            printf("\nInvalid option. Please try again.");
            break;
    }
    return 0;
}

void addProduct() {
    productId++;
    char productName[100];
    float productPrice;
    
    printf("Enter Product Name: ");
    scanf("%s", productName);
    
    printf("Enter Product Price for %s: ", productName);
    scanf("%f", &productPrice);
    
    if (products == NULL) {
        products = (struct Product *)malloc(MAX_PRODUCTS * sizeof(struct Product));
        if (products == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
    } else if (productId >= MAX_PRODUCTS) {
        printf("Maximum number of products reached\n");
        return;
    }

    products[productId - 1].productId = productId;
    strcpy(products[productId - 1].productName, productName);
    products[productId - 1].productPrice = productPrice;

    printf("The Product %s with Price %.2f has been successfully Added with ID: %d\n", productName, productPrice, productId);
}

void displayProducts() {
    if (products == NULL || productId == 0) {
        printf("No products were added yet\n");
        return;
    }

    printf("\nProducts:\n");
    for (int i = 0; i < productId; i++) {
        printf("\nProduct ID: %d", products[i].productId);
        printf("\nProduct Name: %s", products[i].productName);
        printf("\nProduct Price: %.2f\n", products[i].productPrice);
    }
}

void removeProduct() {
    char productName[100];
    printf("Enter Product Name to remove: ");
    scanf("%s", productName);
    int pos = findProduct(productName);

    if (pos == -1) {
        printf("Product not found.\n");
        return;
    }

    // Shift elements to the left to remove the product
    for (int i = pos; i < productId - 1; i++) {
        products[i] = products[i + 1];
    }

    // Decrement productId since one product is removed
   // productId--;

    printf("Product '%s' removed successfully.\n", productName);
}


int findProduct(char productName[100]){
    for(int i =0; i< productId; i++){
        if(!strcmp(products[i].productName, productName)){
            return i;
        }
    }

    printf("Product not Found");
    return -1;
}

void updateProduct() {
    char productName[100];
    printf("Enter Product Name to update: ");
    scanf("%s", productName);
    int pos = findProduct(productName);

    if (pos == -1) {
        printf("Product not found.\n");
        return;
    }

    float productPrice;
    printf("Enter new price for %s: ", productName);
    scanf("%f", &productPrice);

    products[pos].productPrice = productPrice;

    printf("Product '%s' updated successfully.\n", productName);
}
