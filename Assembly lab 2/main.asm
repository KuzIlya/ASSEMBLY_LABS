.data
    array dd 2 dup (0)
.code
;-----------------------------------------------------------------------------------------------------------------------------------
Is_Prime proc
    ; extern "C" bool Is_Prime(int number)
    ; ����: �������� number - ECX
    ; �����: ��������� - � EAX (1, ���� �������, 0 - � ��������� ������)
    
    push rcx
    push rdx
    push r8

    mov r8d, 2

    cmp ecx, 1
    jle _not_prime

_while_div_less_num:
    cmp r8d, ecx ; r8 - ��������, ecx - �����
    jge _is_prime

    xor edx, edx    
    mov eax, ecx       ; �������� ����� � eax ��� �������
    div r8d            ; ����� eax �� r8, ��������� � eax, ������� � edx
    cmp edx, 0         ; ��������� �������
    jz _not_prime      ; ���� ������� ����� 0, �� ����� �� �������

    inc r8

    jmp _while_div_less_num

_not_prime:
    pop r8
    pop rdx
    pop rcx
    mov eax, 0
    ret

_is_prime:
    pop r8
    pop rdx
    pop rcx
    mov eax, 1
    ret

Is_Prime endp

;-----------------------------------------------------------------------------------------------------------------------------------
Goldbah_Problem proc
; extern "C" int *Goldbah_Problem(int number)
; number - RCX
; answer - RAX
    push rcx
    push r8
    push r9

    mov r8d, 2
    mov r9d, ecx

    _while_a1_less_number:
        cmp r8d, r9d
        jnl _end_while

        mov ecx, r8d
        call Is_Prime
        cmp al, 1
        je _a1_prime

        inc r8d
        jmp _while_a1_less_number
    
    _a1_prime:
        mov ecx, r9d
        sub ecx, r8d
        call Is_Prime
        cmp al, 1
        je _primes_found
        inc r8d
        jmp _while_a1_less_number

    _end_while:
        pop r9
        pop r8
        pop rcx
        ret

    _primes_found:
        mov array[0], r8d
        mov array[4], ecx
        lea rax, array
        jmp _end_while
        

Goldbah_Problem endp
;-----------------------------------------------------------------------------------------------------------------------------------
end