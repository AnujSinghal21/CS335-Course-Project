.data
		integer_format:	.asciz,	"%ld\n"
.global	main
.text

main:
func2:
		pushq	%rbp
		movq	%rsp,	%rbp
		sub	$4,	%rsp

		# ##t6 = return_value;
		mov	$10, -4(%rbp)


		# push_param ##t6;
		pushq	-4(%rbp)

		# call_func print;
		call	print
		add	$8,	%rsp

		# return_value;
		popq	%r11
		popq	%r10
		popq	%r9
		popq	%r8
		popq	%rdx
		popq	%rcx
		popq	%rax

		# end_func
		movq	$60,	%rax
		xor	%rdi,	%rdi
		syscall

print:
    pushq	%rbp
    mov	%rsp,	%rbp
    pushq	%rbx
    pushq	%rdi
    pushq	%rsi
    pushq	%r12
    pushq	%r13
    pushq	%r14
    pushq	%r15

    testq $15, %rsp
    jz is_print_aligned

    pushq $0                 # align to 16 bytes

    lea  integer_format(%rip), %rdi
    movq  16(%rbp), %rsi      
    xor %rax, %rax          
    call printf

    add $8, %rsp
    jmp print_done

is_print_aligned:

    lea  integer_format(%rip), %rdi
    movq  16(%rbp), %rsi          
    xor %rax, %rax         
    call printf
    
print_done: 

    popq %r15
    popq %r14
    popq %r13
    popq %r12
    popq %rsi
    popq %rdi
    popq %rbx
    popq %rbp

    ret

