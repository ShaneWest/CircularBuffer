#ifndef buffer_h
#define buffer_h
 
void initBuffer(cb * cb_ptr, int size);
void putBuffer(cb *cb_ptr, BufferType element);
BufferType fetchBuffer(cb *cb_ptr);
int isEmpty(cb *cb_ptr);
int isFull(cb *cb_ptr);

#endif