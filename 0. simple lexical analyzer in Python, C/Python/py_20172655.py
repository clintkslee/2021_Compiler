#py_20172655.py
#20172655 이강산

import os

#Variables
global fp
fp = open('./front02.py', mode='rt', encoding='utf-8')
global charClass
charClass = 0
global lexeme
lexeme = []
global nextChar
nextChar = ''
global nextToken
nextToken = 0

float_check = 0; 

#reserved word lookup table
reserved_word = ['for', 'in', 'if', 'elif', 'else', 'while', 'break', 'continue', 'return']
RESERVED_WORD_CNT = 9
EOF = -1

#Character classes
LETTER = 0 #A-Z, a-z
DIGIT = 1 #number
UNKNOWN = 99 #not included in LETTER and DIGIT

#Token codes
INT_LIT = 10 #integer literal
FLOAT_LIT = 62 #float literal
IDENT = 11 #identifier

#non-alphabet characters
ASSIGN_OP = 20 #=
ADD_OP = 21 #+
SUB_OP = 22 #-
MULT_OP = 23 #*
DIV_OP = 24 #/
MOD_OP = 63 #%
CMPRIGHT_OP = 65 #<
CMPLEFT_OP = 66 #>
LEFT_PAREN = 25 #(
RIGHT_PAREN = 26 #)
QUOTES = 67 #'
COLON = 68 #:

#reserved words
FOR_CODE = 30 #for
IN_CODE = 31 #in
IF_CODE = 32 #if
ELIF_CODE = 33 #elif
ELSE_CODE = 34 #else         
WHILE_CODE = 35 #while                
BREAK_CODE = 36 #break
CONTINUE_CODE = 37 #continue 
RETURN_CODE = 38 #return 
#/*****************************************************/
def lookup(ch):
        global nextToken
        if ch=='=':
                addChar()
                nextToken = ASSIGN_OP
        elif ch=='+':
                addChar()
                nextToken = ADD_OP
        elif ch=='-':
                addChar()
                nextToken = SUB_OP
        elif ch=='*':
        	addChar()
        	nextToken = MULT_OP
        elif ch=='/':
        	addChar()
        	nextToken = DIV_OP
        elif ch=='%':
        	addChar()
        	nextToken = MOD_OP
        elif ch=='<':
        	addChar()
        	nextToken = CMPRIGHT_OP
        elif ch=='>':
        	addChar()
        	nextToken = CMPLEFT_OP
        elif ch=='(':
        	addChar()
        	nextToken = LEFT_PAREN
        elif ch==')':
        	addChar()
        	nextToken = RIGHT_PAREN
        elif ch=='\'':
        	addChar()
        	nextToken = QUOTES
        elif ch==':':		
        	addChar()
        	nextToken = COLON
        else:
        	addChar()
        	nextToken = EOF
        return nextToken
#/*****************************************************/
def lookup_ident():
        global lexeme
        global nextToken
        for i in range(RESERVED_WORD_CNT):
                if "".join(lexeme)==reserved_word[i]:
                        nextToken = i + 30
                        return nextToken
        nextToken = IDENT
        return nextToken
#/*****************************************************/
def addChar():
        global lexeme
        global nextChar
        lexeme.append(nextChar)
        return
#/*****************************************************/
def getChar():
        global nextChar
        global fp
        global charClass
        global float_check
        nextChar=fp.read(1)
        if not nextChar:
                charClass=EOF
                return  
        if nextChar.isalpha():
                charClass=LETTER
        elif nextChar.isdigit() or nextChar=='.':
                if nextChar=='.':
                        float_check=1       
                charClass=DIGIT
        else:
                charClass=UNKNOWN
        return
#/*****************************************************/
def getNonBlank():
        global nextChar
        while nextChar.isspace():
                getChar()        
#/*****************************************************/
def lex():
        global charClass
        global nextChar
        global lexeme
        global nextToken
        global float_check
        lexLen = 0
        getNonBlank()
        if charClass == LETTER:
                addChar()
                getChar()
                while (charClass == LETTER) or (charClass == DIGIT):
                        addChar()
                        getChar()
                lookup_ident()
        elif charClass == DIGIT:
                addChar()
                getChar()
                while charClass == DIGIT:
                        addChar()
                        getChar()
                if float_check==1:
                        nextToken = FLOAT_LIT
                else:
                        nextToken = INT_LIT

        elif charClass == UNKNOWN:
                lookup(nextChar)
                getChar()
	    
        elif charClass == EOF:
                nextToken = EOF;
                lexeme.append('E')
                lexeme.append('O')
                lexeme.append('F')
	
        str="".join(lexeme)
        print("Next token is {0}, Next lexeme is {1}".format(nextToken, str))
        float_check = 0
        lexeme=[]
        return nextToken
#/*****************************************************/
if __name__ == '__main__':
        while True:
            lex()
            if nextToken==EOF:
                break
        fp.close()
        os.system("pause")


















