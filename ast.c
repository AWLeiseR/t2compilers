#include <ast.h>
#include <sintatico.tab.h>
#include <math.h>

void RPN_Walk(TreeNode* aux){
	if(aux){
		RPN_Walk(aux->left);
		RPN_Walk(aux->right);
		switch(aux->node_type){
			case PLUS:{printf("+ ");};break;
			case MINUS:{printf("- ");};break;
			case ASTERIX:{printf("* ");};break;
			case DIV:{printf("/ ");};break;
			case EXP:{printf("^ ");}break;
			case PERCENT: {printf("%% ");}break;
			case REAL:{printf("%d ",aux->value);};break;
			case SEN:{printf("SEN ");};break;
			case COS:{printf("COS ");};break;
			case TAN:{printf("TAN ");};break;
			case ABS:{printf("ABS ");};break;
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

TreeNode* mallocTree(TreeNode* p1, TreeNode * p3, float value,int type){
	TreeNode* aux = (TreeNode*)malloc(sizeof(struct node));
	if(type == REAL){
        aux->node_type = type;
        aux->value = value;
        aux->left = NULL;
        aux->right = NULL;   
    }else {
		aux->node_type = type;
    	aux->value = 0;
        aux->left = p1;
        aux->right = p3;   
    }

    return aux;
}

float calcula(TreeNode* aux){
	if(aux){
		calcula(aux->left);
		calcula(aux->right);
		switch(aux->node_type){
			case PLUS:return calcula(aux->left) + calcula(aux->right);
			case MINUS:return calcula(aux->left) - calcula(aux->right);
			case ASTERIX:return calcula(aux->left) * calcula(aux->right);
			case DIV:return calcula(aux->left) * calcula(aux->right);
			case EXP:return pow( calcula(aux->left) , calcula(aux->right) );
			case PERCENT: return (int)calcula(aux->left) % (int)calcula(aux->right);
			case REAL:return aux->value;
			case SEN:return sin( calcula(aux->left) );
			case COS:return cos( calcula(aux->left) );
			case TAN:return tan( calcula(aux->left) );
			case ABS:return abs( calcula(aux->left) );
			default:return 0;
		}
	}else{
		return 0;
	}
	
}