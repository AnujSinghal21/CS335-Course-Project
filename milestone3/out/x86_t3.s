.data
str_const_1: .asciz "1 and 3 has more ways"
str_const_2: .asciz "TAKE AS YOUR WISH"
str_const_3: .asciz "1 and 2 has more ways"
.globl main
.text
func1: 
	pushq %rbp
	movq %rsp, %rbp
	subq $96, %rsp
	movq 16(%rbp), %rbx
	movq $1, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq $3, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -16(%rbp)
	movq -8(%rbp), %rbx
	movq -16(%rbp), %rcx
	orq %rcx, %rbx
	movq %rbx, -24(%rbp)
	movq -24(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_1
	movq $1, %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp Label_6
Label_1: 
	movq 16(%rbp), %rbx
	movq $3, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -32(%rbp)
	movq -32(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_2
	movq 16(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -40(%rbp)
	pushq -40(%rbp)
	call func1
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -48(%rbp)
	movq 16(%rbp), %rbx
	movq $3, %rcx
	subq %rcx, %rbx
	movq %rbx, -56(%rbp)
	pushq -56(%rbp)
	call func1
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -64(%rbp)
	movq -48(%rbp), %rbx
	movq -64(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -72(%rbp)
	movq -72(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp Label_5
Label_2: 
	movq 16(%rbp), %rbx
	movq $3, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -80(%rbp)
	movq -80(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_3
	movq 16(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -88(%rbp)
	pushq -88(%rbp)
	call func1
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -96(%rbp)
	movq -96(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp Label_4
Label_3: 
Label_4: 
Label_5: 
Label_6: 
	movq %rbp, %rsp
	popq %rbp
	ret
func2: 
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq 16(%rbp), %rbx
	movq $1, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq $2, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -16(%rbp)
	movq -8(%rbp), %rbx
	movq -16(%rbp), %rcx
	orq %rcx, %rbx
	movq %rbx, -24(%rbp)
	movq -24(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_7
	movq $1, %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp Label_8
Label_7: 
	movq 16(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -32(%rbp)
	pushq -32(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -40(%rbp)
	movq 16(%rbp), %rbx
	movq $2, %rcx
	subq %rcx, %rbx
	movq %rbx, -48(%rbp)
	pushq -48(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -56(%rbp)
	movq -40(%rbp), %rbx
	movq -56(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -64(%rbp)
	movq -64(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
Label_8: 
	movq %rbp, %rsp
	popq %rbp
	ret
main: 
	pushq %rbp
	movq %rsp, %rbp
	subq $88, %rsp
	movq $40, %rbx
	movq %rbx, -8(%rbp)
Label_9: 
	movq $1, %rbx
	movq %rbx, -16(%rbp)
Label_10: 
	movq -16(%rbp), %rbx
	movq -8(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -24(%rbp)
	movq -24(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_15
	pushq -16(%rbp)
	call func1
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -32(%rbp)
	movq -32(%rbp), %rbx
	movq %rbx, -40(%rbp)
	pushq -16(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -48(%rbp)
	movq -48(%rbp), %rbx
	movq %rbx, -56(%rbp)
	movq -40(%rbp), %rbx
	movq -56(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -64(%rbp)
	movq -64(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_11
	lea str_const_1(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	jmp Label_14
Label_11: 
	movq -40(%rbp), %rbx
	movq -56(%rbp), %rcx
	xorq %rcx, %rbx
	movq %rbx, -72(%rbp)
	movq -72(%rbp), %rbx
	movq $0, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -80(%rbp)
	movq -80(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_12
	lea str_const_2(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	jmp Label_13
Label_12: 
	lea str_const_3(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
Label_13: 
Label_14: 
	movq -16(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -88(%rbp)
	movq -88(%rbp), %rbx
	movq %rbx, -16(%rbp)
	jmp Label_10
Label_15: 
	movq %rbp, %rsp
	popq %rbp
	jmp exit0
exit0:
    movq	$60, %rax
    movq $0, %rdi
    syscall
print_int:
    pushq	%rbp
    mov	%rsp,	%rbp
    testq $15, %rsp
    jz is_print_int_aligned

    pushq $0                 # align to 16 bytes

    lea  integer_format(%rip), %rdi
    movq  16(%rbp), %rsi
    call printf

    add $8, %rsp
    popq %rbp
    ret

is_print_int_aligned:
    lea  integer_format(%rip), %rdi
    movq  16(%rbp), %rsi
    call printf

    popq %rbp
    ret
print_string:
    pushq	%rbp
    mov	%rsp,	%rbp
    testq $15, %rsp
    jz is_print_string_aligned

    pushq $0                 # align to 16 bytes

    lea  string_format(%rip), %rdi
    movq  16(%rbp), %rsi
    call printf

    add $8, %rsp
    popq %rbp
    ret

is_print_string_aligned:
    lea  string_format(%rip), %rdi
    movq  16(%rbp), %rsi
    call printf

    popq %rbp
    ret

print_bool:
    pushq	%rbp
    mov	%rsp,	%rbp
    testq $15, %rsp
    jz is_print_bool_aligned
    pushq $0                 # align to 16 bytes
    lea  string_format(%rip), %rdi
    cmpq $0, 16(%rbp)
    je print_bool_false
    lea true(%rip), %rsi
    call printf
    add $8, %rsp
    jmp print_bool_end
print_bool_false:
    lea false(%rip), %rsi
    call printf
    add $8, %rsp
    jmp print_bool_end

is_print_bool_aligned:
    lea  string_format(%rip), %rdi
    cmpq $0, 16(%rbp)
    je print_bool_aligned_false
    lea true(%rip), %rsi
    call printf
    jmp print_bool_end
print_bool_aligned_false:
    lea false(%rip), %rsi
    call printf
    jmp print_bool_end

print_bool_end:
    popq %rbp
    ret

power: 
	pushq %rbp
	movq %rsp, %rbp
	movq 16(%rbp), %rbx
	movq 24(%rbp), %rcx
	movq $1, %rax
pow_loop: 
	cmpq $0, %rcx
	je pow_exit
	imulq %rbx, %rax
	decq %rcx
	jmp pow_loop
pow_exit:
	movq %rax, %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
len:
	pushq %rbp
	movq %rsp, %rbp

    movq 16(%rbp), %rbx
    movq -8(%rbx), %rax
    movq $8, %rbx
    cqo
    idivq %rbx
        
    popq %rbp
    ret
.data
    integer_format:	.asciz,	"%ld\n"
    string_format: .asciz "%s\n" 
    true: .asciz "True\n"
    false: .asciz "False\n"

