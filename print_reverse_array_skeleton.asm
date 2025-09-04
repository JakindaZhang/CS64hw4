# print_array.asm program
# For CMPSC 64
#
# Instructions: MODIFY THE PROGRAM PER THE DETAILS BELOW
#
#   Once you have finished modifying everything, save this file as:
#           print_reverse_array.asm
#   and submit it to Gradescope.
.data
	array:      # Write the definition here of an int array
    newline:    # Write the definition here of a newline character (string)
	cout:       # Write the definition here of the output string

.text
printArr:
    # TODO: Write your function code here

main:  # DO NOT MODIFY THE MAIN SECTION
	li $v0, 4
	la $a0, cout
	syscall

	la $a0, array
	li $a1, 10

	jal printArr

exit:
    li $v0, 10
    syscall

