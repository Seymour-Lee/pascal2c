 
//  <�ļ���>��SymbolTable.h 
//  <�ļ�����>�����ļ���������ű���صĸ���Ķ��塣
//
//  <��������>��12/03/2017

#ifndef SymbolTable_h
#define SymbolTable_h

//  ����ͷ�ļ�
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdarg.h>

//  �����ռ�����
using namespace std;

//<����>��class SymbolType
//<�๦��˵��>��Ϊ�������Զ������͡������Ļ��࣬���еı�ʶ���������б���
class SymbolType
{
private:
    string name;		//����������Զ������͡�����������
    bool isReference; 	//���溯�������Ƿ�Ϊ���õ��ã�isReference=1Ϊ���õ���
public:
    SymbolType();
    void setReference();		//���ò���Ϊ���õ���
    bool getReference(); 
    void setName(string name);
    string getName();
    virtual bool find(string name){}
    //virtual void dynamic(){}
    virtual void insert(SymbolType* type){}		//�麯�����ڲ�ͬ�������в�ͬ�����ã������϶��������в���һ������
    virtual void setPrevious(SymbolType* previous){}	
    virtual SymbolType* getPrevious(){}					
};

//<����>��class Integer
//<�๦��˵��>����������Ϊint�ı���
class Integer :public SymbolType
{
public :
    Integer(){}
    Integer(string name);
};

//<����>��class Real
//<�๦��˵��>����������ΪReal�ı���
class Real :public SymbolType
{
public:
    Real(){}
    Real(string name);
};

//<����>��class Char
//<�๦��˵��>����������ΪChar�ı���
class Char :public SymbolType
{
public:
    Char(){}
    Char(string name);
};

//<����>��class Bool
//<�๦��˵��>����������ΪBool�ı���
class Bool:public SymbolType
{
public:
    Bool(){}
    Bool(string name);
};

//<����>��class Const
//<�๦��˵��>������Const���͵ĳ�����ʶ��
class Const :public SymbolType
{
private:
    SymbolType* type;	//����ͨ��ʶ���жϳ���Const������
public:
    Const();
    ~Const();
    void insert(SymbolType* type);	
    SymbolType* getType();
};

//<����>��class Record
//<�๦��˵��>������ṹ��������Ϣ
class Record :public SymbolType
{
private:
    vector<SymbolType*> content;	//����ṹ���еĳ�Ա
    SymbolType* previous;			//ָ�����ڲ����Աʱʹ�ã����Record�ĳ�Ա����Ƕ�׽ṹ��������������һ��������ָ��
public:
    Record();
    Record(string name);
    ~Record();
    bool find(string name);
    void insert(SymbolType* type);	//��Record�в����Ա����
    SymbolType* getType(string name);	//����һ������Ϊname�ĳ�Ա������ָ��
    void setPrevious(SymbolType* previous);	
    SymbolType* getPrevious();
};

//<����>��class Array
//<�๦��˵��>����������������Ϣ
class Array :public SymbolType
{
private:
    int dimension;	//?����ά��
    vector<int> length;	//?����ÿһά�ĳ���
    vector<char> head;	//?����ͷ
    SymbolType* type;   //��������
    SymbolType* previous;	//ָ�����ڲ����Աʱʹ�ã����Record�ĳ�Ա����Ƕ�׽ṹ��������������һ��������ָ��
public:
    Array();
    Array(string name);
    ~Array();
    int getDim();
    void setDim(int dimension);
    void setInfo(int length, char head);    //�������鵱ǰά���Ⱥ�ͷ
    void insert(SymbolType* type);          //�������������
    void setPrevious(SymbolType* previous); 
    int getLength(int location);
    char getHead(int location);
    SymbolType* getPrevious();
    SymbolType* getType(){return type;}     //�������������
};

//<����>��class Typedef
//<�๦��˵��>����type�����������
class Typedef :public SymbolType
{
private:
    SymbolType* type_def;   //type��������͵ľ������͵�ָ�룬Ҳ������һ��type
public:
    Typedef();
    Typedef(string name, SymbolType* type_def); 
    ~Typedef();
};

//<����>��class Function
//<�๦��˵��>�����溯������̵������Ϣ
class Function:public SymbolType
{
private:
    vector<SymbolType*> paraList;		//�����б�
    SymbolType* retType;		//����Ǻ�����retTypeΪ�����ķ���ֵ������Ϊnull
public:
    Function(string name);
    ~Function();
    void addPara(SymbolType* para);         //������б������һ������
    void setRetType(SymbolType* retType);   //���ú����ķ���ֵ
    SymbolType* getRetType();               
    bool findpara(string name);             //�жϲ����б����Ƿ����һ������Ϊname�Ĳ���
    int retParaNum();                       //���ز����ĸ���
    SymbolType* getParaType(string name);   //�õ�����Ϊname�Ĳ���������
    SymbolType* getParaType(int location);  //�õ��ڲ����б��е�location+1���������Ĳ���������
};

//<����>��class SymbolTable
//<�๦��˵��>�����ű����еı�ʶ��(�����������Զ�������)�������������ű���
//              ������ջʽ���ű�����ڲ�ѯʱ
class SymbolTable 
{
private:
    vector<SymbolType *> table;     //�����еı�ʶ�����������vector�У�ģ��ջʽ���ű�Ľṹ��vector��ĩβ��Ϊ�ڵ�ǰ����в������
    vector<int> ptr;	            //������table��ÿһ���¿鿪ʼ��λ��
public:
    SymbolTable();                  //��ʼ����0���뵽ptr�У���ʾ����Ŀ�ʼ
    static SymbolTable* getInstance();  //���õ���ģʽ
    void insert(SymbolType* type);  //����ű��в���һ���µı�ʶ��
    bool find(string name);         //�ڵ�ǰ���в�������Ϊname�ı�ʶ���Ƿ����
    bool isParaReference(string func_name,int location);       //�����������Ͳ���������λ�ã��жϸò����Ƿ�Ϊ���õ���
    bool isParaReference(int func_location,string para_name);  //�������������������Լ����������֣��жϸò����Ƿ�Ϊ���õ���
    bool find_in_global(string name);       //�ڵ�ǰ���ȫ��������Ϊname�ı�ʶ���Ƿ����
    SymbolType* getType(string name);       //��������Ϊname�ı�ʶ��������
    void reLocation();              //�ض�λ����
    void print();
};

#endif /* SymbolTable_h */

