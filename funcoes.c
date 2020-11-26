#include<funcoes.h>
#include<ast.h>

float h_view_lo = -6.500000;
float h_view_hi = 6.500000;
float v_view_lo = -3.500000;
float v_view_hi = 3.500000;

int integral_steps = 1000;
int axis = 1;
int connectDots = 0;

char grafico [25][80];
double matrix[10][10];

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

void printAxis(){
    
    int i,j;
    for(i=0;i<25;i++){
        for(j=0;j<80;j++){
            //printf("(%d,%d)",i,j);
            if(j==40){
                grafico[i][j]='|';
            }else if(i==13){
                grafico[i][j]='_';
            }else{
                grafico[i][j]=' ';
            }
            
        }
        //printf("\n");
    }

    for(i=0;i<25;i++){
        for(j=0;j<80;j++){
            
            printf("%c",grafico[i][j]);
            
            
        }
        printf("\n");
    }
}
void plotFunction(){
    
    printf("\n");
    printAxis();

}

void setIntegralSteps(float step){
    
    if(step > 0){
        integral_steps = (int)step;
    }else{
        printf("\nERROR: integral_steps must be a positive non-zero integer\n\n");
    }
    
}

void Integrate(float downLimit, float upLimit){

    if(downLimit < upLimit){
        
        int i;
        float base = (upLimit - downLimit) / integral_steps;
        float integral = 0;
        // for(i=0;i<integral_steps;i++){
        //     //integral=integral+funcao(downLimit+(i*base));
        // }
    
    }else{
        
        printf("\nERROR: lower limit must be smaller than upper limit\n\n");
    
    }
    
}



void imprimeAbout(){
    printf("+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|       201800560631 - Alan Willy Leiser       |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n\n");
}
