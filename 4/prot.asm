org 7c00h
xor ax,ax
mov es,ax
mov ax,0201h
mov cx,0002h
mov dx,0
mov bx,_2ndseg
int 13h

mov al,1
mov bx,1

jc cant_read

jmp fine_readed
cant_read:
mov bp,errmess
mov cx,32
mov ah,13h
mov dx,0
int 10h
fine_readed:

cli
hlt
errmess db "Can't read data from diskette"
TIMES 510 - ($ - $$) db 0
db 55h,0aah
_2ndseg:
