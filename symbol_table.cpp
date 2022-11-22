#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE
typedef struct lval_s {
    int line;
    int col;
    /* the value of the token. if it is the number 0, this is going to be 0 */
    char *lexeme;
    int token;
} lval;


/* all we have as symbols for the symbol table are identifiers. other possible
   symbols are, for example, goto labels */
typedef struct symbol_s {
    int scope;
    /* this is the actual name of the symbol. an id 'foo' has the name foo */
    char *name;
    char *type;
    bool is_const;
    lval val;
} symbol;

// since we have 128 ASCII characters, that's the max number of children our
// trie can have, even though we won't use all of them
#define N 128

typedef struct symbol_table_node_s {
    struct symbol_table_node_s *children[N];
    symbol sym;
    bool is_leaf;
} symbol_table_node;

symbol_table_node* root;

symbol_table_node *initialize()
{
    symbol_table_node *novo = (symbol_table_node*) calloc(1, sizeof(symbol_table_node));
    for (int i = 0; i < N; i++) novo->children[i] = NULL;
    novo->is_leaf = 0;

    return novo;
}

void adiciona(symbol simbolo)
{
    symbol_table_node *tmp = root;
    char* word = simbolo.name;
    for (int i = 0; word[i] != '\0'; i++) {
        /* get the relative position in the alphabet list */
        int position = (int) word[i] - 'a';

        if (tmp->children[position] == NULL)
            tmp->children[position] = initialize();

        tmp = tmp->children[position];
    }

    tmp->is_leaf = 1;

      tmp->sym = simbolo;
}

symbol_table_node *acha(symbol simbolo)
{
    /* searches for word in the trie */
    symbol_table_node *tmp = root;
    char* word = simbolo.name;
    for(int i = 0; word[i] != '\0'; i++)
    {
        int position = word[i] - 'a';
        if (tmp->children[position] == NULL) return NULL;
        tmp = tmp->children[position];
    }

    if (tmp != NULL && tmp->is_leaf == 1) return tmp;

    return NULL;
}
#endif
