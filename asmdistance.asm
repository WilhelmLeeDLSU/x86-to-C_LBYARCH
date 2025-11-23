section .text
default rel
bits 64

global asmdistance
asmdistance:
    ;write your code here
   
    ; asmdistance(int n, double *x1, double *x2, double *y1, double *y2, double *z)
    ; n -> rcx
    ; mem x1 -> rdx
    ; mem x2 -> r8
    ; mem y1 -> r9
    ; mem y2 -> [rsp + 40]
    ; mem z -> [rsp + 48]
    
    MOV R10, [rsp + 40]
    MOV RAX, [rsp + 48]
    
    L1:
        MOVSD XMM0, [RDX] ; x1
        MOVSD XMM1, [R8] ; x2
        MOVSD XMM2, [R9] ; y1
        MOVSD XMM3, [R10] ; y2
        
        SUBSD XMM0, XMM1      ; (x1 - x2)
        MULSD XMM0, XMM0      ; (x1 - x2)^2
        
        SUBSD XMM2, XMM3      ; (y1 - y2)
        MULSD XMM2, XMM2      ; (y1 - y2)^2
        
        ADDSD XMM0, XMM2      ; sum of squares
        SQRTSD XMM0, XMM0     ; sqrt
        
        MOVSD [RAX], XMM0
        
        add RDX, 8
        add R8,  8
        add R9,  8
        add R10, 8
        add RAX, 8
        
    loop L1
          
    xor rax, rax
    ret