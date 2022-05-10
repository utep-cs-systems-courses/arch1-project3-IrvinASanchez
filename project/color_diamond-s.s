    .arch msp430g2553
    .p2align 1,0
    .text
    
    .extern drawDiamond
    .extern color

jmp_table:
    .word case0 ;yello diamond
    .word case1 ;purple diamond
    .word case2 ;green diamond
    .word case3 ;hot pink diamond
    
    .global color_diamond
color_diamond:
    mov.b &color, r12
    add.b r12, r12
    mov jmp_table(r12), r0
    
case0:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0x07ff, r14 ;yellow
    call #draw_diamond
    add.b #1, &color
    jmp end

case1:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0xf114, r14 ;purple
    call #draw_diamond
    add.b #1, &color
    jmp end
    
case2:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0x07e0, r14 ;green
    call #draw_diamond
    add.b #1, &color
    jmp end
    
case3:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0xb35f, r14 ;hot pink
    call #draw_diamond
    mov.b #0, &color
    jmp end

end: 
    pop r0
    
    
