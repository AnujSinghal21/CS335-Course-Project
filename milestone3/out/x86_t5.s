.data
str_const_1: .asciz "Element is present at index:"
str_const_2: .asciz "Element is not present"
.globl main
.text
func1: 
	pushq %rbp
	movq %rsp, %rbp
	subq $128, %rsp
Label_1: 
	movq 32(%rbp), %rbx
	movq 40(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setle %dl
	movq %rdx, -8(%rbp)
	movq -8(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_6
	movq 40(%rbp), %rbx
	movq 32(%rbp), %rcx
	subq %rcx, %rbx
	movq %rbx, -16(%rbp)
	movq -16(%rbp), %rax
	movq $2, %rbx
	cqo
	idivq %rbx
	movq %rax, -24(%rbp)
	movq 32(%rbp), %rbx
	movq -24(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -32(%rbp)
	movq -32(%rbp), %rbx
	movq %rbx, -40(%rbp)
	movq -40(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -48(%rbp)
	movq -48(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -56(%rbp)
	movq -56(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -64(%rbp)
	movq -64(%rbp), %rbx
	movq 24(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -72(%rbp)
	movq -72(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_2
	movq -40(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp Label_5
Label_2: 
	movq -40(%rbp), %rbx
	movq $8, %rcx
	imulq %rcx, %rbx
	movq %rbx, -80(%rbp)
	movq -80(%rbp), %rbx
	movq 16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -88(%rbp)
	movq -88(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -96(%rbp)
	movq -96(%rbp), %rbx
	movq 24(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -104(%rbp)
	movq -104(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_3
	movq -40(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -112(%rbp)
	movq -112(%rbp), %rbx
	movq %rbx, 32(%rbp)
	jmp Label_4
Label_3: 
	movq -40(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -120(%rbp)
	movq -120(%rbp), %rbx
	movq %rbx, 40(%rbp)
Label_4: 
Label_5: 
	jmp Label_1
Label_6: 
	movq $1, %rbx
	movq $0, %rcx
	subq %rbx, %rcx
	movq %rcx, -128(%rbp)
	movq -128(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	movq %rbp, %rsp
	popq %rbp
	ret
main: 
	pushq %rbp
	movq %rsp, %rbp
	subq $168, %rsp
	movq %rbp, %rbx
	addq $-64, %rbx
	movq %rbx, -8(%rbp)
	movq $56, -8(%rbx)
	movq $3, %rbx
	movq -8(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -8(%rbp), %rbx
	movq $8, %rcx
	addq %rcx, %rbx
	movq %rbx, -80(%rbp)
	movq $4, %rbx
	movq -80(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -8(%rbp), %rbx
	movq $16, %rcx
	addq %rcx, %rbx
	movq %rbx, -88(%rbp)
	movq $5, %rbx
	movq -88(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -8(%rbp), %rbx
	movq $24, %rcx
	addq %rcx, %rbx
	movq %rbx, -96(%rbp)
	movq $6, %rbx
	movq -96(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -8(%rbp), %rbx
	movq $32, %rcx
	addq %rcx, %rbx
	movq %rbx, -104(%rbp)
	movq $7, %rbx
	movq -104(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -8(%rbp), %rbx
	movq $40, %rcx
	addq %rcx, %rbx
	movq %rbx, -112(%rbp)
	movq $8, %rbx
	movq -112(%rbp), %rcx
	movq %rbx, (%rcx)
	movq -8(%rbp), %rbx
	movq $48, %rcx
	addq %rcx, %rbx
	movq %rbx, -120(%rbp)
	movq $9, %rbx
	movq -120(%rbp), %rcx
	movq %rbx, (%rcx)
	pushq -8(%rbp)
	call len
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -128(%rbp)
	movq -128(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -136(%rbp)
	pushq -136(%rbp)
	pushq $0
	pushq $7
	pushq -8(%rbp)
	call func1
	addq $32, %rsp
	movq %rax, %rbx
	movq %rbx, -144(%rbp)
	movq -144(%rbp), %rbx
	movq %rbx, -152(%rbp)
	movq $1, %rbx
	movq $0, %rcx
	subq %rbx, %rcx
	movq %rcx, -160(%rbp)
	movq -152(%rbp), %rbx
	movq -160(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setne %dl
	movq %rdx, -168(%rbp)
	movq -168(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_7
	lea str_const_1(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	pushq -152(%rbp)
	call print_int
	addq $8, %rsp
	jmp Label_8
Label_7: 
	lea str_const_2(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
Label_8: 
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

