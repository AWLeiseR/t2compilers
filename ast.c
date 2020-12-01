#include <ast.h>
#include <sintatico.tab.h>
#include <funcoes.h>

void RPN_Walk(TreeNode* aux){
	//treenode* aux = (treenode*) x ;
	
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
			case REAL:{printf("%f ",aux->value);};break;
			case SEN:{printf("SEN ");};break;
			case COS:{printf("COS ");};break;
			case TAN:{printf("TAN ");};break;
			case ABS:{printf("ABS ");};break;
			case VAR:{printf("x ");};break;
			default:{printf("ERROR: INVALID TYPE ");};break;
		}
	}
	
}

void Delete_Tree(TreeNode* aux){
	//treenode* aux = (treenode*) x;
	if(aux){
        Delete_Tree(aux->left);
        Delete_Tree(aux->right);
        free(aux);
    }
}

TreeNode* mallocTree(TreeNode* p1, TreeNode * p3, float value,int type){
	// treenode* p1 = (treenode*) x1;
	// treenode* p3 = (treenode*) x3;
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

float calcula(TreeNode* aux, float x){
	//treenode* aux = (treenode*) x1;
	if(aux){
		calcula(aux->left,x);
		calcula(aux->right,x);
		switch(aux->node_type){
			case PLUS:return calcula(aux->left,x) + calcula(aux->right,x);
			case MINUS:return calcula(aux->left,x) - calcula(aux->right,x);
			case ASTERIX:return calcula(aux->left,x) * calcula(aux->right,x);
			case DIV:return calcula(aux->left,x) * calcula(aux->right,x);
			case EXP:return pow( calcula(aux->left,x) , calcula(aux->right,x) );
			case PERCENT: return (int)calcula(aux->left,x) % (int)calcula(aux->right,x);
			case REAL:return aux->value;
			case VAR: return x;
			case SEN:return sin( calcula(aux->left,x) );
			case COS:return cos( calcula(aux->left,x) );
			case TAN:return tan( calcula(aux->left,x) );
			case ABS:return abs( calcula(aux->left,x) );
			default:return 0;
		}
	}else{
		return 0;
	}
	
}

void imprimeRpnFormat(TreeNode *tree){
	if(tree){
		printf("\nFunction in RPN format:\n\n");
	
		RPN_Walk(tree);
	}
	printf("\n>");
	
}

void alocaMatrix(TreeNode * tree){
	
	setLinha(0);
	setColuna(0);
	resetAuxColuna();
	limpaMatrix();
	percorreArvoreMatrix(tree);
	
	
}

void percorreArvoreMatrix(TreeNode * tree){
	if(tree){
		percorreArvoreMatrix(tree->left);
		percorreArvoreMatrix(tree->right);
		switch(tree->node_type){
			case R_BRACKET: break;
			case L_BRACKET: {setLinha(getLinha()+1); setColuna(0); }break;
			case REAL: {insertElementMatrix(getLinha(),getColuna(),tree->value);setAuxColuna(getColuna()+1);setColuna(getColuna()+1);} break;
			case COMMA:break;
			default: break;
		}
	}
}