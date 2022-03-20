#ifndef LinkedList
#define LinkedList

typedef struct _element {
    char c;
    struct _element *next;
}ELEMENT, *EP;

void prtList(EP first);
EP newElement(char c);
void insertChar(char c, EP ptr);

#endif