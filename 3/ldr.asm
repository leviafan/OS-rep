org 7c00h
xor ax,ax
mov es,ax
mov ax,0201h
mov cx,0002h
mov dx,0
mov bx,hello
int 13h

mov al,1
mov bx,1

jc cant_read

mov bp,hello
mov cx,16
mov ah,13h
mov dx,0
int 10h
jmp fin
cant_read:
mov bp,errmess
mov cx,34
mov ah,13h
mov dx,0
int 10h
fin:
cli
hlt

errmess db "Can't read sector from diskette"
 TIMES 510 - ($ - $$) db 0
 db 55h,0aah
hello db "Hello, world!"
 TIMES	1024 - ($ - $$) db 0
