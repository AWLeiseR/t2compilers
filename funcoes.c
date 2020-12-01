#include<funcoes.h>


float h_view_lo = -6.500000;
float h_view_hi = 6.500000;
float v_view_lo = -3.500000;
float v_view_hi = 3.500000;

int integral_steps = 1000;
int axis = 1;
int connectDots = 0;

char grafico [25][80];
double matrix[10][10];
double auxMatrix[10][10];
double L[10][10];
int linha,coluna, auxColuna;

int getLinha(){
    return linha;
}
void setLinha(int linha1){
    linha = linha1;
}

int getColuna(){
    return coluna;
}

void setColuna(int coluna1){
    coluna = coluna1;
}

void insertElementMatrix(int linha,int coluna,double element){
    
    matrix[linha][coluna]=element;
    
}

int getAuxColuna(){
    return auxColuna;
}

void setAuxColuna(int coluna){
    if(auxColuna < coluna)
        auxColuna = coluna;
}

void resetAuxColuna(){
    auxColuna = 1;
}

void imprimeSettings(){
    
    printf("h_view_lo: %f\n",h_view_lo);
    printf("h_view_hi: %f\n",h_view_hi);
    printf("v_view_lo: %f\n",v_view_lo);
    printf("v_view_hi: %f\n",v_view_hi);
    printf("integral_steps: %d\n\n",integral_steps);
    printf("Draw Axis: %s\n",axis?"ON":"OFF");
    printf("Connect Dots: %s\n\n",connectDots?"ON":"OFF");

}

void resetSettings(){

    h_view_lo = -6.500000;
    h_view_hi = 6.500000;
    v_view_lo = -3.500000;
    v_view_hi = 3.500000;

    integral_steps = 1000;
    axis = 1;
    connectDots = 0;

}

void setHView(float hviewlo, float hviewhi){
    
    if(hviewlo < hviewhi){
    
        h_view_lo = hviewlo;
        h_view_hi = hviewhi;  
    
    }else{
    
        printf("\nERROR: h_view_lo must be smaller than h_view_hi\n");
    
    }

}

void setVView(float vviewlo, float vviewhi){
    
    if(vviewlo < vviewhi){
    
        v_view_lo = vviewlo;
        v_view_hi = vviewhi;
    
    }else{
    
        printf("\nERROR: v_view_lo must be smaller than v_view_hi\n");
    
    }
    
}

void axisOn(){
    axis = 1;
}

void axisOff(){
    axis = 0;
}

void limpaGrafico(){
    int i,j;
    for(i=0;i<25;i++){
        for(j=0;j<80;j++){
            
            grafico[i][j] = ' '; 
            
        }
    
    }
}

void printAxis(float somaV,float pixelV,float somaH,float pixelH){
    
    int i,j,x,z;
    float auxV = v_view_lo, auxH = h_view_lo;

    i= (0 - auxV)/pixelV;
    j= (0 - auxH)/pixelH;

    if(i < 25 && i > 0){
        
        for(x=0;x<80;x++){
            grafico[i][x] = '-';
        }
    
    }
    
    if(j < 80 && j > 0 ){
        
        for(z=0;z<25;z++){
            grafico[z][j]='|';
    
        }
    }
    
    if(i < 25 && i > 0 && j < 80 && j > 0){
        grafico[i][j]= '+';
    }
    

    //printf("%d %d\n",i,j);

}

void imprimeGrafico(){
    int i,j;

    for(i=24;i>=0;i--){
        for(j=0;j<80;j++){
            
            printf("%c",grafico[i][j]);

        }
        printf("\n");
    }
}

void plotFunction(TreeNode * tree){
    int i,j,menor;
    
    float somaV=v_view_lo;
    float somaH=h_view_lo;
    
    float aux,aux1;

    float pixelH = (h_view_hi - h_view_lo) / 80;
    
    float pixelV = (v_view_hi - v_view_lo) / 25;
    
    printf("\n");
    limpaGrafico();
    if(axis){
       printAxis(somaV,pixelV,somaH,pixelH);
    }

    for(i=0;i<80;i++){
        
        aux = calcula(tree,somaH);
        
        //printf("%f\n",aux);

        menor = (int) floor((aux - somaV)/pixelV);
        
        if(menor>0 && menor < 25){
            grafico[menor][i] = '*';
        }
        
        somaH=h_view_lo + ( i * pixelH);
    }
    imprimeGrafico();

}

void setIntegralSteps(float step){
    
    if(step > 0){
        integral_steps = (int)step;
    }else{
        printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
    }
    
}

void integrate(TreeNode* tree,float downLimit, float upLimit){

    if(downLimit < upLimit){
        
        int i;
        float base = (upLimit - downLimit) / integral_steps;
        printf("down -> %f up -> %f base ->%f ",downLimit,upLimit,base);
        float integral = 0;
        for(i=0;i<integral_steps;i++){
            
            integral=integral+calcula(tree,downLimit+(i*base))*base;
        }
        printf("\n\n%f\n\n",integral);
    }else{
        
        printf("\nERROR: lower limit must be smaller than upper limit\n\n");
    
    }
    
}

void imprimeCabecalho(){
    int i, espacos=(auxColuna*17)+1;
    
    printf("+-");
    for(i=0;i<espacos;i++){
        printf(" ");
    }
    printf("-+\n");
}

void limpaMatrix(){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			matrix[i][j]=0;
		}
	}
}

void imprimeMatrix(){
    int i,j;
    printf("\n");
    imprimeCabecalho();
    for(i = 0; i < linha; i++){
        printf("| ");
        for(j = 0; j < auxColuna; j++){
            printf(" %.10e",matrix[i][j]);
        }
        printf("  |\n");
    }
    imprimeCabecalho();
    printf("\n");
}

void calculaLU(){
    int i,j,y;
	float pivo;

	for(i=0;i<auxColuna;i++){
		L[i][i]=1;
	}

	for(j=0;j<auxColuna-1;j++){//anda coluna

		pivo=auxMatrix[j][j];//pivo diagonal principal
		
		for(y=1+j;y<linha;y++){//anda linha
			
				L[y][j] = auxMatrix[y][j]/pivo; // multiplicador
				
				for(i=0;i<auxColuna;i++){//percorre as colunas da linha
					
				 	auxMatrix[y][i] -= L[y][j]*auxMatrix[j][i];
				
				}
		}
	}
    
}

void transferirMatrix(){
    int i,j;
    
    for(i=0;i<linha;i++){
        for(j=0;j<auxColuna;j++){
            auxMatrix[i][j]=matrix[i][j];
        }
    }
}

void calculaDeterminante(){
    int i, j;
    float det=1;
    if(linha == auxColuna){
        if(linha==1){

            det=matrix[0][0];
        
        }else if(linha == 2){
          
            det=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        
        }else{
            
            transferirMatrix();
            calculaLU();
            for(i=0;i<auxColuna;i++){
                det = det*auxMatrix[i][i];
            }
        
        }
        
        printf("\n\n%f\n\n",det);
    }else{
        printf("\n\nMatrix format incorrect!\n\n");
    }
    
}

void resolveSistemaLinear(){
    if(linha == auxColuna +1 ){

    }else{
        printf("\n\nMatrix format incorrect!\n\n");
    }
}

void imprimeAbout(){
    printf("+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|       201800560631 - Alan Willy Leiser       |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n\n");
}
