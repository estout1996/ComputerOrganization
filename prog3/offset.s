/*Elizabeth Stout
  CPSC 2310 project 3
  Due July 28, 2020

  This function returns the offset needed to access an element in a 2d array 

  Given i = row, j = col, n = number of columns in row, offset is calculated by:
  offset = (i * n + j) * 4
*/

.text
.align 4
.global offset
.type offset, %function
offset:
	push {lr}

	mul r3,r0,r2 //multiply i*n
	add r3, r3, r1 //add j to the result
	mov r0, r3, lsl #2 //multiply by 4

	pop {pc}

