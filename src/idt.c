#include "idt.h"

struct IDT_entry IDT[IDT_SIZE];

void idt_init{
    unsigned long keyboard_address;
    unsigned long idt_address;
    unsigned long idt_ptr[2];

    // Populate IDT for Keyboard Interrupts
    keyboard_address = (unsigned long)keyboard_handler;
    IDT[0x21].offset_lowerbits = keyboard_address & 0xffff;
    IDT[0x21].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET
    IDT[0x21].zero = 0;
    IDT[0x21].type_attr = 0x8e; //INTERRUPT_GATE
    IDT[0x21].offset_higherbits = (keyboard_address & 0xffff0000) >> 16;
    
    /*
    * Ports
    *            PIC1    PIC2
    * Command    0x20    0xA0
    * Data       0x21    0xA1
    */

    //Begin Initialisation
    write_port(0x20, 0x11);
    write_port(0xA0, 0x11);
}