	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1

hi:	live %234
	bd %0, r3
	zjmp %:hi
