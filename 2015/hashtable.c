#include <stdint.h>
#include <string.h>

struct nlist { // Table Entry:
    struct nlist *next;
    char *name; // Key
    char *defn; // Val
};

#define HASHSIZE 101
static struct nlist *hashtable[HASHSIZE]; // Pointer table.

// Hash: form hash values for string.
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

// Lookup: look for s in hashtable.
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtable[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; // Found.
    return NULL; // Not Found.
}

char *strdup(char *);
// Install: put (name, defn) in hashtab.
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { // Not found.
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtable[hashval] = np;
    } else // Already there.
        free((void *) np->defn); // Free previous defn.
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

char *strdup(char *s) // Make a duplicate of s.
{
    char *p;
    p = (char *) malloc(strlen(s)+1); // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}