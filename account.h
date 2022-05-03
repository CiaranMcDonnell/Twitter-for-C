#ifndef SE1TWITTERPROJ_ACCOUNT_H
#define SE1TWITTERPROJ_ACCOUNT_H
#endif // SE1TWITTERPROJ_ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct accountsNode
{
	char username[15];
	struct accountsNode *nextPtr;
} accountNode;

typedef accountNode *accountNodePtr; /* synonym for ListNode* */

// protypes
void makeAccounts(accountNodePtr *startPtr);
void printAccounts(accountNodePtr startPtr);
void deleteAccount(void);
void accountName(accountNodePtr startPtr, char *uname);