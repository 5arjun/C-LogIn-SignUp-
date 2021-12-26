#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20
#define LIST_LENGTH 50
typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

} uLogIn;

typedef struct{
    uLogIn array[LIST_LENGTH];
    int count;
    int length;
} uLogInList;

int getLogCount(char filename[]);
uLogInList create_loginlist();
void readLogIns(uLogInList *ll, char filename[]);
void compare_login( uLogInList ll);
void create_login(char filename[], char username[], char password[]);


int main(){
    char logFilename[20] = "logincount.txt";

    uLogInList ll = create_loginlist(); //list of SAVED logins in system
    char loginFilename[10]= "logins.csv"; 
    //ALL logins in system are read into the program
    readLogIns(&ll, loginFilename);
    
    printf("Select One:\n(1)Log-In\n(2)Sign-Up\n->");
    int choice;
    scanf("%d", &choice);
    if (choice == 2){
        char newusername[20];
        char newpassword[20];
        printf("Create a username: ");
        scanf("%s", newusername);
        printf("Create a password: ");
        scanf("%s", newpassword);
        create_login(loginFilename, newusername, newpassword);
    }
    if(choice == 1){
        compare_login(ll);
    }
    return 0;
}

uLogInList create_loginlist(){//creates a user list
    uLogInList ll;
    ll.length = LIST_LENGTH;
    ll.count = 0;
    return ll;
}
int getLogCount(char filename[]){ //gets the number of total logins in the system
    FILE *file = fopen(filename, "r"); //opens logincount file
    if (file == NULL){ 
        perror("Logs file failed to open");
        exit(888);
    }
    char buffer[5];
    int logCount;  //variable that will have the number of logs in the system
    while(fgets(buffer,5,file) != NULL){
        logCount = atoi(buffer); //converts to a number and assigns to logCount
    }
    fclose(file);
    return logCount;
}

void readLogIns(uLogInList *ll, char filename[]){
    FILE *file = fopen(filename, "r"); //opens file with all logins
    if (file == NULL){
        perror("File failed to open");
        exit(999);
    }
    char buffer[30];
    int recs = 0;
    while(fgets(buffer,30,file)){
        strcpy(ll->array[recs].username, strtok(buffer, ","));//inserts saved logins from reading file
        strcpy(ll->array[recs].password, strtok(NULL, ","));
        recs++;
        ll->count += 1;
    }
    fclose(file);

}

void compare_login( uLogInList ll){
    int loop = 0;
    do{
        printf("Enter username: ");//gets input for username
        char username[20];
        scanf("%s", username);
        printf("Enter password: ");//gets input for password
        char password[20];
        scanf("%s", password);

        for(int i = 0; i < ll.count; i++){
            int uValue = strcmp(username, ll.array[i].username);//compares entered user to ones in the logs
            int pValue = strcmp(password, ll.array[i].password);
            if (uValue == 0 && pValue == 0) {//if strcmp() returns both 0's
                printf("ACCESS GRANTED");
                loop = 1;//loop = 1 breaks the do while loop
            }
            else{
                loop = 0;//continues the do while loop
            }
        } 
        if(loop == 0) 
            printf("Incorrect username or password\n");//prints this if incorrect login and doesn't exit loop
    }while (loop == 0);
}
void create_login(char filename[], char username[], char password[]){
    FILE *file = fopen(filename, "a");
    if (file == NULL){
        perror("File(L) failed to open");
        exit(777);
    }
    fprintf(file, "\n%s,%s,", username, password);
    fclose(file);
}