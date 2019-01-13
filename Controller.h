//
//  <�ļ���>��Controller.h
//  <�ļ�����>�����ļ�������һ��Controller���࣬���ڿ��Ʊ������
//  <��������>��06/03/2017

#ifndef Controller_h
#define Controller_h

//  ����ͷ�ļ�
#include "AbstractSyntaxTree.h"
#include "SymbolTable.h"

//  <������>��Controller
//  <�๦������>���������ڿ��Ʊ�����̣���main������ʵ�������࣬��
//  ������ؽӿڡ�
class Controller{
public:
    Controller();//���캯��
    ~Controller();//��������
    
    void parsing(const char * fileName);//�ʷ����﷨����
    void typeChecking();//�������
    void codeGeneration(const char * fileName);//��������
    
private:
    //SymbolTable * symbolTable;
    
    Program * astRoot;//AST root node
    
};

#endif /* Controller_h */

