#include "custom/page.h"
#include "raylib/raylib.h"
#include <stdio.h>
#include <stdlib.h>

void UncapAlphabetical(int *c) {
  if (!IsKeyDown(KEY_LEFT_SHIFT)) {
    c -= 32;
  }
}

void PageDeleteChar(Page *page) {
  if (page->index > 0) {
    page->index--; // moves back one letter
    page->content[page->index] = '\0';
    // turns the current letter into null, making the past letter
    // practically useless and the system could just rewrite it when we
    // need it
  }
}

Page PageCreate() {
  int size = 50;
  char *content = (char *)malloc(size * sizeof(char));
  content[0] = '\0';
  int index = 0;
  int length = 0;

  return (Page){
      .content = content, .index = index, .length = length, .size = size};
}

void PageAppend(Page *page, char c) { // haha dynamic
  if (page->index >= page->size - 1) {
    page->size *= 2;
    page->content =
        (char *)realloc((void *)page->content, page->size * sizeof(char));
    // there's a lot going on here
    // first (char *) is a cast to turn the memory into a pointer to a
    // character(character array) since allocation returns void pointers also
    // realloc takes void pointers as arguements, so we have to cast the page's
    // string to void before reallocating it the next arguement is just the size
    // of the reallocation, which is double the past size

  } else if (page->index > page->size) {
    printf("INDEX : %d, SIZE : %d\n", page->index, page->size);
    printf("PAGE INDEX(CURSOR) GREATER PAGE SIZE, EXITING..\n");
    exit(1);
  }

  if (page->index < page->size - 1) {
    page->content[page->index] = c;
    page->index++;
    page->length++;
    page->content[page->index] = '\0';
  }
}

void PageUpdate(Page *page) {
  int key = GetKeyPressed();
  if (key == KEY_BACKSPACE) {
    PageDeleteChar(page);
  } else if (key == KEY_ENTER) {
    PageAppend(page, '\n');
  } else if (key != 0) {
    UncapAlphabetical(&key);
    PageAppend(page, key);
  }
}
