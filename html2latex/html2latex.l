%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list_type;
%}

%option       noyywrap nounput yylineno
%x            COMMENT PARA PRE OL UL LI

%%

"<h1>"[^<]*"</h1>" {
    /**************************************************************************
     * Matched an HTML H1 header so print it out as a LateX section title.
     * The beginning and ending tags need to be stripped off before the
     * title can be formatted in LateX.
     *************************************************************************/
    yytext[yyleng-5] = 0;
    printf( "\\section{%s}", yytext+4 );
}

"<h2>".*"</h2>" {
	int s = 4, e = 5;
	yytext[yyleng - e] = 0;
	printf("\\subsection{%s}", yytext+s);
}


"<h3>".*"</h3>" {
	int s = 4, e = 5;
	yytext[yyleng - e] = 0;
	printf("\\subsubsection{%s}", yytext+s);
}


"<pre>".* {
	int s = 5, e = 6;
	printf("\\begin{verbatim}");
	//yytext[yyleng-e] = 0;
	printf("%s", yytext + s);
	BEGIN PRE;
}


"<!--" {
    /**************************************************************************
     * Matched an HTML comment so print it out as a LateX comment. The
     * beginning and ending tags are stripped off before the LateX comment
     * is emitted.
     *************************************************************************/
    printf( "%% " );
    BEGIN COMMENT;
}



"<p>" {
	// paragraph
	printf("%s", yytext + 3);
	BEGIN PARA;
}


"<ul>"[^<]* { printf("\\begin{itemize}\n"); }
"<ol>"[^<]* { printf("\\begin{enumerate}\n"); }

"<li>"[^<]* {
	printf("\t\\item %s", yytext + 4);
	BEGIN PARA;
}


"</ul>" { printf("\\end{itemize}\n"); }
"</ol>" { printf("\\end{enumerate}\n"); }


[ \t\n\r]+ {
    /**************************************************************************
     * Matched some whitespace that is not inside of an HTML tag. We
     * just ignore the whitespace.
     *************************************************************************/
}

. {
    /**************************************************************************
     * Matched something that we did not expect to see. Issue an error and
     * exit the program with a failure code.
     *************************************************************************/
    fprintf( stderr, "Unexpected input at line %d: '%s'\n", yylineno, yytext );
    exit( 1 );
}

<PRE>"</pre>" { 
	printf("\\end{verbatim}\n");
	BEGIN 0;
}


<PRE>[^<]* {
	printf("%s", yytext);
}

<PARA>"<small>".*"</small>" {
	// found a small tag in a para
	yytext[yyleng-8] = 0;
	printf("{\\scriptsize %s}", yytext+7);
}

<PARA>"<em>".*"</em>" {
	int e = 5;
	int s = 4;
	yytext[yyleng-e] = 0;
	printf("\\emph{%s}", yytext+s);
}




<PARA>"<b>".*"</b>" {
	int e = 4, s = 3;
	yytext[yyleng-e] = 0;
	printf("\\textbf{%s}", yytext+s);
}






<PARA>"<i>".*"</i>" {
	int s = 3, e = 4;
	yytext[yyleng-e] = 0;
	printf("\\textit{%s}", yytext+s);
}


<PARA>"<strong>".*"</strong>" {
    int s = 8, e = 9;
    yytext[yyleng-e] = 0;
    printf("\\textmd{%s}", yytext+s);
}



<PARA>"<sup>".*"</sup>" {
	int s = 5, e = 6;
	yytext[yyleng-e] = 0;
	printf("\\textsuperscript{%s}", yytext+s);
}


<PARA>"<sub>".*"</sub>" {
	int s = 5, e = 6;
	yytext[yyleng-e] = 0;
	printf("\\textsubscript{%s}", yytext+s);
}


<PARA>"<big>".*"</big>" {
	// found a big tag in a para
	yytext[yyleng-6] = 0;
	printf("{\\Large %s}", yytext+5);
}


<PARA>"</p>" {
	// At the end of parsing a para
	yytext[yyleng-4] = 0;
	printf("%s\n\n", yytext);
	BEGIN 0;
}



<PARA>"</li>" {
	//yytext[yyleng-5] = 0;
	//printf("\\item %s\n", yytext)l
	printf("\n\n");
	BEGIN 0;
}

<PARA>.*"<\li>" {
	yytext[yyleng-5] = 0;
	printf("\\item %s\n\n", yytext);
	BEGIN 0;
}



<COMMENT>"-->" {
    /**************************************************************************
     * Matched an HTML end comment while parsing an HTML comment. Print out
     * a new line and resume normal parsing.
     *************************************************************************/
    printf( "\n" );
    BEGIN 0;
}

<COMMENT>[\n](\r)? {
    /**************************************************************************
     * Matched a newline while parsing an HTML comment. Print out a new
     * line making sure to mark the next line as a comment as well.
     *************************************************************************/
    printf( "\n%% " );
}

<COMMENT>[ \t] {
    /**************************************************************************
     * Matched some white space while parsing an HTML comment. Print out
     * the white space as is.
     *************************************************************************/
    printf( "%s", yytext );
}

<COMMENT>. {
    /**************************************************************************
     * Matched any other text while parsing an HTML comment. Print out
     * the text as is.
     *************************************************************************/
    printf( "%s", yytext );
}

%%

/**************************************************************************
 * The main function for the HTML to LateX converter. Here we do three
 * things:
 *  1. Print out the LateX document header.
 *  2. Invoke the lexer to print out the LateX document
 *  3. Print out the LateX footer.
 *************************************************************************/
int main( int argc, const char *argv[] ) {
    printf( "\\documentclass[12pt]{article}\n" );
    printf( "\\usepackage{fixltx2e}\n" );
    printf( "\n" );
    printf( "\\setlength{\\parindent}{0.0in}\n" );
    printf( "\\setlength{\\parskip}{0.125in}\n" );
    printf( "\n\n" );
    printf( "\\begin{document}\n" );
    yylex();
    printf( "\\end{document}\n" );
    return 0;
}
