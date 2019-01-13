//
//  <�ļ���>��Writer.h
//  <�ļ�����˵��>�����ļ�������һ��Writer�࣬�����ض��������
//  <��������>��16/03/2017

#ifndef Writer_h
#define Writer_h

//����ͷ�ļ�
#include <iostream>
#include <fstream>
#include <string>

//
//  <������>��Writer
//  <�๦��˵��>������������ļ�д�����ݵĹ��ܡ��������ض���
//  �������
class Writer{
public:
    //����Writer����
    static Writer & getInstance();
        
    // ��ȡ������Ļ�����ָ��
    std::streambuf* rdbuf() const;
    // �ض���������Ļ�����ָ��
    std::streambuf* rdbuf(std::streambuf* sb);
    
    //��ȡ˽�е������
    operator std::ostream&();
    
    //����tab��������
    void addTabCounter();
    //����tab��������
    void decTabCounter();
    //��ӡ��ǰ�е�tab������������
    void printTabs();  
    
private:
    Writer();//���캯��
    
    int tabCounter;//��¼tab��
    
    std::ostream stream;//�����
};


#endif /* Writer_h */

