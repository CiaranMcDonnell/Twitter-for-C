#ifndef SE1TWITTERPROJ_FEED_H
#define SE1TWITTERPROJ_FEED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

// Structure definitions
typedef struct tweetsNode {
 	char username[MAX_USERNAME];
    char tweet[280];
 	struct tweetsNode *nextPtr;
    int id;
} tweetNode;

typedef tweetNode *tweetsNodePtr;

// Prototypes
int postTweet(tweetsNodePtr *startPtr, accountNodePtr curAcPtr);
int getNewsFeed(tweetsNodePtr startPtr, accountNodePtr curAcPtr);
void printNewsFeed(int y, tweetsNodePtr startPtr);
void divLine(int len);

#endif /* !SE1TWITTERPROJ_FEED_H */