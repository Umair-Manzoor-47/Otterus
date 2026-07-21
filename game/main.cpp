
#include <Editor.h>
#include "Flores.h"

int main() {
    editor::Editor editor;
    editor.SetGame(std::make_unique<Flores>());
    editor.Run();
    return 0;
}