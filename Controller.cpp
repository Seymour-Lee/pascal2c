//
//  <�ļ���>��Controller.cpp 
//  <�ļ�����>�����ļ�ʵ����Controller������Գ�Ա����
//  <��������>��06/03/2017

//  ����ͷ�ļ�
#include <iostream>
#include <stdio.h>

#include "Controller.h" 
#include "syntax.tab.h"

//  ����syntax.y�е�ȫ�ֱ��� 
extern FILE * yyin;
extern int yyparse (Program **astRoot);

//
//  <������>��Controller::Controller()
//  <��������˵��>���ú���ΪController��Ĺ��캯�� 
Controller::Controller(){
    astRoot=NULL;
    //symbolTable=NULL;
}

//
//  <������>��Controller::~Controller()
//  <��������˵��>���ú���ΪController�����������
Controller::~Controller(){
    //std::cout<<"deleting Controller"<<std::endl;
    if(astRoot == NULL) delete astRoot;
    
    //delete the AST using back-traversing
}

//
//  <������>��Controller::parsing(const char * fileName)
//  <��������˵��>���ú������ôʷ����﷨������������
//  �������޷����ԵĴ������﷨����δ���ɸ��ڵ㣬�����ֹͣ 
void Controller::parsing(const char * fileName){
    if(!(yyin=std::fopen(fileName, "r")))
    	std::cout<<"δ����Դ�ļ�������������з�ʽ���У�"<<std::endl; 
    //call yyparse();
    //std::cout<<(yyin==NULL);
    else
    {
    	std::cout<<"���ڱ���Դ�ļ���"<<fileName<<"\n";
	    yyparse(&this->astRoot); 
	    if(this->astRoot==NULL)
	    	std::cout<<"\n\n��1���ʷ����﷨������ɣ����ִ��󣬷���ֹͣ�����޸�Դ�ļ���\n\n";
		else 
			std::cout<<"\n\n��1���ʷ����﷨������ɣ�\n\n";
    }
}

//
//  <������>��Controller::typeChecking()
//  <��������˵��>���ú����������ͼ�麯������
void Controller::typeChecking(){
    //traverse the AST to check the type-righting
    if(astRoot) {
		this->astRoot->checkType();
    	//std::cout<<"\n���������ɡ�\n\n";
	} 
        
}

//
//  <������>��Controller::codeGeneration()
//  <��������˵��>���ú������ô������ɺ�������
void Controller::codeGeneration(const char * fileName){
    //call this function after parsing();
    //deal with the AST to print the c-code
    if(astRoot) {
    	char *outName=new char[strlen(fileName)+1];
		strcpy(outName,fileName);
	    //std::cout<<strtok(pureName,".");
	    if(strtok(outName,".")!=NULL)
	    	outName=strcat(strtok(outName,"."),".c");
	    else 
	    	outName=strcat(outName,".c");
	    this->astRoot->printCodes(outName);
	    std::cout<<"\n\n��3��C����������ɣ������"<<outName<<"\n\n";
	} 
}


