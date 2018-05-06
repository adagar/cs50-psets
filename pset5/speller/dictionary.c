// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"


//create a global array to link to lists
node* list;//[BUCKETS];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //create a lower case version of the word
    //TODO move this out to a function
    int length = strlen(word);
    char *lowerWord = (char*)malloc(length + 1);
    for(int i = 0; i < length; i++)
    {
        lowerWord[i] = tolower(word[i]);
    }

    printf("Checking to see if %s is correctly spelled...\n", lowerWord);
    if (lowerWord == NULL)
    {
        return false;
    }
    else
    {
        //look in list[hash(lowerWord)] to see if this lowerWord is in there
        //create a node cursor to scan list, should start pointing to same pointer the head does
        node *cursor = &list[hash(lowerWord)];
        printf("Scanning %s...\n", cursor->word);
        while (true)
        {
            if(cursor->word == lowerWord)
            {
                return true;
            }
            else
            {
                if (strcmp(cursor->word, "\0"))
                {
                    return false;
                }
            }
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    printf("Loading dictionary...\n");

    // open input file
    FILE *dictFile = fopen(dictionary, "r");
    if (dictFile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return 2;
    }

    //create a word char star
    char word[LENGTH + 1];

    initList();

    //scan dictionary, word by word
    printf("Begining Loading loop...\n");
    while(fscanf(dictFile, "%s", word) != EOF)
    {
        printf("Loading word %s...\n", word);


        //malloc a new node for each word
        node *new_node = malloc(sizeof(node));

        // confirm new node is valid
        if(new_node == NULL)
        {
            unload();
            return false;
        }

        //copy word to the new node
        strcpy(new_node->word, word);

        //hash new word
        int hashVal = hash(word);

        //outsource the insertion to a separate function
        insert(new_node, hashVal);
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}


//hash function
int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

//hash table functions
bool insert(node *n, int hashVal)
{
    //link to whatever hash list currently pointing to
    //this will protect/maintain current link
    n->next = list[hashVal].next;

    //now that link is preserved, we can link list to this node
    list[hashVal] = *n;

    return true;
}

void initList()
{
    //allocate memory to list buckets
    list = malloc(sizeof(node) * BUCKETS);
    for(int i = 0; i < BUCKETS; i++)
    {
        strcpy(list[i].word, "\0");
        list[i].next = NULL;
    }
}