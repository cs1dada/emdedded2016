#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __DETAIL_PHONE_BOOK_ENTRY *pDetail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __DETAIL_PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __HASH_TABLE {
    int size;
    entry **list;
} hashtable;

entry *findName(char lastname[], hashtable *pHead);
int append(char lastName[], hashtable *e);
hashtable *HashTable_Init();
int Hash (char lastName[]);

#endif
