# print_array.asm program
# For CMPSC 64
#
# Instructions: MODIFY THE PROGRAM PER THE DETAILS BELOW
#
#   Once you have finished modifying everything, save this file as:
#           print_reverse_array.asm
#   and submit it to Gradescope.
.data
	array:      .word 1 2 3 4 5 60 70 80 90 100 
	# Write the definition here of an int array
    newline:    .asciiz "\n"
	# Write the definition here of a newline character (string)
	cout:       .asciiz "The contents of the array are:\n"
	# Write the definition here of the output string

.text
printArr:
	move $t0, $a0
	move $t1, $a1
print_loop:
	beq $t1, $zero, return
	addi $t1, $t1, -1
	sll $t2, $t1, 2
	add $t3, $t0, $t2
	lw $a0, 0($t3)
	li $v0, 1
	syscall

	li $v0, 4
	la $a0, newline
	syscall
	j print_loop

return:
	jr $ra

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

