#pragma once
#include "GMLIB/GMLIB.h"


class GMLIB_NpcDialogueForm {
public:
    enum class NpcDialogueFormAction : int {
        Button = 0, // Button Mode
        Close  = 1, // Open Command
        Open   = 2  // Close Command
    };

public:
    GMLIB_API GMLIB_NpcDialogueForm(std::string npcName, std::string sceneName, std::string dialogue);

    GMLIB_NpcDialogueForm() = delete;

public:
    virtual ~GMLIB_NpcDialogueForm();

public:
    GMLIB_API int addAction(
        std::string              name,
        NpcDialogueFormAction    type     = NpcDialogueFormAction::Button,
        std::vector<std::string> commands = {}
    );

    GMLIB_API void
    sendTo(Player* pl, std::function<void(Player* pl, int index, NpcRequestPacket::RequestType type)> callback);
};