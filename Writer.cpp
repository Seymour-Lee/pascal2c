//
//  <�ļ���>��Writer.cpp
//  <�ļ�����˵��>�����ļ�ʵ����Writer������Գ�Ա����
//  <��������>��16/03/2017

//����ͷ�ļ�
#include "Writer.h"

//
//  <������>��Writer& Writer::getInstance()
//  <��������˵��>���ú������ڵ�����Writer��Ķ���ʹ��Writerʱ�ȵ��øú�����ȡ����
Writer& Writer::getInstance() {
    static Writer instance;
    return instance;
}

//
//  <������>��std::streambuf * Writer::rdbuf() const
//  <��������˵��>���ú������ڻ�ȡ���������ָ��
std::streambuf * Writer::rdbuf() const {
    return stream.rdbuf();
}

//
//  <������>��std::streambuf * Writer::rdbuf(std::streambuf * sb)
//  <��������˵��>���ú��������ض��������
std::streambuf * Writer::rdbuf(std::streambuf * sb) {
    return stream.rdbuf(sb);
}

//
//  <������>��Writer::operator std::ostream&()
//  <��������˵��>���ú������ڷ���˽�е�stream��Ա
Writer::operator std::ostream&() {
    return stream;
}

//
//  <������>��Writer::Writer() : stream(std::cout.rdbuf())
//  <��������˵��>�����캯��
Writer::Writer() : stream(std::cout.rdbuf()) {
    tabCounter=0;
}

//
//  <������>��void Writer::addTabCounter()
//  <��������˵��>������������
void Writer::addTabCounter(){
    tabCounter++;
}

//
//  <������>��void Writer::decTabCounter()
//  <��������˵��>������������
void Writer::decTabCounter(){
    tabCounter--;
}

//
//  <������>��void Writer::printTabs()
//  <��������˵��>����ӡ����
void Writer::printTabs(){
    std::ostream& cout=Writer::getInstance();
    for (int i=0; i<tabCounter; i++) {
        cout<<"    ";
    }
}

