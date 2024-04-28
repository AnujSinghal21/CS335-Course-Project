.data
.globl main
.text
main: 
	pushq %rbp
	movq %rsp, %rbp
	subq $96, %rsp
	movq $1, %rbx
	movq %rbx, -8(%rbp)
	movq $2, %rbx
	movq %rbx, -16(%rbp)
	movq $2, %rbx
	movq %rbx, -24(%rbp)
Label_1: 
	movq -24(%rbp), %rbx
	movq $1, %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -32(%rbp)
	movq -32(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_4
	movq -8(%rbp), %rbx
	movq -16(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -40(%rbp)
	movq -40(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_2
	movq -8(%rbp), %rbx
	movq -16(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -48(%rbp)
	movq -48(%rbp), %rbx
	movq %rbx, -8(%rbp)
	jmp Label_3
Label_2: 
	movq -8(%rbp), %rbx
	movq $7, %rcx
	addq %rcx, %rbx
	movq %rbx, -56(%rbp)
	movq -56(%rbp), %rbx
	movq %rbx, -8(%rbp)
Label_3: 
	movq -24(%rbp), %rbx
	movq $1, %rcx
	subq %rcx, %rbx
	movq %rbx, -64(%rbp)
	movq -64(%rbp), %rbx
	movq %rbx, -24(%rbp)
	jmp Label_1
Label_4: 
	movq $0, %rbx
	movq %rbx, -72(%rbp)
Label_5: 
	movq $1, %rbx
	movq %rbx, -72(%rbp)
Label_6: 
	movq -72(%rbp), %rbx
	movq -8(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setl %dl
	movq %rdx, -80(%rbp)
	movq -80(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_7
	movq -24(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -88(%rbp)
	movq -88(%rbp), %rbx
	movq %rbx, -24(%rbp)
	movq -72(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -96(%rbp)
	movq -96(%rbp), %rbx
	movq %rbx, -72(%rbp)
	jmp Label_6
Label_7: 
	pushq -24(%rbp)
	call print_int
	addq $8, %rsp
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

