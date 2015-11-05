#include "t3f/t3f.h"
#include "t3f/ustring.h"

ALLEGRO_FONT * font = NULL;
char text[10][1024] = {{0}};

void logic(void * data)
{
}

void render(void * data)
{
	al_clear_to_color(al_map_rgba_f(0.0, 0.0, 0.0, 1.0));
	al_draw_text(font, al_map_rgba_f(1.0, 1.0, 1.0, 1.0), 0, 0, 0, text[0]);
	al_draw_text(font, al_map_rgba_f(1.0, 1.0, 1.0, 1.0), 0, 16, 0, text[1]);
	al_draw_text(font, al_map_rgba_f(1.0, 1.0, 1.0, 1.0), 0, 32, 0, text[2]);
}

int main(int argc, char * argv[])
{
	if(!t3f_initialize("ex_ustring", 640, 480, 60.0, logic, render, T3F_USE_KEYBOARD, NULL))
	{
		return 1;
	}
	font = al_create_builtin_font();
	if(!font)
	{
		return 1;
	}
	t3f_strcpy(text[0], "T³ Software", 1024);
	t3f_strcpy(text[1], text[0], 1024);
	t3f_strset(text[1], 2, '5', 1024);
	t3f_strcpy(text[2], text[1], 1024);
	t3f_strcat(text[2], " Presents", 1024);
	t3f_run();
	return 0;
}
