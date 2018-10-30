all: 
	make -f Makefile hallowelt
	make -f Makefile seq_fault
	make -f Makefile sorted_list

hallowelt: hallowelt.c
	gcc hallowelt.c -o hallowelt
	
seq_fault: seq_fault.c
	gcc seq_fault.c -o seq_fault
	
sorted_list: sorted_list.h sorted_list.c
	gcc sorted_list.c -o sorted_list
