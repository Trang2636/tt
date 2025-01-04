#include"datatypes.h" 
 
//nguyen mau ham 
void logIn(char email, char passWord); 
void categoryName();  
void printMenu();
//void showProduct();
bool checkLogIn(char *email, char *passWord); 
//void editProduct(Product product[],int number);
//void addProduct(Product product[],int *number); 
//void deleteProduct(Category category[], int *categoryCount);
void addCategory(Category category[],int *categoryCount); 
void categoryMenu();
void searchCategory(Category category[], int categoryCount); 
void sortCategory(Category category[], int categoryCount, int smallChoice);

bool validateCategory(Category category[], int categoryCount, int id, const char *name) ;
bool validateAllCategories(Category category[], int categoryCount);
void loadCategoriesFromFile();
void saveCategoriesToFile( Category category[],int categoryCount);
void displayCategory();
