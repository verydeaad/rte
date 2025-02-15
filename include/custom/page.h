#ifndef PAGE_H
#define PAGE_H

typedef struct Page {
  char *content;
  int index;
  int length;
  int size;

} Page;

void PageDeleteChar(Page *page);
Page PageCreate();
void PageAppend(Page *page, char c);
void PageUpdate(Page *page);

#endif
