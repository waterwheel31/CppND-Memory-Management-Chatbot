#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;

    //std::cout << "GraphNode Constructor. Node:" <<  _id << " \n";

}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    //std::cout << "GraphNode Deconstructor. id:" <<  _id << " \n";

    /*
    std::cout << "deleting _chatBot from graphnode.cpp \n";
    if (_chatBot != nullptr){
        delete _chatBot; 
    }
    */

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    //std::cout << "GraphNode::AddEndgeToParentNode \n";
    _parentEdges.push_back(edge);
    //std::cout << "_parentEdges.size():" << _parentEdges.size() << "\n"; 
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    //std::cout << "GraphNode::AddEdgeToChildNode number of nodes: "<< _childEdges.size()  << "\n"; 
    
    _childEdges.push_back(std::move(edge));
    std::cout << "node: "<< _id << ", _childEdges.size():" << _childEdges.size() << "\n"; 
}


//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    //std::cout << "Chat bot moved to Node:" << _id << "\n";
    _chatBot = std::move(chatbot);
    // std::cout << "Chat bot moving complete: " << _id << "\n";
    _chatBot.SetCurrentNode(this);
    //std::cout << "MoveChatbotHere end: " << _id << "\n";
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}