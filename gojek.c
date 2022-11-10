#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 100

FILE *listdata;
FILE *drivers;
FILE *bookinglist;
char name[MAX];
char merek[MAX];
char motorcyle[MAX];

typedef struct{

    char firstname[MAX];
    char lastname[MAX];
    char location[MAX];

}userdata;

typedef struct{

    char name[MAX];
    char motorcycle[MAX];
    char merek[MAX];

}driverdata;

typedef struct{

    char name[MAX];
    char merek[MAX];
    char motorcyle[MAX];

}booking;

void option3(){ 
    printf("\nPlease choose one of these motorcycles : \n");
    option2();
    int option;
    printf("  ==> ");
    scanf("%d", &option);
    userdata userdata1;
    driverdata driverdata1;

    switch(option){
        case 1:
            book1();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            printf("Wrong input. Please try again.\n");
            break;
    }
}   

void option1(){
    
    userdata userdata1;
    
    listdata = fopen("List(Registered).txt", "a");

    printf("\nPlease enter your first name : \n\t==> ");
    scanf("%s", userdata1.firstname);
    printf("\nPlease enter your last name : \n\t==> ");
    scanf("%s", userdata1.lastname);
    fprintf(listdata, "Name : %s %s\n", userdata1.firstname, userdata1.lastname);
    printf("\nPlease enter your current location : \n\t==> ");
    scanf("%s", userdata1.location);
    fprintf(listdata, "Location : %s\n", userdata1.location);
    fclose(listdata);

}

void option2(){
    
    
    
    driverdata driverdata1;
    drivers = fopen("Drivers.txt" , "r");
    while(fscanf(drivers, "%s %s", driverdata1.name, driverdata1.merek, driverdata1.motorcycle) == 2){
        fscanf(drivers, "%[^\n]", driverdata1.motorcycle);
        printf("\n%s\n  Motorcycle : %s%s\n", driverdata1.name, driverdata1.merek, driverdata1.motorcycle);
    }
    
    fclose(drivers);

}

void menu(){

    int option;
    printf("  ==> ");
    scanf("%d", &option);
        switch(option){
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                printf("Exiting program.....\n");
                break;
            default:
                printf("Wrong input, please try again.\n");
                break;
        }
    
}

void stylemenu(){
    printf("|-------------------------------|\n");
    printf("|    Welcome To The Program.    |\n");
    printf("|    1. Insert Userdata         |\n");
    printf("|    2. Check Available Drivers |\n");
    printf("|    3. Book A Ride             |\n");
    printf("|    4. Exit                    |\n");
    printf("|-------------------------------|\n");
}

int book1(){
    userdata userdata1;
    bookinglist = fopen("Bookinglist.txt", "a");
    printf("You've chosen Asep as your driver.");
    fprintf(listdata, "Name : %s %s\n", userdata1.firstname, userdata1.lastname);
    fclose(bookinglist);
}

void book2(){

    
}

void book3(){


}


int main(){

stylemenu();
menu();


}