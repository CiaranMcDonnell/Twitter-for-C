#ifndef SE1TWITTERPROJ_ACCOUNT_H
#define SE1TWITTERPROJ_ACCOUNT_H
#endif //SE1TWITTERPROJ_ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>

struct accountsNode {
    char username[15]; /* each listNode contains a character */
    struct accountsNode *nextPtr; /* pointer to next node */
};

typedef struct accountsNode AccountsNode; /* synonym for struct listNode */
typedef AccountsNode *AccountsNodePtr; /* synonym for ListNode* */

//protypes
void makeAccounts(void);
void deleteAccount(void);