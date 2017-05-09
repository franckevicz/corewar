.name		"Gagnant"
.comment	"JourJ"

ld   %0,r3
label:zjmp %:avantdebut
zjmp %0

code:live %42
sti  r15,%0,r14
zjmp %-200
live %42
sti  r15,%0,r14
zjmp %-200
live %42
sti  r15,%0,r14
zjmp %-200
live %42
sti  r15,%0,r14
zjmp %-200
sti  r15,%0,r14
zjmp %-200
sti  r15,%0,r14
zjmp %-200
	
avantdebut:	sti   r1,%:code,%1
		sti   r1,%:code,%15
		sti   r1,%:code,%29
		sti   r1,%:code,%43
		sti   r1,%:code,%57
		sti   r1,%:code,%71
init:		ld   %393216,r4
		ld   %917504,r12
		ld   %1,r11
		ld   %6,r10
debut:		live %42
		sti  r4,%:label,%1
		add  r4,r12,r4
		sub  r10,r11,r10
		zjmp %:init
		fork %:debut
		live %3
level0:		fork %:level10
level11:	live %4
		fork %:level111

level110:	live %42
		ldi  %8,%:code,r15
		ld   %-186,r14
		ld   %0,r2
		zjmp  %:label
			
level10:	live %42
		fork %:level100
level101:	live %42
		ldi  %4,%:code,r15
		ld   %-190,r14
		ld   %0,r2
		zjmp %:label
		
level111:	live %42
		ldi  %12,%:code,r15
		ld   %-182,r14
		ld   %0,r2
		zjmp %:label
		
level100:	live %42
		ldi  %0,%:code,r15
		ld   %-194,r14
		ld   %0,r2
		zjmp %:label
