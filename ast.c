#include <ast.h>
#include <sintatico.tab.h>

void RPN_Walk(TreeNode* aux){
	if(aux){
		RPN_Walk(aux->left);
		RPN_Walk(aux->right);
		switch(aux->node_type){
			case PLUS:{printf("+ ");};break;
			case MINUS:{printf("- ");};break;
			case ASTERIX:{printf("* ");};break;
			case DIV:{printf("/ ");};break;
			case REAL:{printf("%d ",aux->value);};break;
			default:{printf("ERROR: INVALID TYPE ");};break;
		}
	}
}

void Delete_Tree(TreeNode* aux){
	    if(aux)
    {
        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}

/*TreeNode* mallocTree(char type, float value){
	TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
	if(type == REAL){
		aux->node_type = REAL;
    	aux->value = value;
		
	}else if(type == PLUS || type == MINUS || type == DIV || type == ASTERIX){
		aux->node_type = type;
		aux->value = 0;
		
	}

	return aux;
}*/
