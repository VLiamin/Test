section .text
global compare
compare:
	;mov rsi, s1     ; esi = &s1
	;mov rdi, s2     ; edi = &s2
	xor rdx, rdx    ; edx = 0
loop:
	mov al, [rsi + rdx]
	mov bl, [rdi + rdx]
	inc rdx
	cmp al, bl  ; compare two current characters
	jne not_equal   ; not equal
	cmp al, 0       ; at end?
	je equal        ; end of both strings
	jmp loop        ; equal so far
not_equal:
	mov rdi, 1
	jmp exit
equal:
	mov rdi, 0
	jmp exit
exit:
	;mov rax, 0x2000001  ; sys_exit
	mov rax, rdi
    ret
section .data
s1: db "string one", 0
s2: db "string one", 0