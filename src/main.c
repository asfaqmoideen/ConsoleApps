#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products

struct Product* head = NULL;
struct Product {
    int productId;
    char productName[100];
    float productPrice;
    struct Product *next;
};

//struct Product *products = NULL; // Pointer to dynamically allocated array
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
   // free(products); // Free dynamically allocated memory
    return 0;
}

void displayMainMenu() {
    printf(" --- Welcome to Product Inventory Manager");
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

    struct Product *temp;   
    temp = (struct Product*)malloc(sizeof(struct Product));
    printf("Enter Product Name: ");
    scanf("%s", &temp->productName);
    printf("Enter Product Price for %s: ", temp->productName);
    scanf("%f", &temp->productPrice);
    temp->productId = productId;

        temp->next = NULL;
    	if(head==NULL)	{
		head = temp;
	}
	else{
		struct Product* ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
    printf("The Product %s with Price %.2f has been successfully Added with ID: %d\n", temp->productName, temp->productPrice, temp->productId);
}

void displayProducts() {
    if (head == NULL) {
        printf("No products were added yet\n");
    }

    else{
    printf("\nProducts:\n");
    struct Product *ptr;
    ptr = head;
    do{
        printf("\nProduct ID: %d",ptr->productId );
        printf("\nProduct Name: %s", ptr->productName);
        printf("\nProduct Price: %.2f\n", ptr->productPrice);
        ptr =ptr->next;
    }while(ptr->next != NULL);
    }
}

void removeProduct() {
    char productName[100];
    printf("Enter Product Name to remove: ");
    scanf("%s", productName);
    int pos = findProduct(productName);
    struct Product *ptr = head;

    if (pos == -1) {
        printf("Product not found.\n");
        return;
    }
    else if(pos == 0){
        ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else {
        struct Product *prv_ptr; 
        for (int i = 0; i < pos; i++) {
            prv_ptr = ptr;
            ptr = ptr->next;
         }
         prv_ptr->next = ptr->next;
         free(ptr);
    }

    printf("Product '%s' removed successfully.\n", productName);
}


int findProduct(char productName[100]){

    struct Product *ptr = head;
    if(head == NULL){
        printf("\n No Products were added Yet");
        return 0;
    }

    for(int i =0; ptr->next !=NULL; i++){
        if(!strcmp(ptr->productName, productName)){
            return i;
        }
    }

    printf("Product not Found");
    return -1;
}

void updateProduct() {

    struct Product* ptr = head;
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

    if(pos == 0){
        scanf("%f", ptr->productPrice);
    }
    else{
        for (int i = 0; i == pos; i++) {
            scanf("%f", ptr->productPrice);
         }
    }

    printf("Product '%s' updated successfully.\n", productName);
}
