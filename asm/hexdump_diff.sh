#!/bin/bash

my_asm="./asm"
reference_asm="./reference/reference_asm"
input=`basename $1`
output="`basename -s .s $1`.cor"
my_hexdump="my_`basename -s .cor $output`_hexdump"
reference_hexdump="reference_`basename -s .cor $output`_hexdump"

make > /dev/null && $my_asm $1 && hexdump -C $output > $my_hexdump && rm $output
$reference_asm $1 && hexdump -C $output > $reference_hexdump && rm $output

echo -e "my_asm\t\t\t\t\t\t\t\treference_asm"
diff -s -y $my_hexdump $reference_hexdump
rm $my_hexdump $reference_hexdump