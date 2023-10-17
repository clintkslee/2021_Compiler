	      INT  0, 32
	      SUP  0, main
	      RET  0, 0
main:
	      INT  0, 24
	      LDA  1, 12
	     LITI  0, 1
	      STX  0, 1
	      POP  0, 1
	      LDA  1, 16
	      LOD  0, 12
	      STX  0, 1
	      POP  0, 1
	      LDA  1, 20
	     LITI  0, 120
	     STXB  0, 0
	      POP  0, 1
	      INT  0, 12
	      LDA  0, 16
	      LOD  1, 12
	      LOD  1, 16
	      LOD  1, 20
	      POP  0, 7
	     ADDR  0, printf
	      CAL  0, 0
	      RET  0, 0
.literal    12 3.140000
.literal    16 "%d %f %c\n"
