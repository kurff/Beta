#include "gtest/gtest.h"
#include "mcts/tree.hpp"
using namespace Beta;
TEST(NodeTest, Allocate){
    Node<int>* node = new Node<int>("1");
    EXPECT_NE(node, nullptr);
    EXPECT_EQ(node->N(),0.0);
    EXPECT_EQ(node->P(),0.0);
    EXPECT_EQ(node->child().size(),0);
    EXPECT_EQ(node->parent().size(),0);
}

TEST(TreeTest, Allocate){
    Tree<int>* tree = new Tree<int>(1);
    EXPECT_NE(tree, nullptr);
    //EXPECT_EQ()
}

TEST(TreeTest, AddNode){
    Tree<int>* tree = new Tree<int>(0);
    Node<int>* node = new Node<int>("0");
    Node<int>* node1 = new Node<int>("1");
    tree->add_node(node);
    tree->add_node(node,node1);
    Node<int>* node2 = new Node<int>("2");
    tree->add_node(node, node2);
    tree->travel(node);

}


