.data
.globl main
.text
func1: 
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq -8(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -16(%rbp)
	movq $0, %rbx
	movq -16(%rbp), %rcx
	movq %rbx, (%rcx)
	movq $0, %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	movq %rbp, %rsp
	popq %rbp
	ret
func2: 
	pushq %rbp
	movq %rsp, %rbp
	subq $72, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq -8(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -16(%rbp)
	movq -16(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -24(%rbp)
	pushq -24(%rbp)
	call print_int
	addq $8, %rsp
	movq $0, %rbx
	movq %rbx, -32(%rbp)
	movq 16(%rbp), %rbx
	movq -32(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -40(%rbp)
	movq $0, %rbx
	movq %rbx, -48(%rbp)
	movq 16(%rbp), %rbx
	movq -48(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -56(%rbp)
	movq -56(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -64(%rbp)
	movq -64(%rbp), %rbx
	movq $1, %rcx
	addq %rcx, %rbx
	movq %rbx, -72(%rbp)
	movq -72(%rbp), %rbx
	movq -40(%rbp), %rcx
	movq %rbx, (%rcx)
	movq 16(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	movq %rbp, %rsp
	popq %rbp
	ret
main: 
	pushq %rbp
	movq %rsp, %rbp
	subq $72, %rsp
	movq %rbp, %rbx
	addq $-16, %rbx
	movq %rbx, -8(%rbp)
	movq $8, -8(%rbx)
	pushq -8(%rbp)
	call func1
	addq $8, %rsp
	movq -8(%rbp), %rbx
	movq %rbx, -32(%rbp)
	movq $0, %rbx
	movq %rbx, -40(%rbp)
	movq -32(%rbp), %rbx
	movq -40(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -48(%rbp)
	movq $10, %rbx
	movq -48(%rbp), %rcx
	movq %rbx, (%rcx)
	pushq -32(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -56(%rbp)
	pushq -32(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -64(%rbp)
	pushq -32(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -72(%rbp)
	movq $0, %rax
	movq %rbp, %rsp
	popq %rbp
	ret
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

