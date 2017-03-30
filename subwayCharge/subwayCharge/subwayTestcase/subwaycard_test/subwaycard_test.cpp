#if _SUBWAY_LLT
#include <gtest/gtest.h>
#include "mockcpp/mockcpp.hpp"
#include "subwayCard.h"

using namespace testing;

class subwayCardTest : public testing::Test
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

int add(int x, int y)
{
    return x + y;
}

int minus(int x, int y)
{
    return x - y;
}

//****
TEST_F(subwayCardTest, Test1)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EXPECT_TRUE(1 == 1);
    
    //��׮
    MOCKER(add)
        .expects(once())
        .will(returnValue(1));

    MOCKER(minus)
        .expects(once())
        .will(returnValue(2));

    EXPECT_TRUE(add(3, 5) == 1);
    EXPECT_TRUE(minus(3, 5) == 2);

    //���׮����
    GlobalMockObject::verify();

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

TEST_F(subwayCardTest, Test2)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EXPECT_TRUE(1 == 1);
    
    //��׮


    EXPECT_TRUE(add(3, 5) == 8);
    EXPECT_TRUE(minus(10, 5) == 5);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

#endif