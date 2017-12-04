#include "gtest/gtest.h"
#include "mcts/tree.hpp"
using namespace Beta;
TEST(NodeTest, Allocate){
    Node<int>* node = new Node<int>("1");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->N(),0.0);
    EXPECT_EQ(node->P(),0.0);
    EXPECT_EQ(node->child().size(),0);
    EXPECT_EQ(node->parent(),nullptr);
}

TEST(TreeTest, Allocate){
    Tree<int>* tree = new Tree<int>(1);
    EXPECT_NE(tree, nullptr);
    //EXPECT_EQ()
}

TEST(TreeTest, AddDeleteNode){
    Tree<int>* tree = new Tree<int>(0);
    Node<int>* node = new Node<int>("0");
    Node<int>* node1 = new Node<int>("1");
    tree->add_node(node);
    tree->add_node(node,node1);
    Node<int>* node2 = new Node<int>("2");
    Node<int>* node3 = new Node<int>("3");
    tree->add_node(node, node2);
    tree->add_node(node,node3);
    Node<int>* node4 = new Node<int>("4");
    Node<int>* node5 = new Node<int>("5");
    tree->add_node(node3,node4);
    tree->add_node(node, node5);
    tree->travel(node);
    DLOG(INFO)<< tree->size();
    tree->clear_node(node3);
    tree->clear_node(node5);
    DLOG(INFO)<< tree->size();
    tree->travel(node);
    tree->clear_node(node5);

}


