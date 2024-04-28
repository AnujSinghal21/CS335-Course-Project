.data
str_const_1: .asciz "rectangle1 area"
str_const_2: .asciz "rectangle2 area"
str_const_3: .asciz "rectangle1 has larger area"
str_const_4: .asciz "Both has same area"
str_const_5: .asciz "rectangle1 has smaller area"
str_const_6: .asciz "rectangle1 perimeter"
str_const_7: .asciz "rectangle2 perimeter"
str_const_8: .asciz "rectangle1 has larger perimeter"
str_const_9: .asciz "Both has same perimeter"
str_const_10: .asciz "rectangle1 has smaller perimeter"
.globl main
.text
func1: 
	pushq %rbp
	movq %rsp, %rbp
	subq $32, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq -8(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -16(%rbp)
	movq 24(%rbp), %rbx
	movq -16(%rbp), %rcx
	movq %rbx, (%rcx)
	movq $8, %rbx
	movq %rbx, -24(%rbp)
	movq 16(%rbp), %rbx
	movq -24(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -32(%rbp)
	movq 32(%rbp), %rbx
	movq -32(%rbp), %rcx
	movq %rbx, (%rcx)
	movq %rbp, %rsp
	popq %rbp
	ret
func2: 
	pushq %rbp
	movq %rsp, %rbp
	subq $56, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq -8(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -16(%rbp)
	movq $8, %rbx
	movq %rbx, -24(%rbp)
	movq 16(%rbp), %rbx
	movq -24(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -32(%rbp)
	movq -16(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -40(%rbp)
	movq -32(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -48(%rbp)
	movq -40(%rbp), %rbx
	movq -48(%rbp), %rcx
	imulq %rcx, %rbx
	movq %rbx, -56(%rbp)
	movq -56(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	movq %rbp, %rsp
	popq %rbp
	ret
func3: 
	pushq %rbp
	movq %rsp, %rbp
	subq $64, %rsp
	movq $0, %rbx
	movq %rbx, -8(%rbp)
	movq 16(%rbp), %rbx
	movq -8(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -16(%rbp)
	movq $8, %rbx
	movq %rbx, -24(%rbp)
	movq 16(%rbp), %rbx
	movq -24(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -32(%rbp)
	movq -16(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -40(%rbp)
	movq -32(%rbp), %rbx
	movq (%rbx), %rcx
	movq %rcx, -48(%rbp)
	movq -40(%rbp), %rbx
	movq -48(%rbp), %rcx
	addq %rcx, %rbx
	movq %rbx, -56(%rbp)
	movq $2, %rbx
	movq -56(%rbp), %rcx
	imulq %rcx, %rbx
	movq %rbx, -64(%rbp)
	movq -64(%rbp), %rax
	movq %rbp, %rsp
	popq %rbp
	ret
	movq %rbp, %rsp
	popq %rbp
	ret
main: 
	pushq %rbp
	movq %rsp, %rbp
	subq $176, %rsp
	movq %rbp, %rbx
	addq $-24, %rbx
	movq %rbx, -8(%rbp)
	movq $16, -8(%rbx)
	pushq $10
	pushq $5
	pushq -8(%rbp)
	call func1
	addq $24, %rsp
	movq -8(%rbp), %rbx
	movq %rbx, -40(%rbp)
	movq %rbp, %rbx
	addq $-64, %rbx
	movq %rbx, -48(%rbp)
	movq $16, -8(%rbx)
	pushq $12
	pushq $4
	pushq -48(%rbp)
	call func1
	addq $24, %rsp
	movq -48(%rbp), %rbx
	movq %rbx, -80(%rbp)
	lea str_const_1(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	pushq -40(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -88(%rbp)
	movq -88(%rbp), %rbx
	movq %rbx, -96(%rbp)
	pushq -96(%rbp)
	call print_int
	addq $8, %rsp
	lea str_const_2(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	pushq -80(%rbp)
	call func2
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -104(%rbp)
	movq -104(%rbp), %rbx
	movq %rbx, -112(%rbp)
	pushq -112(%rbp)
	call print_int
	addq $8, %rsp
	movq -96(%rbp), %rbx
	movq -112(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -120(%rbp)
	movq -120(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_1
	lea str_const_3(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	jmp Label_4
Label_1: 
	movq -96(%rbp), %rbx
	movq -112(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -128(%rbp)
	movq -128(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_2
	lea str_const_4(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	jmp Label_3
Label_2: 
	lea str_const_5(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
Label_3: 
Label_4: 
	lea str_const_6(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	pushq -40(%rbp)
	call func3
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -136(%rbp)
	movq -136(%rbp), %rbx
	movq %rbx, -144(%rbp)
	pushq -144(%rbp)
	call print_int
	addq $8, %rsp
	lea str_const_7(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	pushq -80(%rbp)
	call func3
	addq $8, %rsp
	movq %rax, %rbx
	movq %rbx, -152(%rbp)
	movq -152(%rbp), %rbx
	movq %rbx, -160(%rbp)
	pushq -160(%rbp)
	call print_int
	addq $8, %rsp
	movq -144(%rbp), %rbx
	movq -160(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	setg %dl
	movq %rdx, -168(%rbp)
	movq -168(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_5
	lea str_const_8(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	jmp Label_8
Label_5: 
	movq -144(%rbp), %rbx
	movq -160(%rbp), %rcx
	movq $0, %rdx
	cmpq %rcx, %rbx
	sete %dl
	movq %rdx, -176(%rbp)
	movq -176(%rbp), %rbx
	testq %rbx, %rbx
	jz Label_6
	lea str_const_9(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
	jmp Label_7
Label_6: 
	lea str_const_10(%rip), %r8
	pushq %r8
	call print_string
	addq $8, %rsp
Label_7: 
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

