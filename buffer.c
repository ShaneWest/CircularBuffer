/* 
    Shane West
    
    
    Circular Buffer 
*/
 
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
 
typedef char BufferType;
 
struct buffer {
        int size;
        int first;  // position of first element
        //int end;  // position of last element
        /* Tracking start and end of buffer would waste
         * one position. A full buffer would always have
         * to leave last position empty or otherwise
         * it would look empty. Instead this buffer uses
         * count to track if buffer is empty or full
         */
        int count; // number of elements in buffer
 
        /* Two ways to make buffer element type opaque
         * First is by using typedef for the element
         * pointer. Second is by using void pointer.
         */
        BufferType *elements;
};
 
void initBuffer(cb *cbptr, int size)
{
        cbptr->size = size;
        cbptr->count = 0;
        cbptr->first = 0; // could be anywhere actually
        cbptr->elements = malloc(size * sizeof(BufferType));
        printf("Buffer allocated\n");
}
 
int isFull(cb *cbptr)
{
        if (cbptr->count == cbptr->size) return TRUE;
        else return FALSE;
}
int isEmpty (cb *cbptr)
{
        return (cbptr->count == 0) ?  TRUE : FALSE;
}
 
void putBuffer(cb *cbptr, BufferType element)
{
        if (isFull(cbptr))
                return;
        cbptr->elements[(cbptr->first + cbptr->count++) % cbptr->size] = element;
        printf("Added %d\n", element);
        return;
}
 
BufferType fetchBuffer(cb *cbptr)
{
        if (isEmpty(cbptr))
                return 0;
        return (cbptr->elements[cbptr->first++ % cbptr->size]);
}