.name "Julien Lepers"
.comment "Ouai, Ouai Ouai, Ouai"

jump: sti r1, %7, %1
live %1
fork %100
zjmp %:init

init: sti r1, %:live,%1
ld %355,r2
ld %4,r8

live: live %1
add r2,r3,r2
sti r6, %:live,r2
ldi r7,r8,r6
add r7,r8,r7
and r4, %0, r4

zjmp %:live