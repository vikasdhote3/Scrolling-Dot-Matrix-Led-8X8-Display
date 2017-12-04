#ifndef __uart_init_h
#define __uart_init_h

#include "main.h"

void uart_init(void);
void uart_tx(unsigned char);
unsigned char uart_rx(void);
void uart_string(char *);


#endif
