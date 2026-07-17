
#include <Editor.h>
#include "Flores.h"
#include <entt/entt.hpp>

int main() {

    entt::registry sanityCheck;
    (void)sanityCheck;
    editor::Editor editor;
    editor.SetGame(std::make_unique<Flores>());
    editor.Run();
    return 0;
}