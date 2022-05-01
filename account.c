#include "account.h"

void makeAccounts(AccountsNodePtr *sPtr, AccountsNodePtr *ePtr, char username[15]){
    AccountsNodePtr startPtr = NULL;
    AccountsNodePtr endPtr = NULL;
    AccountsNodePtr newPtr = malloc(sizeof(AccountsNode));
    char cont='n';
    while (cont=='n' || cont == 'N'){
        if (newPtr != NULL) {
            *newPtr->username = username;
            newPtr->nextPtr = NULL;
            AccountsNodePtr previousPtr = *ePtr;
            if (*sPtr==NULL){
                *sPtr = newPtr;
            }
            if (previousPtr!=NULL){
                previousPtr->nextPtr = newPtr;
            }
            *ePtr = newPtr;
        }
        else {
            printf("%s not inserted. No memory available.\n", username[15]);
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

void deleteAccount(void){

}