// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int counter = 0;


// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int length =strlen(word);
    char copy[length+1]; // take a byte extra for NTC
    copy[length] = '\0'; // necessary to add the ntc after allocating space to it

    // not converting gave errors to :) handles min length (1-char) words
    //:) handles max length (45-char) words
    //:) handles words with apostrophes properly
    //:) spell-checking is case-insensitive
    for (int i = 0; i < length; i++) // we take the word and LC and save that into copy
    {
        copy[i] = tolower(word[i]);
    }

    int checkhash = hash(copy); // get a hashcode for that copy
    node *check = table[checkhash]; // take a pointer tmp to point at what that array of hashcode is pointing
    
    if (check == NULL) // if tmp points to null return
    {
        return false;
    }
    
    while (check != NULL) // do it until the ll ends
    {
        if (strcasecmp(check->word,copy)==0) // check case insesnitive for word in node to our word(copy)
        {
            return true; // if found
        }
        
        check = check->next; // else move to next node, traverse the ll
    }
    

    return false; // if not found copy until end
}


// Hashes word to a number
//  stackoverflow
//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/ this was for a prior one that I altered later to ^
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = *word;
    while (c == *word++)
        {
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        }
    return hash % N;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //1. open dictionary file
    //2. read strings from file one at a time
    //3. create new node for each word
    //4. hash word to obtain hash value
    //5. insert node into hash table at that location

    //The following open dictionary file
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        //printf("loaded alr bodoh\n");
        return false;
    }

    //The following read strings from the file
    char word[LENGTH+1];

    while(fscanf(dict, "%s", word) != EOF) //fscanf = scanning from file.
    {
        //creates new node for each word
        node *n = malloc(sizeof(node)); //*n is the new node

        if (n==NULL)
        {
            return false;
        }

        strcpy(n->word, word); // copies word in array into n->word (node)
        n->next = NULL;


        int x = hash(word); //hash the word

        //new_node should point to whatever was previous in list
        // new_node->next = head;
        // head = new_node;
        n->next = table[x];
        table[x] = n;

        // counter for wach word in dictionary
        counter++;

    }



    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    //1. need to return words in the dictionary
    //you can either iterate over one of every linked lists

    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{



    for (int i = 0; i < N; i++)
    {
        node *free_cursor = table[i];

        while (free_cursor != NULL)
        {
            node *tmp = NULL;

            tmp = free_cursor;
            free_cursor = free_cursor->next;
            free(tmp);

        }

    }


    return true;
}
