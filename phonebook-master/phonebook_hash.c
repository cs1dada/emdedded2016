#include <stdlib.h>
#include <stdio.h>

#include "phonebook_hash.h"

#define HashTableSize 100

entry *findName(char lastname[], hashtable *pHead)
{
    int index = Hash(lastname);
    //printf("findname: lastname=%s index=%d\n", lastname, index);

    entry *slot = pHead -> list[index];

    while (slot != NULL) {
        if (strcasecmp(lastname, slot->lastName ) == 0) {
            //printf("match\n");
            return slot;
        }
        slot = slot->pNext;
    }

    printf("lastname not exist \n");
    return NULL;
}

/*
*
*char lastName[] : element
*hashtable *e : container to put element
*/
int append(char lastName[], hashtable *e)
{
    int index = 0;

    entry  *NewEntry;
    NewEntry = (entry *)malloc(sizeof(entry));
    strcpy(NewEntry -> lastName, lastName);

    /* pick slot in hashtable */
    index = Hash(lastName);

    /* insert NewEntry to hashtable*/
    NewEntry->pNext = e->list[index];
    e->list[index] = NewEntry;

    return 0;
}

/*
*
*   hashtable [HashTableSize]
*    __________________________________________________________
*  | list[0] | list[1] | list[2] | ..... | list[HashTableSize -1] |
*   ----------------------------------------------------------------------
*/
hashtable *HashTable_Init()
{
//printf("HashTable_Init\n");
    hashtable * ht = NULL;
    int i = 0;

//printf("allocate memory\n");
    ht = (hashtable *)malloc(sizeof(hashtable));
    ht -> list = (entry **)malloc(sizeof(entry *) * HashTableSize);
    ht -> size = HashTableSize;

//printf("init to zero\n");
    for (i =0; i < HashTableSize; i++) {
        //memset(ht -> list[i], '\0', sizeof(entry) );
        ht -> list[i] = NULL;
    }

    //printf("init ok!!! \n");
    return ht;
}

int Hash (char lastName[])
{
    int value =0;
    int i = 0;

    while (lastName[i] != '\0') {
        //printf("value=%d, name=%c \n", lastName[i], lastName[i]);
        value += lastName[i];
        i ++;
    }
    if (strcasecmp(lastName, "zyxel" ) == 0) {
        //printf("Hash lastName =%s value=%d\n", lastName,value);
    }

#if 0
    if (strcasecmp(lastName, "zyxel" ) == 0) {
        value = i = 0;

        while (lastName[i] != '\0') {
            printf("value=%d, name=%c \n", lastName[i], lastName[i]);
            value += lastName[i];
            i ++;
        }
        printf("Hash lastName =%s value=%d\n", lastName,value);
    }
#endif

    return value % HashTableSize;
}
