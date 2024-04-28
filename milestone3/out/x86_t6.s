.data
str_const_1: .asciz "Sorted Array in Ascending Order:"
.globl main
.text
func1: 
	pushq %rbp
	movq %rsp, %rbp
	subq $280, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	pushq 16(%rbp)
	call len
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -16(%rbp)
	movq -16(%rbp), %rbx
	movq %rbx, -24(%rbp)
Label_1: 
	movq $0, %rbx
	movq %rbx, -8(%rbp)
Label_2: 
	movq -8(%rbp), %rbx
	movq -24(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -32(%rbp)
	movq -32(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_12
	movq $0, %rbx
	movq %rbx, -40(%rbp)
Label_3: 
	movq $0, %rbx
	movq %rbx, -48(%rbp)
Label_4: 
	movq -24(%rbp), %rbx
	movq -8(%rbp), %rcx
	subq %rcx, %rbx
	movq %rbx, -56(%rbp)
	movq -56(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -64(%rbp)
	movq -48(%rbp), %rbx
	movq -64(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -72(%rbp)
	movq -72(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_9
	movq 24(%rbp), %rbx
	movq -8(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -80(%rbp)
	movq -80(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_5
	jmp Label_9
	jmp Label_6
Label_5: 
Label_6: 
	movq -48(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -88(%rbp)
	movq -88(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -96(%rbp)
	movq -48(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -104(%rbp)
	movq -104(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -112(%rbp)
	movq -112(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -120(%rbp)
	movq -96(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -128(%rbp)
	movq -120(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -136(%rbp)
	movq -128(%rbp), %rbx
	movq -136(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -144(%rbp)
	movq -144(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_7
	movq -48(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -152(%rbp)
	movq -152(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -160(%rbp)
	movq -160(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -168(%rbp)
	movq -168(%rbp), %rbx
	movq %rbx, -176(%rbp)
	movq -48(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -184(%rbp)
	movq -184(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -192(%rbp)
	movq -48(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -200(%rbp)
	movq -200(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -208(%rbp)
	movq -208(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -216(%rbp)
	movq -216(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -224(%rbp)
	movq -216(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -232(%rbp)
	movq -232(%rbp), %rbx
	movq -192(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -48(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -240(%rbp)
	movq -240(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -248(%rbp)
	movq -248(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -256(%rbp)
	movq -176(%rbp), %rbx
	movq -256(%rbp), %rcx
	movq %rbx, (%rcx)
	movq $1, %rbx
	movq %rbx, -40(%rbp)
	jmp Label_8
Label_7: 
Label_8: 
	movq -48(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -264(%rbp)
	movq -264(%rbp), %rbx
	movq %rbx, -48(%rbp)
	jmp Label_4
Label_9: 
	movq -40(%rbp), %rbx
	movq $0, %rcx
	cmpq %rcx, %rbx
	sete %cl
	movq %rcx, -272(%rbp)
	movq -272(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_10
	jmp Label_12
	jmp Label_11
Label_10: 
Label_11: 
	movq -8(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -280(%rbp)
	movq -280(%rbp), %rbx
	movq %rbx, -8(%rbp)
	jmp Label_2
Label_12: 
	movq %rbp, %rsp
	popq %rbp
	ret
main: 
	pushq %rbp
	movq %rsp, %rbp
	subq $168, %rsp
	movq $2, %rbx
	movq $0, %rcx
	subq %rbx, %rcx
	movq %rcx, -8(%rbp)
	movq $9, %rbx
	movq $0, %rcx
	subq %rbx, %rcx
	movq %rcx, -16(%rbp)
	movq %rbp, %rbx
	addq $-64, %rbx
	movq %rbx, -24(%rbp)
	movq $40, -8(%rbx)
	movq -8(%rbp), %rbx
	movq -24(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -24(%rbp), %rbx
	movq $8, %rcx
	addq %rcx, %rbx
	movq %rbx, -80(%rbp)
	movq $45, %rbx
	movq -80(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -24(%rbp), %rbx
	movq $16, %rcx
	addq %rcx, %rbx
	movq %rbx, -88(%rbp)
	movq $0, %rbx
	movq -88(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -24(%rbp), %rbx
	movq $24, %rcx
	addq %rcx, %rbx
	movq %rbx, -96(%rbp)
	movq $11, %rbx
	movq -96(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -24(%rbp), %rbx
	movq $32, %rcx
	addq %rcx, %rbx
	movq %rbx, -104(%rbp)
	movq -16(%rbp), %rbx
	movq -104(%rbp), %rcx
	movq %rbx, (%rcx)
	pushq -24(%rbp)
	call len
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -112(%rbp)
	movq -112(%rbp), %rbx
	movq %rbx, -120(%rbp)
	pushq -120(%rbp)
	pushq -24(%rbp)
	call func1
	addq $16, %rsp
	lea str_const_1(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	movq $0, %rbx
	movq %rbx, -128(%rbp)
Label_13: 
	movq $0, %rbx
	movq %rbx, -128(%rbp)
Label_14: 
	movq -128(%rbp), %rbx
	movq -120(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -136(%rbp)
	movq -136(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_15
	movq -128(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -144(%rbp)
	movq -144(%rbp), %rbx
	movq -24(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -152(%rbp)
	movq -152(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -160(%rbp)
	pushq -160(%rbp)
	call print_int
	addq $8, %rsp
	movq -128(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -168(%rbp)
	movq -168(%rbp), %rbx
	movq %rbx, -128(%rbp)
	jmp Label_14
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

