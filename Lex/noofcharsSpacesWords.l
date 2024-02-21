%{
    #include <stdio.h>
    int words=0,spaces=0,cc=0;

%}

%%
[ \t]  {spaces++;cc+=yyleng;}
[^\t\n ]+ {words++;cc+=yyleng;}


%%

int main(int argc, char* argv[])
{
	printf("Enter some input string:\n");
	yylex();
	printf("Number of words=%d\n",words);
    printf("Number of spaces=%d\n",spaces);
    printf("Number of characters=%d\n",cc);
}

int yywrap(){
    return 1;
}
