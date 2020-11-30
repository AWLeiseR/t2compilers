#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

#include <ast.h>

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
#endif 