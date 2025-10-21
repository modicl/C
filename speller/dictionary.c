// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1196;
unsigned int wordcount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashnumber = hash(word);
    node *cursor = table[hashnumber];
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word,word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hashvalue = 0;
    int hashtotal = 0;
    if (strlen(word) == 1)
    {
        return (toupper(word[0]) - 'A')*2;
    }
    else
    {
        for(int i = 0 , n = strlen(word) ; i < n ; i++)
        {
            hashvalue = toupper(word[i]) - 'A';
            hashtotal = hashtotal + hashvalue;
        }
    }
    return hashtotal;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initializing the buffer for reading words
    char tempword[LENGTH + 1];
    // We open the dictionary
    FILE *dict = fopen(dictionary, "r");
    // We check if dict is NULL
    if (dict == NULL)
    {
        return false;
    }
    // Read string from file
    while(fscanf(dict, "%s", tempword) != EOF)
    {
        // Creating node
        node *new_w = malloc(sizeof(node));
        if (new_w == NULL)
        {
            return false;
        }
        strcpy(new_w -> word, tempword);

        // We get the hash for indexing
        int hashIndex = hash(tempword);

        // If index is null
        if(table[hashIndex] == NULL)
        {
            new_w -> next = NULL;
        }
        else
        {
            // We point to the first node in the linked list in certain index
            new_w -> next = table[hashIndex];
        }
        // We assign temp as the first node
        table[hashIndex] = new_w;

        wordcount += 1;

    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return wordcount;
}

void freenode(node *n)
{
    if(n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        if(table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}
