#include<stdio.h>
#include<string.h> 
#include"functions.h" 
#include<stdbool.h> 

//logic ham chon danh muc hay hang hoa 
void chooseMenu(){
	printf("\n***Management System Using C***\n");
	printf("   [1].Quan li san pham\n");
	printf("   [2].Quan li danh muc\n");
	printf("Lua chon cua ban: ");	 
} 

//logic ham menu daanh muc 
void categoryMenu(){
    printf("\n***Store Management System Using C***\n");
	printf("\n======He Thong Quan Li Danh Muc======\n");
	printf("     [1].Hien thi toan bo danh muc.\n");
	printf("     [2].Them 1 danh muc moi.\n");
	printf("     [3].Sua 1 danh muc.\n");
	printf("     [4].Xoa 1 danh muc.\n");
	printf("     [5].Tim kiem 1 danh muc.\n");
	printf("     [6].Sap xep 1 danh muc.\n");
	printf("     [7].Thoat.\n");
	printf("    =========================\n");
	printf("     Lua chon cua ban: "); 
}
//logic ham dang nhap 
void logIn(char *email, char *passWord){ 
 do{
 	 printf("\n***Store Management System Using C***\n");
	printf("            LOGIN\n");
	printf("Email : ");
	fgets(email, 100 , stdin);
    email[strcspn(email,"\n")]='\0';
	printf("Password : ");
	fgets(passWord, 100 , stdin);
    passWord[strcspn(passWord,"\n")]='\0';
 }while(!checkLogIn(email,passWord)); 
} 

//logic ham kiem tra tk mk
bool checkLogIn(char *email, char *passWord){
	//tai khoan mat khau k thay doi 
	const char EMAILCORRECT[]="bigboss";
	const char PASSCORRECT[]="g63";
	//so sanh gia tri ng dung nhap vao voi tai khoan co dinh 
	if(strcmp(email,EMAILCORRECT)==0 && strcmp(passWord,PASSCORRECT)==0){
		printf("\nCorrect. Welcome To Store Management System Using C\n"); 
		return true; 
	}else{
			printf("\n            !! ERROR !!\n"); 
		return false; 
	} 	 
}
 
 //logic ham in menu sp 
void printMenu(){
	printf("\n***Store Management System Using C***\n");
	printf("\n======Product Management System======\n");
	printf("     [1].Show all products.\n");
	printf("     [2].Add a new product.\n");
	printf("     [3].Edit a product.\n");
	printf("     [4].Delete a product.\n");
	printf("     [5].Search a product.\n");
	printf("     [6].Exit.\n");
	printf("    =========================\n");
	printf("     Enter the choice: "); 
} 

//logic ham hien thi toan bo sp 
void displayProduct(Product product[],int productCount){
	if(productCount==0){
		printf("EMPTY");
	}else{
		printf("\n***PRODUCTS***\n");
    printf("-----------------------------------------------------------\n");
    printf("Category ID   | ID  | Name           | Price     |  Quanity\n");
    printf("---------------------------------------\n");
     int i; 
    for (i = 0; i <productCount; i++) {
    printf("|%d           | %d  | %s           | %.3f      | %d      |\n",product[i].categoryId, product[i].productId, product[i].name,product[i].price,product[i].quanity);
}

    printf("----------------------------------------------------------\n");
    }
} 
 
 
 //ham them san pham  
void addProduct(Product product[],int *productCount){
	product[*productCount].productId=*productCount+1; 
	printf("Ten san pham : ");
	fgets(product[*productCount].name,100,stdin);
	product[*productCount].name[strcspn(product[*productCount].name,"\n")]='\0';
	printf("Gia cua san pham : ");
	scanf("%.2f",&product[*productCount].price);
	getchar(); 
	(*productCount)++;
	printf("\nDone!\n"); 
} 

//ham sua san pham
void editProduct(Product product[], int productCount){
	int position;
	printf("Vi tri muon sua :");
	scanf("%d", &position);
	int findIndex=-1;
	int i; 
	for(i=0;i<productCount;i++){
		if(product[i].productId==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Not  found");
	}else{
		getchar();
		printf("Ten san pham muon sua : ");
		fgets(product[findIndex].name, 100, stdin);
		product[findIndex].name[strcspn(product[findIndex].name, "\n")] = '\0';
		printf("Gia cua san pham : ");
		scanf("%d", &product[findIndex].price);
		getchar();
		printf("\nDONE.\n");
		 
	}
}

//ham xoa san pham 
void deleteProduct(Product product[], int *productCount){
	int position;
	printf("Vi tri muon xoa :");
	scanf("%d", &position);
	int findIndex=-1;
	int i; 
	for(i=0;i<*productCount;i++){
		if(product[i].productId==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Not found");
	return ;
	}else{
		printf("Confirm deletion?\n");
	
		for(i=findIndex;i<*productCount;i++){
			product[i]=product[i+1];
		}
		(*productCount)--;
	}
}


void deleteCategory(Category category[], int *categoryCount){
	int position;
	printf("Vi tri muon xoa :");
	scanf("%d", &position);
	int findIndex=-1;
	int i; 
	for(i=0;i<*categoryCount;i++){
		if(category[i].id==position){
			findIndex =i;
			break;
		}
	} 
	if(findIndex==-1){
		printf("Not found");
	}else{
		for(i=findIndex;i<*categoryCount;i++){
			category[i]=category[i+1];
		}
		(*categoryCount)--;
	}
}

void displayCategory(Category category[],int categoryCount){
		printf("\n***CATEGORIES***\n");
    printf("----------------------\n");
    printf("| ID  | Name         |\n");
    printf("----------------------\n");
     int i; 
    for (i = 0; i <categoryCount; i++) {
        printf("| %-3d | %-12s |\n", category[i].id, category[i].name); 
               
}

    printf("----------------------\n");
    
} 

void searchCategory(Category category[], int categoryCount){
	char keyword[50];
	int found=0;
	fflush(stdin);
	printf("nhap tu khoa de tim kiem danh muc; ");
	fgets(keyword,50,stdin);
	keyword[strcspn(keyword,"\n")]='\0';
	printf("ket qua tim kiem: \n");
	printf("|___|______________________|\n");
	int i;
	for(i=0;i<categoryCount;i++){

		if(strstr(category[i].name,keyword)!=NULL){
			printf("| %d | %s\n", category[i].id, category[i].name);
            printf("|___|______________________|\n");
            found = 1;
		}
	}
	if (!found) {
        printf("Khong tim thay danh muc nao phu hop voi tu khoa '%s'.\n", keyword);
    }
}

void sortCategory(Category category[],int categoryCount,int smallChoice){
	while(smallChoice!=3){
	printf("[1].Tang dan\n");
	printf("[2].Giam dan\n");
	printf("[3].Thoat\n");
	printf("Moi ban nhap vao lua chon: ");
	scanf("%d",&smallChoice);
	switch(smallChoice){		
		int i,j;
    case 1:
    	system("cls");
			for (i = 0; i < categoryCount - 1; i++) {
        		for (j = 0; j <categoryCount - i - 1; j++) {
            		if (strcmp(category[j].name, category[j+1].name) > 0){
            			int count;
                		char temp[100];
                		strcpy(temp, category[j].name);
                		strcpy(category[j].name, category[j+1].name);
                		strcpy(category[j + 1].name, temp);
                		
                		count=category[j].id;
              			category[j].id=category[j+1].id;
              			category[j+1].id=count;
            		}
        		}
    		}
    		displayCategory( category, categoryCount);
    		
		    break;
     	case 2:
           system("cls");
			for ( i = 0; i < categoryCount - 1; i++) {
        		for (j = 0; j < categoryCount - i - 1; j++) {
            		if (strcmp(category[j].name, category[j+1].name) < 0) {
                		char temp[100];
                		strcpy(temp, category[j].name);
                		strcpy(category[j].name, category[j+1].name);
                		strcpy(category[j + 1].name, temp);
            		}
        		}
    		}
    		displayCategory(category, categoryCount);
    		break;
    		
    	case 3 :
    		system("cls");
    		printf("Nhan enter de quay lai ");
    		getchar();
			break; 
    	}
    }
}

bool validateCategory(Category category[], int categoryCount, int id, const char *name) {
	int i; 
    for (i = 0; i < categoryCount; i++) {
        if (category[i].id == id) {
            printf("ID da ton tai. Vui long nhap lai.\n");
            return false;
        }
    }
   
    for (i = 0; i < categoryCount; i++) {
        if (strcmp(category[i].name, name) == 0) {
            printf("Ten danh muc da ton tai. Vui long nhap lai.\n");
            return false;
        }
    }

    
    if (strlen(name) == 0 || strspn(name, " \t") == strlen(name)) {
        printf("Ten danh muc khong duoc de trong. Vui long nhap lai.\n");
        return false;
    }

    return true; 
}

void addCategory(Category category[], int *categoryCount) {
    int id;
    char name[100];

    do {
        printf("Nhap ID danh muc: ");
        scanf("%d", &id);
        getchar(); 
        if (id <= 0) {
            printf("ID phai la so duong. Vui long nhap lai.\n");
        }
    } while (id <= 0);

    do {
        printf("Nhap ten danh muc: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';  
        if (!validateCategory(category, *categoryCount, id, name)) {
            printf("Du lieu khong hop le. Vui long nhap lai.\n");
        }
    } while (!validateCategory(category, *categoryCount, id, name));

    
    category[*categoryCount].id = id;
    strcpy(category[*categoryCount].name, name);
    (*categoryCount)++;
    printf("Them danh muc thanh cong!\n");
}

void editCategory(Category category[], int *categoryCount) {
    int id;
    char newName[100];

    printf("Nhap ID danh muc can chinh sua: ");
    scanf("%d", &id);
    getchar();

   
    int found = -1;
    int i; 
    for (i = 0; i < *categoryCount; i++) {
        if (category[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay danh muc co ID: %d\n", id);
        return;
    }

   
    do {
        printf("Nhap ten moi cho danh muc: ");
        fgets(newName, sizeof(newName), stdin);
        newName[strcspn(newName, "\n")] = '\0'; 

        if (!validateCategory(category, *categoryCount, id, newName)) {
            printf("Du lieu khong hop le. Chinh sua danh muc that bai.\n");
        }
    } while (!validateCategory(category, *categoryCount, id, newName));

    
    strcpy(category[found].name, newName);
    printf("Chinh sua danh muc thanh cong!\n");
}

bool validateAllCategories(Category category[], int categoryCount) {
	int i; 
    for (i = 0; i < categoryCount; i++) {
        if (!validateCategory(category, categoryCount, category[i].id, category[i].name)) {
            printf("Danh muc voi ID %d hoac ten '%s' khong hop le.\n", category[i].id, category[i].name);
            return false;
        }
    }
    return true;
}


  
 void saveCategoriesToFile( Category category[],int categoryCount){
		FILE *file = fopen("category.dat", "wb");
	if(file==NULL){
		printf("Khong mo duoc file");
	}
	fwrite(category,sizeof(Category),categoryCount,file);
	printf("Luu thong tin thanh cong");
	fclose(file);
}

void loadCategoriesFromFile(Category category[], int *categoryCount) {
	 FILE *file = fopen("category.dat", "ab");
	if(file==NULL){
		printf("Khong mo duoc file");
	}
	Category readCategory[100];
	*categoryCount=fread(readCategory,sizeof(Category),100,file);
	int i; 
	for(i=0;i<*categoryCount;i++){
		printf("---ID---Name------------");
		printf("| %d     | %s           |",readCategory[i].id,readCategory[i].name);
		printf("|-----------------------|"); 
	}
	printf("Lay Du Lieu Thanh Cong\n");
	fclose(file);
}

