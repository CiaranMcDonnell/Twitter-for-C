#include "account.h"

void makeAccounts(AccountsNodePtr *sPtr, AccountsNodePtr *ePtr, char username[15]){
    AccountsNodePtr startPtr = NULL;
    AccountsNodePtr endPtr = NULL;
    AccountsNodePtr newPtr = malloc(sizeof(AccountsNode));
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
}

void deleteAccount(void){

}