#if _SUBWAY_LLT
#include <gtest/gtest.h>
#include "mockcpp/mockcpp.hpp"
#include "subwayCard.h"

using namespace testing;

class subwayPriceTest : public testing::Test
{
public:
    //�����׼����¼�
    //�ڲ������а�������������ǰ����һ��
    static void SetUpTestCase()     
    {
    }

    //�ڲ������а�������������ȫ�����н���������һ��
    static void TearDownTestCase()
    {
    }

    //��������������¼�
    //�������е�ÿ��������ʼ����ǰ����һ��
    void SetUp()
    {
         //Ϊ��С���Բ�����������֮���Ӱ�죬����ɽ���һЩ��ʼ������
    }

    //��������ÿ����������������һ��
    void TearDown()
    {
         //�ɽ���һЩ��̬�ڴ���ͷŲ���
     }
};

//****
TEST_F(subwayPriceTest, Test1)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EXPECT_TRUE(1 == 1);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

#endif