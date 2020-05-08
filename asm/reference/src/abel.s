	.name "Abel"
	.comment "L'amer noir." # comment comment

# Just a comment
	sti r1, %:hi, %1 # comment
hi:	live %234
	ld %0, r3
	zjmp %:hi
