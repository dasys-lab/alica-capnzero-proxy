#include <alica_capnzero_proxy/Communication.h>
#include <engine/AlicaEngine.h>
#include <engine/containers/AllocationAuthorityInfo.h>
#include <engine/containers/EntryPointRobots.h>

#include <capnp/common.h>
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <kj/array.h>
#include <thread>


int main(int argc, char* argv[]) {
    alica::AlicaEngine* ae = NULL;
    essentials::IDManager* idManager = new essentials::IDManager();
    alica_capnzero_proxy::Communication *com = new alica_capnzero_proxy::Communication(*ae, *idManager);
    com->startCommunication();
    com->sendLogMessage(1, "Receiver test");
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}