#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cgen.h"

extern int yylineno;

void ssopen(sstream *S) { S->stream = open_memstream(&S->buffer, &S->bufsize); }

char *ssvalue(sstream *S)
{
  fflush(S->stream);
  return S->buffer;
}

void ssclose(sstream *S) { fclose(S->stream); }

char *replaceChar(char *const source, char toBeReplaced, char replacer)
{
  for (int i = 0; i < strlen(source); ++i)
  {
    if (source[i] == toBeReplaced)
    {
      source[i] = replacer;
    }
  }
  return source;
}

char *template(const char *pat, ...)
{
  sstream S;
  ssopen(&S);

  va_list arg;
  va_start(arg, pat);
  vfprintf(S.stream, pat, arg);
  va_end(arg);

  char *ret = ssvalue(&S);
  ssclose(&S);
  return ret;
}

/*
        Report errors
*/
void yyerror(char const *pat, ...)
{
  va_list arg;
  fprintf(stderr, "line %d: ", yylineno);

  va_start(arg, pat);
  vfprintf(stderr, pat, arg);
  va_end(arg);

  fprintf(stderr, "\n");

  yyerror_count++;
}

int yyerror_count = 0;

const char *c_prologue =
    "#include \"lambdalib.h\"\n"
    "\n";
