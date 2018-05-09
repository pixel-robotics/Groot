#ifndef XMLPARSERS_HPP
#define XMLPARSERS_HPP

#include "tinyXML2/tinyxml2.h"

#include <nodes/Node>
#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/DataModelRegistry>

bool ReadTreeNodesModel(QtNodes::DataModelRegistry& registry, const tinyxml2::XMLElement* model_root);

//--------------------------------------------------------

const QString gTestXML = R"(

<root main_tree_to_execute = "MainTree" >

    <BehaviorTree ID="MainTree">
        <Fallback name="root_selector">

            <Sequence name="door_open_sequence">
                <Action ID="IsDoorOpen" />
                <Action ID="PassThroughDoor" />
            </Sequence>

            <Sequence name="door_closed_sequence">
                <Decorator ID="Negation">
                     <Action ID="IsDoorOpen" />
                </Decorator>
                <Action ID="OpenDoor" />
                <Action ID="PassThroughDoor" />
                <Action ID="CloseDoor" />
            </Sequence>

            <Action ID="PassThroughWindow" />

        </Fallback>
    </BehaviorTree>

    <!-- TreeNodesModel is used only by the Graphic interface -->
    <TreeNodesModel>
        <Action ID="IsDoorOpen" />
        <Action ID="PassThroughDoor" />
        <Action ID="CloseDoor" />
        <Action ID="OpenDoor" />
        <Action ID="PassThroughWindow" />
        <Decorator ID="Invert" />
        <Decorator ID="RetryUntilSuccesful">
            <Parameter label="num_attempts" type="Int" />
        </Decorator>
        <Decorator ID="Repeat">
            <Parameter label="num_cycles" type="Int" />
        </Decorator>
    </TreeNodesModel>
</root>
        )";


#endif // XMLPARSERS_HPP
