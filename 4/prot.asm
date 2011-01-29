org 7c00h
xor ax,ax
mov es,ax
mov ax,0204h
mov cx,0002h
mov dx,0
mov bx,_2ndseg
int 13h


jc cant_read
jmp _2ndseg
cant_read:
mov al,1
mov bx,1
mov bp,errmess
mov cx,32
mov ah,13h
mov dx,0
int 10h
cli
hlt

errmess db "Can't read data from diskette",0
protected db "Hello! I am #GP!",0
other db "Hello! I am not #GP (",0

TIMES 510 - ($ - $$) db 0
db 55h,0aah
_2ndseg:
cli
LGDT [GDTR]
LIDT [IDTR]
mov eax, cr0
or al, 1
mov cr0, eax

jmp 8:tend
GDT:
  TIMES 8 db 0
code  db 0FFh, 0FFh, 00h, 00h, 00h, 10011010b, 00h, 00h
      db  00h,  00h, 00h, 80h, 0Bh, 02h, 00h, 00h
tsize dw $-GDT
GDTR    dw tsize
        dd GDT
IDTR    dw 800h
        dd IDT

tend:
xor ax, ax
mov ds, ax
mov es, ax
mov di, ax
sti


	mov bx,0
	div bx
int 0Dh
;LLDT [code] ;GP, here we go! 
cli 
hlt
other_int:
	mov si, other
	mov cx,	22
	jmp cont
int_GP:
	mov si, protected
	mov cx, 17
cont:
	mov ax, 10h
	mov es, ax
	xor di, di
	mov ds, di
	mov	al, 02h
print:
	movsb
	stosb
	loop	print
_end:
cli
hlt
iret

times	1024 - ($ - $$) db 0
IDT:
  times 13  dw other_int, 8, 1000011000000000b, 0
            dw int_GP, 8, 1000011000000000b, 0
  times 242 dw other_int, 8, 1000011000000000b, 0
 
