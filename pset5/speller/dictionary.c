// Implements a dictionary's functionality

#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"


//create a global array to link to lists
node_t* list;//[BUCKETS];
unsigned int dictSize;

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

    // fprintf("Checking to see if %s is correctly spelled...\n", lowerWord);
    if (lowerWord == NULL)
    {
        free(lowerWord);
        return false;
    }
    else
    {
        //look in list[hash(lowerWord)] to see if this lowerWord is in there
        //create a node cursor to scan list, should start pointing to same pointer the head does
        node_t * cursor = &list[hash(lowerWord)];
        while (cursor != NULL)//strncmp(cursor->word, "\0", length) != 0)
        {
            char* cursWord = cursor->word;
            if(strncmp(cursWord, lowerWord, length) == 0 && strcmp(&cursWord[length], "\0") == 0)
            {
                //printf("%s is correctly spelled!\n", word);
                free(lowerWord);
                return true;
            }
            else
            {
                cursor = cursor->next;
            }
        }
    }
    //printf("%s is NOT correctly spelled!\n", word);
    free(lowerWord);
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
    //printf("Begining Loading loop...\n");
    while(fscanf(dictFile, "%s", word) != EOF)
    {
        // printf("Loading word %s...\n", word);


        //malloc a new node for each word
        node_t *new_node = malloc(sizeof(node_t));

        // confirm new node is valid
        if(new_node == NULL)
        {
            free(new_node);
            unload();
            return false;
        }

        //outsource the insertion to a separate function
        insert(word);
        free(new_node);
    }
    fclose(dictFile);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictSize;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < BUCKETS; i++)
    {
        //printf("Sending the %c bucket for erasure...\n", i+'a');
        node_t* head = &list[i];
        erase(&head);
    }

    free(list);
    return true;
}


//hash function
int hash(const char *word)
{
    if(word[0] == 39)
    {
        return 26;
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
    dictSize++;

    return true;
}

void initList()
{
    //allocate memory to list buckets
    list = (node_t*)malloc(sizeof(node_t) * BUCKETS);
    dictSize = 0;

    for(int i = 0; i < BUCKETS; i++)
    {
        node_t head = list[i];
        strcpy(head.word, "\0");
        head.next = NULL;
    }
}

void erase(node_t** n)
{
    node_t* temp = *n;
    if (temp->next == NULL)
    {
        return;
    }
    else
    {
        erase(&temp->next);
        if (strcmp(temp->word, "\0") == 0)
        {
            return;
        }
        //printf("erasing %s...\n", temp->word);
        free(temp);
    }
}