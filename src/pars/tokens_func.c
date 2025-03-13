#include "../minishell.h"

// Helper function to check if a character is a valid quote
int is_quote(char c)
{
    return (c == '\'' || c == '"');
}

int skip_space(const char *input, int i)
{
    while (input[i] && (input[i] == ' ' || input[i] == '\t'))
        i++;
    return (i);
}

// Enhanced function to handle quotes properly
int skip_token_end(const char *input, int i)
{
    char quote;
    int start_pos;

    if (!input[i])
        return i;
    
    // Handle redirection operators
    if ((input[i] == '>' && input[i + 1] == '>') || (input[i] == '<' && input[i + 1] == '<'))
        return (i + 2);
    
    // Handle special characters
    if (if_special(input[i]))
        return (i + 1);
    
    // Handle quoted strings
    if (is_quote(input[i]))
    {
        quote = input[i++];
        start_pos = i - 1;
        
        // Continue until matching quote is found or end of string
        while (input[i] && input[i] != quote)
            i++;
        
        // Handle unclosed quotes
        if (!input[i])
        {
            ft_printf(RED"Error: Unclosed %c quote"RST"\n", quote);
            // Return to the start of the quoted string
            return start_pos;
        }
        
        // Skip the closing quote
        if (input[i] == quote)
            i++;
        
        return (i);
    }
    
    // Handle normal tokens (including backslashes)
    while (input[i])
    {
        // Handle backslash: include the next character as part of the token
        if (input[i] == '\\' && input[i + 1])
        {
            i += 2; // Skip both the backslash and the escaped character
            continue;
        }
        
        // Stop at spaces or special characters or quotes
        if (yesspace(input[i]) || if_special(input[i]) || is_quote(input[i]))
            break;
            
        i++;
    }
    
    return (i);
}

// Function to extract the content of a token with proper quote handling
char *extract_token_content(const char *input, int start, int end)
{
    char *token_str;
    
    if (start >= end)
        return NULL;
    
    token_str = strndup(input + start, end - start);
    if (!token_str)
        return NULL;
    
    return token_str;
}

t_token *create_token(const char *input, int start, int end, t_token *prev)
{
    t_token *n_token;
    char *token_str;

    if (start >= end)
        return NULL;

    n_token = malloc(sizeof(t_token));
    if (!n_token)
        return NULL;

    token_str = extract_token_content(input, start, end);
    if (!token_str)
    {
        free(n_token);
        return NULL;
    }

    n_token->str = token_str;
    n_token->type = define_type(n_token, prev);
    n_token->next = NULL;
    n_token->prev = prev;
    n_token->fd_in = -1;  // Initialize file descriptors
    n_token->fd_out = -1;

    return n_token;
}

// Function to check if a token is quoted and set its type accordingly
void set_token_quote_type(t_token *token)
{
    int len;
    
    if (!token || !token->str)
        return;
    
    len = ft_strlen(token->str);
    if (len < 2)
        return;
    
    // Check if the token is enclosed in quotes
    if ((token->str[0] == '"' && token->str[len - 1] == '"') ||
        (token->str[0] == '\'' && token->str[len - 1] == '\''))
    {
        token->type = STR;
    }
}

t_token *tokenize(char *input)
{
    t_token *head = NULL;
    t_token *current = NULL;
    int i = 0;
    int unclosed_quote = 0;

    while (input[i])
    {
        i = skip_space(input, i);
        int start = i;
        
        // Handle special tokens (quotes, redirections, etc.)
        int old_i = i;
        i = skip_token_end(input, i);
        
        // Check if there was an unclosed quote
        if (i == start && old_i != i)
        {
            // An error was encountered with unclosed quotes
            unclosed_quote = 1;
            break;
        }
        
        if (i > start)
        {
            t_token *new_token = create_token(input, start, i, current);
            if (!new_token)
            {
                // Handle error - cleanup and return
                if (head)
                    free_tokens(head);
                return NULL;
            }
            
            // Set quote-specific type
            set_token_quote_type(new_token);
            
            if (!head)
                head = new_token;
            if (current)
                current->next = new_token;
            current = new_token;
        }
        else
            i++;
    }
    
    if (unclosed_quote)
    {
        // Clean up and return NULL for unclosed quotes
        if (head)
            free_tokens(head);
        return NULL;
    }
    
    return head;
}