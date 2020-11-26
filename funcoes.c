#include<funcoes.h>

float h_view_lo = -6.500000;
float h_view_hi = 6.500000;
float v_view_lo = -3.500000;
float v_view_hi = 3.500000;

int integral_steps = 1000;
int axis = 0;
int connectDots=0;


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
    axis = 0;
    connectDots=0;
}

void setHView(){
    scanf("%f:%f;",h_view_lo,h_view_hi);
}

void setVView(){
    scanf("%f:%f;",v_view_lo,v_view_hi);
}

void axisOn(){
    axis = 1;
}

void axisOff(){
    axis = 0;
}

void plotFunctio(){

}

void serIntegralSteps(){

}

void Integrate(){

}



void imprimeAbout(){
    printf("+----------------------------------------------+\n");
    printf("|                                              |\n");
    printf("|           DCMAT - CopyRight DC-UEL           |\n");
    printf("|                                              |\n");
    printf("+----------------------------------------------+\n\n");
}
