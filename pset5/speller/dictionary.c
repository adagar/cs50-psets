// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"


//create a global array to link to lists
node_t* list;//[BUCKETS];

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

    //printf("Checking to see if %s is correctly spelled...\n", lowerWord);
    if (lowerWord == NULL)
    {
        return false;
    }
    else
    {
        //look in list[hash(lowerWord)] to see if this lowerWord is in there
        //create a node cursor to scan list, should start pointing to same pointer the head does
        node_t * cursor = &list[hash(lowerWord)];
        while (cursor != NULL)//strncmp(cursor->word, "\0", length) != 0)
        {
            if(strncmp(cursor->word, lowerWord, length) == 0)
            {
                //printf("%s is correctly spelled!\n", word);
                return true;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    //printf("%s is NOT correctly spelled!\n", word);
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //printf("Loading dictionary...\n");

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
    //printf("Begining Loading loop...\n");
    while(fscanf(dictFile, "%s", word) != EOF)
    {
        //printf("Loading word %s...\n", word);


        //malloc a new node for each word
        node_t *new_node = malloc(sizeof(node_t));

        // confirm new node is valid
        if(new_node == NULL)
        {
            unload();
            return false;
        }

        //outsource the insertion to a separate function
        insert(word);
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
    for (int i = 0; i < BUCKETS; i++)
    {
        //printf("Sending the %c bucket for erasure...\n", i+'a');
        node_t* head = &list[i];
        erase(head);
    }

    free(list);
    return true;
}


//hash function
int hash(const char *word)
{
    if(strcmp(&word[0], "\'"))
    {
        return 27;
    }
    return tolower(word[0]) - 'a';
}

//hash table functions
bool insert(char* word)
{
    //get hash val
    int hashVal = hash(word);
    //get head val
    node_t* head = &list[hashVal];

    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    //allocate mem for new node
    //make sure we're not out of memory
    //populate and insert node at beginning
        //link to whatever hash list currently pointing to
        //this will protect/maintain current link

    // if(head->next==NULL)
    // {
    //     printf("I'm unititiated head");
    // }

    new_node->next = head->next;

    //copy word to the new node
    strcpy(new_node->word, word);

    //now that link is preserved, we can link list to this node
    head->next = new_node;

    return true;
}

void initList()
{
    //allocate memory to list buckets
    list = (node_t*)malloc(sizeof(node_t) * BUCKETS);
    for(int i = 0; i < BUCKETS; i++)
    {
        node_t head = list[i];
        strcpy(head.word, "\0");
        head.next = NULL;
    }
}

void erase(node_t* n)
{
    if (n->next == NULL)
    {
        return;
    }
    else
    {
        erase(n->next);
        if (strcmp(n->word, "\0") == 0)
        {
            return;
        }
        //printf("erasing %s...\n", n->word);
        free(n);
    }
}