#ifndef SE1TWITTERPROJ_ACCOUNT_H
#define SE1TWITTERPROJ_ACCOUNT_H
#endif //SE1TWITTERPROJ_ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 500
#define MAX_USERNAME 15

typedef struct accountsNode {
	char username[MAX_USERNAME];
	struct followNode *followersPtr;
	struct followNode *followingPtr;
	struct accountsNode *nextPtr;
} accountNode;

typedef accountNode *accountNodePtr; /* synonym for ListNode* */


//protypes
void makeAccounts(accountNodePtr *startPtr);
void printAccounts(accountNodePtr startPtr);
void deleteAccount(void);
void accountName(accountNodePtr startPtr, char *uname);