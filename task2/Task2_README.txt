Task2: Syntax analysis of the given input
Output: Valid Input or Syntax Error

Commands:
yacc -d ASPV9624.y
lex ASPV9624.l
gcc y.tab.c lex.yy.c -ll
./a.out <filename.txt>

Here the filename can entered as per the users requirements.