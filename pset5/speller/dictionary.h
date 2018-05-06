// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stdio.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define BUCKETS 27


// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
int hash(const char *word);
void initList();

//node structure
typedef struct
{
    char word[LENGTH+1];
    struct node* next;
}
node;


//linked list functions
bool insert(node *n, int hashVal);
#endif // DICTIONARY_H
