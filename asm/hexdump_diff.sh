#!/usr/bin/sh

retval=0
output="`basename -s .s $1`.cor"
my_asm="./asm"
my_hexdump="my_hexdump"
reference_asm="./reference/reference_asm"
reference_hexdump="reference_hexdump"

make > /dev/null && $my_asm $1 && hexdump -C $output > $my_hexdump
$reference_asm $1 && hexdump -C $output > $reference_hexdump

echo "Testing with ${output}..."
diff $my_hexdump $reference_hexdump > /dev/null
retval=$?
if [ $retval -eq 0 ]; then
    echo "Hexdumps are identical"
else
    diff -y $my_hexdump $reference_hexdump
fi
rm $my_hexdump $reference_hexdump $output
if [ $retval -eq 0 ]; then
    true
else
    false
fi