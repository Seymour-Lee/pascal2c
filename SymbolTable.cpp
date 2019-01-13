 
//  <�ļ���>��SymbolTable.cpp 
//  <�ļ�����>�����ļ���������ű���صĸ����ʵ�֡�
//
//  <��������>��12/03/2017

//  ����ͷ�ļ�
#include "SymbolTable.h"

//  <������>��SymbolType::SymbolType()
//  <��������˵��>�����캯����
SymbolType::SymbolType()
{
	this->isReference=0;
}

//  <������>��void SymbolType::setReference()
//  <��������˵��>�����ò���Ϊ���õ���
void SymbolType::setReference()
{
	this->isReference=1;
}

//  <������>��bool SymbolType::getReference()
//  <��������˵��>���õ�ĳ����Ϊ���õ��û��Ǵ�ֵ����
bool SymbolType::getReference()
{
	return this->isReference;
}

//  <������>��void SymbolType::setName(string name)
//  <��������˵��>�����øñ�ʶ��������
void SymbolType::setName(string name)
{
    this->name = name;
}

//  <������>��string SymbolType::getName()
//  <��������˵��>���õ��ñ�ʶ��������
string SymbolType::getName()
{
    return name;
}

//  <������>��Integer::Integer(string name)
//  <��������˵��>�����캯��
Integer::Integer(string name)
{
    setName(name);
}

//  <������>��Real::Real(string name)
//  <��������˵��>�����캯��
Real::Real(string name)
{
    setName(name);
}

//  <������>��Char::Char(string name)
//  <��������˵��>�����캯��
Char::Char(string name)
{
    setName(name);
}

//  <������>��Bool::Bool(string name)
//  <��������˵��>�����캯��
Bool::Bool(string name)
{
    setName(name);
}

//  <������>��Const::Const()
//  <��������˵��>�����캯��
Const::Const()
{
	this->type==NULL;
}

//  <������>��Const::~Const()
//  <��������˵��>������������ɾ��ָ��Const�������͵�ָ��
Const::~Const()
{
	delete this->type;
}

//  <������>��void Const::insert(SymbolType* type)
//  <��������˵��>���������﷨�������õ������͸���Const
void Const::insert(SymbolType* type)
{
    this->type = type;
}

//  <������>��SymbolType* Const::getType()
//  <��������˵��>���õ�Const�ľ�������
SymbolType* Const::getType()
{
	return this->type;
}

//  <������>��Record::Record()
//  <��������˵��>�����캯��
Record::Record()
{
	this->previous=NULL;
}

//  <������>��Record::Record(string name)
//  <��������˵��>�����캯��
Record::Record(string name)
{
	this->previous=NULL;
    setName(name);
}

//  <������>��Record::~Record()
//  <��������˵��>������������ɾ��ָ��Record�ĳ�Ա��ָ�룬�����Ա�д���Record��array
//	��Ƕ�׽ṹ��ɾ��ָ���丸�ڵ��ָ��previous
Record::~Record()
{
    if (!content.empty())
    {
    	for (int i = 0;i<content.size();i++)
        {
            delete content.at(i);
        }
	}
	if(previous!=NULL)
		delete previous;
}

//  <������>��void Record::insert(SymbolType* type)
//  <��������˵��>����Record�в���һ����Ա
void Record::insert(SymbolType* type)
{
    content.push_back(type);
}

//  <������>��SymbolType* Record::getType(string name)
//  <��������˵��>����Record�еõ�����Ϊname�ĳ�Ա������ָ��
SymbolType* Record::getType(string name)
{
    for (int i = 0;i<content.size();i++)
    {
        if (content.at(i)->getName() == name)
            return content.at(i);
    }
    return NULL;
}

//  <������>��void Record::setPrevious(SymbolType* previous)
//  <��������˵��>�����Record�к���Ƕ�׵ĸ������Խṹ����record��
//	array������Ҫ��¼�丸�ڵ㣬Ҳ�����������ڵ�Record��ָ�룬��������
void Record::setPrevious(SymbolType* previous)
{
    this->previous = previous;
}

//  <������>��SymbolType* Record::getPrevious()
//  <��������˵��>���õ�ĳһ����ֵ�ĸ��ڵ�
SymbolType* Record::getPrevious()
{
    return previous;
}

bool Record::find(string name)
{
	for(int i=0;i<content.size();i++)
	{
		if(content.at(i)->getName()==name)
			return true;
		
	}
	return false;
}

//  <������>��Array::Array()
//  <��������˵��>�����캯����
Array::Array()
{
	this->previous=NULL;
	this->type=NULL;
}

//  <������>��Array::Array(string name)
//  <��������˵��>�����캯��
Array::Array(string name)
{
	this->previous=NULL;
	this->type=NULL;
    setName(name);
    dimension = 0;
}

//  <������>��Array::~Array()
//  <��������˵��>������������ɾ�����ܴ��ڵĸ��ڵ�ָ��
//	�Լ���array������ָ��
Array::~Array()
{
	if(previous!=NULL)
		delete previous;
	if(type!=NULL)
   	 	delete type;
   
}

//  <������>��int Array::getDim()
//  <��������˵��>���õ������ά��
int Array::getDim()
{
    return dimension;
}

//  <������>��void Array::setDim(int dimension)
//  <��������˵��>�����������ά��
void Array::setDim(int dimension)
{
    this->dimension = dimension;
}

//  <������>��void Array::setInfo(int length, char head)
//  <��������˵��>���������鵱ǰά���Ⱥ�ͷ
void Array::setInfo(int length, char head)
{
    this->length.push_back(length);
    this->head.push_back(head);
}

//  <������>��void Array::insert(SymbolType* type)
//  <��������˵��>���������������

void Array::insert(SymbolType* type)
{
    this->type = type;
}

//  <������>��void Array::setPrevious(SymbolType* previous)
//  <��������˵��>����Record���ƣ�������Ƕ������ʱ����¼�丸�ڵ�
void Array::setPrevious(SymbolType* previous)
{
    this->previous = previous;
}

//  <������>��void Array::getHead(int location)
//  <��������˵��>����������ÿһά����Ԫ�� 
char Array::getHead(int location)
{
	return this->head.at(location);
}

//  <������>��void Array::getLength(int location)
//  <��������˵��>����������ÿһά�ĳ��� 
int Array::getLength(int location)
{
	return this->length.at(location);   
}


//  <������>��SymbolType* Array::getPrevious()
//  <��������˵��>���õ�Ƕ�����͵ĸ��ڵ�
SymbolType* Array::getPrevious()
{
    return previous;
}

//  <������>��Typedef::Typedef()
//  <��������˵��>�����캯��
Typedef::Typedef()
{
	this->type_def=NULL;
}

//  <������>��Typedef::Typedef(string name, SymbolType* type_def)
//  <��������˵��>������type��������͵����֣��Լ��䶨������ͣ�������
//	����Ϊ��Function�������������
Typedef::Typedef(string name, SymbolType* type_def)
{
    setName(name);
    this->type_def = type_def;
}

//  <������>��Typedef::~Typedef()
//  <��������˵��>����������
Typedef::~Typedef()
{
    delete type_def;
}

//  <������>��Function::Function(string name)
//  <��������˵��>�����캯��
Function::Function(string name)
{
    this->setName(name);
    retType = NULL;
}

//  <������>��Function::~Function()
//  <��������˵��>������������ɾ����������̿����е����в���
//	���ں�����ɾ���䷵��ֵ
Function::~Function()
{
    if (!paraList.empty())
    {
        for (int i = 0;i < paraList.size();i++)
        {
            delete paraList.at(i);
        }
    }
    if (retType != NULL)
    {
        delete retType;
    }
}

//  <������>��void Function::addPara(SymbolType* para)
//  <��������˵��>����ú��������һ������
void Function::addPara(SymbolType* para)
{
    if (para == NULL)
        return;
    paraList.push_back(para);
}

//  <������>��void Function::setRetType(SymbolType* retType)
//  <��������˵��>�����ú����ķ���ֵ
void Function::setRetType(SymbolType* retType)
{
    if (retType == NULL)
        return;
    this->retType = retType;
}

//  <������>��SymbolType* Function::getRetType()
//  <��������˵��>���õ������ķ���ֵ
SymbolType* Function::getRetType()
{
    return retType;
}

//  <������>��bool Function::findpara(string name)
//  <��������˵��>���жϲ����б����Ƿ����һ������Ϊname�Ĳ���
bool Function::findpara(string name)
{
    if (paraList.empty())
        return false;
    for (int i = 0;i < paraList.size() ;i++)
    {
        if (paraList.at(i)->getName() == name)
            return true;
    }
    return false;
}

//  <������>��int Function::retParaNum()
//  <��������˵��>�����ز����ĸ���
int Function::retParaNum()
{
	if(!paraList.empty())
    	return paraList.size();
}

//  <������>��SymbolType* Function::getParaType(string name)
//  <��������˵��>���õ�����Ϊname�Ĳ���������
SymbolType* Function::getParaType(string name)
{
    if (paraList.empty())
        return NULL;
    for (int i = 0;i < paraList.size();i++)
    {
        if (paraList.at(i)->getName() == name)
            return paraList.at(i);
    }
    return NULL;
}

//  <������>��SymbolType* Function::getParaType(int location)
//  <��������˵��>���õ��ڲ����б��е�location+1���������Ĳ���������
SymbolType* Function::getParaType(int location)
{
    if (paraList.empty())
        return NULL;
    return paraList.at(location);
}

//  <������>��SymbolTable::SymbolTable()
//  <��������˵��>�����캯�������������Ŀ�ʼλ����Ϊ0�����뵽ָ��
//	�鿪ʼλ�õ�ptr��
SymbolTable::SymbolTable()
{
    ptr.push_back(0);
}

//  <������>��SymbolTable* SymbolTable::getInstance()
//  <��������˵��>������ģʽ������SymbolTable* ���͵�ָ���Ե��ú���
SymbolTable* SymbolTable::getInstance()
{
    static SymbolTable* symbolTable = new SymbolTable();
    return symbolTable;
}

//  <������>��void SymbolTable::insert(SymbolType* type)
//  <��������˵��>������ű��в���һ������Ϊtype�ı�ʶ����
void SymbolTable::insert(SymbolType* type)
{
    table.push_back(type);
    if (dynamic_cast<Function *>(type)!=NULL)
        ptr.push_back(table.size() - 1);
}

//  <������>��bool SymbolTable::find(string name)
//  <��������˵��>���ڵ�ǰ���в�������Ϊname�ı����Ƿ����
//	������ӿ��У������Ĳ���ҲҪ���ң�
bool SymbolTable::find(string name)
{
	if(table.size()==0)
		return false;
    for (int i = table.size() - 1;i >= ptr.at(ptr.size()-1);i--)
    {
        if (name == table.at(i)->getName())
            return true;
        //
        if (i == ptr.at(ptr.size()-1)&& i != 0)
        {
            Function* temp = dynamic_cast<Function*>(table.at(i));
            if (temp->findpara(name))
                return true;
        }
        
    }
    return false;
}

//  <������>��bool SymbolTable::isParaReference(string func_name,int location)
//  <��������˵��>���ж�������Ϊfunc_name����������λ��Ϊlocation+1�Ĳ����Ƿ�Ϊ
//	���õ���
bool SymbolTable::isParaReference(string func_name,int location)
{
	
	for(int i=ptr.size()-1;i>0;i--)
	{
		
		if(table.at(ptr.at(i))->getName()==func_name)
		{
			Function* temp=dynamic_cast<Function*>(table.at(ptr.at(i)));
			return temp->getParaType(location)->getReference();
		} 
	}
	return false;
}

//  <������>��bool SymbolTable::isParaReference(int func_location,string para_name)
//  <��������˵��>���жϵ�func_location�������ĺ����У�����Ϊpara_name�ı����Ƿ�
//	Ϊ���õ���
bool SymbolTable::isParaReference(int func_location,string para_name)
{
	if(func_location<=0||func_location>ptr.size()-1)
		return false;
	
	Function* temp=dynamic_cast<Function*>(table.at(ptr.at(func_location)));
	
	if(temp->getParaType(para_name)!=NULL)
		return temp->getParaType(para_name)->getReference();
	return false;
}

//  <������>��bool SymbolTable::find_in_global(string name)
//  <��������˵��>����ȫ���Լ���ǰ���в�������Ϊname�ı�ʶ���Ƿ����
//	���������ڴ�ӡ�����Ҫ���ҷ��ű����û�н����ض�λ������������
//	������ұ�ķ�Χ������ȫ����ң����������жϵ�ǰ���Ƿ�Ϊ�գ�Ȼ��
//	�жϵ�ǰ���Ƿ�С�������飬����ǵĻ����ͽ���ȫ����ң�����Ͳ���
//	��ǰ���Լ���һ���ӿ������֮��Ĳ���
bool SymbolTable::find_in_global(string name)
{
	if(table.size()==0)
		return false;
	if(ptr.size()<=2)
	{
		for (int i = (table.size() - 1);i >= 0;i--)
	    {
	        if (name == table.at(i)->getName())
	        {
	        	
	        	return true;
	        }
	            
	        //?����?�ơ�??�̦�?����???��??��,a�С�?�ơ�??��???��?��????�C����
	        if (i == ptr.at(ptr.size()-1) && i != 0)
	        {
	        	
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return true;
	        	
	        }
	       
    	}
     	return false;
	}
	else
	{
		for(int i=table.size()-1;i>=ptr.at(ptr.size()-1);i--)
		{
			if (name==table.at(i)->getName())
	        	return true;
		}
		for (int i = (ptr.at(1));i >= 0;i--)
	    {
	        if (name == table.at(i)->getName())
	            return true;    
    	}
     	return false;
	}
	return false;
}

//  <������>��SymbolType* SymbolTable::getType(string name)
//  <��������˵��>����������Ϊname�ı�ʶ�����ͣ������ڷ�������֮ǰ
//	һ��Ҫ���в��Ҳ�������ˣ���Ϊname�ı�ʶ��һ�����ڣ�
//	ͬ��������û�н����ض�λ��������˲��ұ�ķ���ҲҪ�����仯����
//	find_in_globalI()������ͬ������׸��
SymbolType* SymbolTable::getType(string name)
{ 
	if(table.size()==0)
		return NULL;
	if(ptr.size()<=2)
	{
		for (int i = (table.size() - 1);i >= 0;i--)
	    {
	        if (name == table.at(i)->getName())
	            return table.at(i);
	        if (i == ptr.at(ptr.size()-1)&&i!=0)
	        {
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return temp->getParaType(name);
	        }
	        
	    }
	}
    else
    {
    	for (int i = (table.size() - 1);i >= ptr.at(ptr.size()-1);i--)
	    {
	        if (name == table.at(i)->getName())
	            return table.at(i);
	        if (i == ptr.at(ptr.size()-1)&&i!=0)
	        {
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return temp->getParaType(name);
	        }   
	    }
	    for(int i = (ptr.at(1));i>=0;i--)
	    {
	    	if (name == table.at(i)->getName())
	            return table.at(i);
	        if (i == ptr.at(ptr.size()-1)&&i!=0)
	        {
	            Function* temp = dynamic_cast<Function*>(table.at(i));
	            if (temp->findpara(name))
	                return temp->getParaType(name);
	        }   
	    }
    }
    return NULL;
}

//  <������>��void SymbolTable::reLocation()
//  <��������˵��>���Ժ��������ض�λ��ɾ����ǰ���е�����ָ��
//	�������ڴ�ӡ�����ʱ����Ҫ�õ����п��е���Ϣ�����û�е���

void SymbolTable::print()
{
	for(int i=0;i<table.size();i++)
	{
		cout<<table.at(i)->getName()<<endl;
	}
}

void SymbolTable::reLocation()
{/*
    int pos = ptr.at(ptr.size()-1);
    for (int i = (table.size() - 1);i > pos;i--)
        delete table.at(i);*/
}


