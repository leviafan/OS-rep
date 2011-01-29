org 7c00h
xor ax,ax
mov es,ax
mov ax,0202h
mov cx,0002h
mov dx,0
mov bx,_2ndseg
int 13h

mov al,1
mov bx,1

jc cant_read

jmp _2ndseg
cant_read:
mov bp,errmess
mov cx,32
mov ah,13h
mov dx,0
int 10h
cli
hlt

errmess db "Can't read data from diskette"
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
NULL_DESCR	TIMES 8 db 0
CODE_DESCR  0FFh, 0FFh, 00h, 00h, 00h, 9Ah, 00h, 00h
VIDEO_DESCR  00h,  10h, 00h, 80h, 0Bh, 02h, 00h, 00h
tsize dw $-GDT
GDTR    dw tsize
        dd GDT
IDTR    dw 800h
        dd IDT

tend:
xor ax, ax
mov ds, ax
mov ss, ax
mov es, ax
sti

LLDT [CODE_DESCR] ;GP, here we go! 

