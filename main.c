#include <stdio.h>
#include <stdlib.h>
#include"functions.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int categoryCount; 
	//Product products[100];
    Category categories[100]; 
	int productCount; 
	char email[100];
	char passWord[100];
	int enterNumber; 
	int check;
	int  choice;  
	int mainChoice, productChoice, categoryChoice; 
	int smallChoice;
	saveCategoriesToFile(category,categoryCount);
	//dang nhap trc khi vao ctrinh
	system("cls");	
	logIn(&email, &passWord);
	//load file trc khi vao ctrinh 
	loadCategoriesFromFile (category, &categoryCount);
	while(mainChoice!=3){
		system("cls");
		chooseMenu(); 
	scanf("%d",&mainChoice);
	 
	switch(mainChoice){
//		case 1 ://qli sp 
//		system("cls");
//		while(productChoice!=6){
//				printMenu();
//		scanf("%d",&productChoice);
//		getchar(); 
//		switch(productChoice){
//			case 1 : 
//			system("cls");
//				displayProduct(products,productCount);
//				printf("Nhan enter de quay lai\n");
//				getchar(); 
//				break; 
//			
//			case 2 :
//				system("cls");
//				addProduct(products,&productCount);
//				printf("Nhan enter de quay lai\n");
//				getchar();
//				break; 
//				
//			case 3 :
//				system("cls");
//				displayProduct(products,productCount);
//			    editProduct(products,productCount);
//			    printf("Nhan enter de quay lai\n");
//				getchar();
//			    break; 
//				
//			case 4 :
//				system("cls");
//				displayProduct(products,productCount);
//			    deleteProduct(products,&productCount);
//			    printf("Nhan enter de quay lai \n");
//				getchar();
//			    break; 
//				
//			//case 5 :
//			  //  searchProduct(); 
//				//break;	
//			case 6 :
//				system("cls");
//				 printf("Quay lai menu chinh.\n");
//                break;
//            default:
//                printf("Vui long nhap lai.\n");
//			      
//			} 	
//	
//		
//		}
//			break; 
		
		case 2 ://qli danh muc 
		
		while(categoryChoice!=7){
			system("cls");
				categoryMenu();
			scanf("%d",&categoryChoice);
			getchar(); 
			switch(categoryChoice){
				
				case 1 :
				system("cls");
				displayCategory(categories,categoryCount);
				printf("Nhan enter de quay lai\n");
				getchar();
				
				break;
				
				case 2 :
					system("cls");
					addCategory(categories,&categoryCount);
					saveCategoriesToFile(categories,categoryCount);
					printf("Nhan enter de quay lai\n");
				getchar();
				
					break;
					
				case 3 : 
				system("cls");
				    displayCategory(categories,categoryCount);
				     editCategory(categories,&categoryCount);
				     saveCategoriesToFile(categories,categoryCount);
				     printf("Nhan enter de quay lai\n");
				getchar();
					 break; 
				case 4 :
					system("cls");
				    deleteCategory(categories,&categoryCount); 
				    saveCategoriesToFile(categories,categoryCount);
				    printf("Nhan enter de quay lai\n");
				getchar();
				
				    break;
				    
				case 5 :
					system("cls");
				    searchCategory(categories,categoryCount);
				     printf("Nhan enter de quay lai\n");
				getchar();
			
				    break;
				    
				case 6 :
				  system("cls");
				  displayCategory(categories,categoryCount);
				    sortCategory(categories,categoryCount,smallChoice);
				    break; 
				    
				case 7 :
					system("cls");
				      printf("Quay ve man hinh chinh.\n");
                break;
            default:
                printf("Vui long nhap lai.\n");
		}
			} 	
		break; 
		case 3 :
			system("cls");
			saveCategoriesToFile(categories,categoryCount);
                printf("Exit.\n");
                break;

            default:
                printf("Vui long thu lai.\n");
        }
    }
   return 0;
}
