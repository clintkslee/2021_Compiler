a.out : y.tab.c lex.yy.c
	cc y.tab.c lex.yy.c

y.tab.c : kim.y
	yacc -d kim.y

lex.yy.c : kim.l
	lex kim.l

kim.y : 

kim.l :
