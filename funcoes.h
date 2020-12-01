#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

#include <ast.h>

int getLinha();
void setLinha(int linha1);
int getColuna();
void setColuna(int coluna1);
void insertElementMatrix(int linha,int coluna,double element);
int getAuxColuna();
void setAuxColuna(int coluna);
void resetAuxColuna();
void imprimeSettings();
void imprimeAbout();
void resetSettings();
void setHView(float hviewlo, float hviewhi);
void setVView(float vviewlo, float vviewhi);
void axisOn();
void axisOff();
void plotFunction();
void setIntegralSteps(float step);
void integrate(TreeNode* tree,float downLimit, float upLimit);
void limpaMatrix();
void imprimeMatrix();
void calculaDeterminante();
#endif 