#ifndef IDT_H
#define IDT_H

struct IDT_entry{
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char      zero;
    unsigned char      type_attr;
    unsigned short     offset_higherbits;
}__attribute__((packed));


extern struct IDT_entry IDT[IDT_SIZE];

#endif