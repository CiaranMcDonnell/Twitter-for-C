#ifndef SE1TWITTERPROJ_ACCOUNT_H
#define SE1TWITTERPROJ_ACCOUNT_H

//necessary library inclusions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME 15

//structure definitions
typedef struct followsNode {
	char username[MAX_USERNAME];
	struct followsNode *nextPtr;
} followNode;

typedef struct accountsNode {
	char username[MAX_USERNAME];
	struct followsNode *followersPtr;
	struct followsNode *followingPtr;
	struct accountsNode *nextPtr;
} accountNode;

typedef followNode *followNodePtr;
typedef accountNode *accountNodePtr;

//protypes
void makeAccounts(accountNodePtr *startPtr);
void accountName(accountNodePtr startPtr, char *uname);

#endif /* !SE1TWITTERPROJ_ACCOUNT_H */