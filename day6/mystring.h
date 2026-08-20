#ifndef MYSTRING_H
#define MYSTRING_H

/* Replace every 'find' with 'rep' in s, in place. s must be writable. Returns how many were replaced. */

int replace_char(char *s, char find, char rep);

/* Remove a trailing '\n' from s if there is one. 
Returns 1 if one was removed, 0 otherwise. */
int trim_newline(char *s);

#endif
