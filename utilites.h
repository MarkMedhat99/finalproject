#ifndef UTILITES_H_INCLUDED
#define UTILITES_H_INCLUDED


#define set_bit(Reg,bitno)  Reg = Reg | (1 << bitno)
#define clr_bit(Reg,bitno)  Reg = Reg & (~(1 << bitno))
#define tog_bit(Reg,bitno)  Reg = Reg ^ (1 << bitno)
#define get_bit(Reg,bitno)  (Reg >> bitno) & 1

#endif // UTILITES_H_INCLUDED
