/*Elizabeth Stout
CPSC 2310 project 3
Due July 28, 2020
This is a main to test the offset function
*/
.text
.global main
.align 4
.type main, %function
main:
push {r4-r8,lr}
mov r4, r0 // Store argc
mov r5, r1 // Store argv

argc .req r4
argv .req r5
i .req r6
j .req r7
n .req r8

// *(argv + 1)
ldr r0, [argv, #4]
bl atoi
mov i, r0

// *(argv + 2)
ldr r0, [argv, #8]
bl atoi
mov j, r0

// *(argv + 3)
ldr r0, [argv, #12]
bl atoi
mov n, r0

// Set up parameters
mov r0, i
mov r1, j
mov r2, n
bl offset

// Preserve returned value in r3, and then print offset for i, j, n
mov r3, r0
ldr r0, =fmtline
mov r1, i
mov r2, j
bl printf
pop {r4-r8,pc}
.section ".rodata"
fmtline: .asciz "The offset for a[%d][%d] is %d\012\000"
