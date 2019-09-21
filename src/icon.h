#ifndef ICON_H
#define ICON_H

#include <windows.h>
#include <wchar.h>

typedef void* HICO;

//destroy icon object
void ico_delete(HICO hico);

//read bmp file to create icon object
//call ico_delete to free memory
HICO ico_load(const wchar_t *path);

//draw icon to device context
void ico_draw(HICO hico,HDC hdc,int x,int y);

#endif
