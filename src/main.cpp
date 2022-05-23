#include "menu.h"

int main(int argc, char* argv[]) {
    Menu menu;
    int quit = false;
    
    while (!quit) {
        menu.draw();
        if (menu.MenuEventHandling()) quit = true;
    }

    return 0;
}