#include "account.h"

void makeAccounts(accountNodePtr *startPtr){
    /*
    Takes in username inputs from end users and uses them to create a linked list of 
    It creates a linked list of accounts
    */
    accountNodePtr endPtr = NULL;
    accountNodePtr newPtr;
    char cont='y', uname[MAX_USERNAME];
    while (cont=='y' || cont == 'Y'){
        newPtr = (accountNode*)malloc(sizeof(accountNode));
        if (newPtr != NULL) {
            accountName(*startPtr, uname);
            strcpy(newPtr->username, uname);
            newPtr->nextPtr = NULL;
            newPtr->followersPtr = NULL;
            newPtr->followingPtr = NULL;
            accountNode *previousPtr = endPtr;
            if (*startPtr==NULL){
                *startPtr = newPtr;
            }
            if (previousPtr!=NULL){
                previousPtr->nextPtr = newPtr;
            }
            endPtr = newPtr;
        }
        else {
            printf("No memory available.\n");
        }
        printf("\nWould you like to make another account? y/n: ");
        fflush(stdin);
        scanf("%c", &cont);
        while (cont != 'n' && cont != 'N' && cont != 'y' && cont != 'Y'){
            fflush(stdin);
            printf("Invalid input\nPlease try again\n\nWould you like to make another account? y/n: ");
            scanf("%c", &cont);
        }
    }
}

void accountName(accountNodePtr startPtr, char *uname){
    /*
    It asks the user to input a username, checks that it's valid, and then copies it to the variable
    passed to it.
    */
    accountNodePtr testPtr;
    char attempt[16];
    int len, dq = 1;
    while (dq!=0){
        testPtr = startPtr;
        dq=0;
        printf("\n(Usernames are limited to 15 characters and only letters, numbers and underscores are permitted)\n");
        printf("Enter: ");
        fflush(stdin);
        scanf("%[^\n]", &attempt);
        len = strlen(attempt);
        if(len>15){
            printf("Your input included more than 15 characters\nPlease try again\n");
            dq++;
        }
        if (dq!= 1){
            for (int i=0; i<len;i++){
                if (((attempt[i] > 'Z' || attempt[i]<'A') &&  (attempt[i]>'z' || attempt[i]<'a') &&  (attempt[i]>'9' || attempt[i]<'0')) && attempt[i]!='_'){
                    dq++;
                    printf("Your input contains illegal characters\nPlease try again\n");
                    break;
                }
            }
        }
        while (testPtr!=NULL && dq!=1) {
            if(!strcmp(testPtr->username, attempt)){
                dq++;
                printf("Sorry, this username already exists\nPlease try again\n");
            }
            testPtr = testPtr->nextPtr;
        }    
    }
    strcpy(uname,attempt);
}