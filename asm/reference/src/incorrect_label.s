	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:Hi, %1

Hi:	live %234
	ld %0, r3
	zjmp %:hi
