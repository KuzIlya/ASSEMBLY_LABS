
includelib kernel32.lib
extrn GetStdHandle:proc
extrn WriteFile:proc
extrn GetLastError:proc


.data
	text byte "123"
	len dd 3
	bytesWritten dword ?


.code

main proc
	sub  rsp, 40
	mov rcx, -11
	call GetStdHandle
	mov rcx, rax
	lea rdx, text
	mov r8d, len
	lea  r9, bytesWritten
	mov  qword ptr [rsp + 32], 0
	call WriteFile
	call GetLastError
	add  rsp, 40
main endp


end