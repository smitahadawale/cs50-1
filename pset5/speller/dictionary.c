/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
 int dict_size ;
 int c;
 typedef struct Node Node;

 struct Node{
     Node *child[27];
    bool end;
 };
 
 Node* root;
 
 bool find(Node* curr,const char* word,int pos,int len)
 {
     if(pos == len)
     {
         return curr->end;
     }
     
     int idx;
     
   if(word[pos] == '\'')
    idx = 26;
   else
    {
        char x = tolower(word[pos]);
        idx = x-'a';
    }
     if(curr->child[idx] == NULL)
    {
       return false;
    }
    
   return find(curr->child[idx],word,pos+1,len);
     
 }
 
bool check(const char *word)
{
    return find(root,word,0,(int)strlen(word));
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
void insert(Node* curr,char* word,int pos,int len)
{
    if(pos == len)
    {
        curr->end = true;
        return;
    }
  
   int idx ;
  
   if(word[pos] == '\'')
    idx = 26;
   else
    {
        char x = tolower(word[pos]);
        idx = x-'a';
    }
    if(curr->child[idx] == NULL)
    {
        curr->child[idx] = (Node*) malloc(sizeof(Node));
        curr->child[idx]->end = false;
    }
    
    insert(curr->child[idx],word,pos+1,len);
    
}
 
bool load(const char *dictionary)
{   c = 0;
   dict_size = 0;
   char s[50];
   FILE *fp = fopen(dictionary, "r");
    root = (Node *)malloc(sizeof(Node));
   
   while(true)
   {
    if(fscanf(fp,"%s",s) == EOF) break;
    
    insert(root,s,0,(int)strlen(s));
    
    dict_size++;
   }
   return true;
}



/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
 
 void delete(Node* root)
 {
     for(int i=0; i<27; i++)
     if(root->child[i] != NULL)
     {
         delete(root->child[i]);
     }
     free(root);
 }
 
unsigned int size(void)
{
    
   return dict_size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    delete(root);
    return true;
}
