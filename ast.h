#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct node TreeNode;

struct node{
	int node_type;
	float value;
	TreeNode* left;
	TreeNode* right;
	
};

void RPN_Walk(TreeNode* aux);
void Delete_Tree(TreeNode* auxx);
TreeNode* mallocTree(TreeNode* p1, TreeNode * p3, float value,int type);
float calcula(TreeNode* aux,float x);
void imprimeRpnFormat(TreeNode *tree);
void alocaMatrix(TreeNode * tree);
void percorreArvoreMatrix(TreeNode * tree);

#endif