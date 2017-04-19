.name "Kitty"
.comment "Mitty"

zjmp %:wall
st      r1,6
live    %0
ld  %16777216,r2
fork %:dead_zork
fork %:label_1

wall:
	live	%4902343
	st		r2,-36
	st		r1,-40
	st		r2,-51
	st		r1,-55
	st		r2,-66
	st		r1,-70
	st		r2,-81
	st		r1,-85
	st		r2,-96
	st		r1,-100
	st		r2,-111
	st		r1,-115
	sti     r1,%:label_1,%1
	sti     r1,%:wall,%1
	ld      %0,r16
    zjmp    %-142

label_1:
    live    %0
    ld      %0,r16
    sti     r1,%:wall_2,%1
    fork    %:label_1
    fork    %:wall
    st      r1,6

wall_2:
    live    %1
    st      r1,6
wall_3:
    live    %1
    st      r1,6
wall_4:
    live    %1
    st      r1,6
wall_5:
    live    %1
    st      r1,6
wall_6:
    live    %1
    st      r1,9
    zjmp    %:wall_2
dead_zork:
    live    %2147483647
