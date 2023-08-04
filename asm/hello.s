.text
    .file   "main.c"
    .globl  main                            // -- Begin function main
    .p2align    2

.type   main,@function
main:                                   // @main
// %bb.0:
    sub sp, sp, #32                     // =32
    stp x29, x30, [sp, #16]             // 16-byte Folded Spill
    add x29, sp, #16                    // =16
    mov w8, wzr
    stur    wzr, [x29, #-4]
    adrp    x0, .L.str
    add x0, x0, :lo12:.L.str
    str w8, [sp, #8]                    // 4-byte Folded Spill
    bl  printf
    ldr w8, [sp, #8]                    // 4-byte Folded Reload
    mov w0, w8
    ldp x29, x30, [sp, #16]             // 16-byte Folded Reload
    add sp, sp, #32                     // =32
    ret
