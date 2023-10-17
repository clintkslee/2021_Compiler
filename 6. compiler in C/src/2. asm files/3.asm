	      INT  0, 28
	      SUP  0, main
	      RET  0, 0
main:
	      INT  0, 20
	      LDA  1, 16
	     LITI  0, 0
	      STX  0, 1
	      POP  0, 1
	      LDA  1, 12
	     LITI  0, 0
	      STX  0, 1
	      POP  0, 1
L2:
	      LOD  1, 12
	     LITI  0, 10
	     LSSI  0, 0
	      JPC  0, L3
	      LOD  1, 16
	      LDA  1, 16
	      LDX  0, 1
	     INCI  0, 0
	      STO  0, 1
	      POP  0, 1
L1:
	      LOD  1, 12
	      LDA  1, 12
	      LDX  0, 1
	     INCI  0, 0
	      STO  0, 1
	      POP  0, 1
	      JMP  0, L2
L3:
	      LDA  1, 16
	      LOD  1, 16
	     LITI  0, 2
	      MOD  0, 0
	      STX  0, 1
	      POP  0, 1
	      LOD  1, 16
	   SWITCH  0, L4
	      JMP  0, L5
L6:
	      LDA  1, 12
	     LITI  0, 13
	      STX  0, 1
	      POP  0, 1
	      JMP  0, L5
L7:
	      LDA  1, 12
	     LITI  0, 13
	   MINUSI  0, 0
	      STX  0, 1
	      POP  0, 1
	      JMP  0, L5
L4:
	  SWVALUE  0, 0
	  SWLABEL  0, L6
	  SWVALUE  0, 1
	  SWLABEL  0, L7
	    SWEND  0, 0
L5:
	      INT  0, 12
	      LDA  0, 12
	      LOD  1, 16
	      LOD  1, 12
	      POP  0, 6
	     ADDR  0, printf
	      CAL  0, 0
	      RET  0, 0
.literal    12 "a:%d i:%d\n"
