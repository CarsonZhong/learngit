#if _SUBWAY_LLT
#include <gtest/gtest.h>
#include "mockcpp/mockcpp.hpp"
#include "subwayLine.h"

using namespace testing;

class subwayLineTest : public testing::Test
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
        InitSubwayLine();
    }

    //��������ÿ����������������һ��
    void TearDown()
    {
         //�ɽ���һЩ��̬�ڴ���ͷŲ���
     }
};

//���ӵ�һ��վ�㣬վ��������Ҫ�󣬷���ʧ��
TEST_F(subwayLineTest, AddStation_NameOutofRange_ReturnError)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = AddSubwayStation("S101", 1000);
    EXPECT_TRUE(EN_RETURN_INVALID_STATION == enValue);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//���ӵ�һ��վ�㣬���ƺ;��붼����Ҫ�󣬷��سɹ�
TEST_F(subwayLineTest, AddStation_FirstStationNameOk_ReturnSucc)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S1", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(0 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//�ظ�����һ��վ�㣬���Ӵ���
TEST_F(subwayLineTest, AddStation_AddTheSameStationRepeat_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S1", 1000);
    EXPECT_TRUE(EN_RETURN_ADD_STATION_REPEAT == enValue);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//���ӵڶ���վ�㣬��ǰһվ��ľ���Ϊ0�����ش���
TEST_F(subwayLineTest, AddStation_SecondStationDis0_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 0);
    EXPECT_TRUE(EN_RETURN_INVALID_DIS == enValue);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//���ӵڶ���վ�㣬��ǰһվ��ľ���Ϊ51Km�����ش���
TEST_F(subwayLineTest, AddStation_SecondStationDis51Km_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 51000);
    EXPECT_TRUE(EN_RETURN_INVALID_DIS == enValue);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//��������վ��ɹ��󣬻�ȡ��վ���ľ���ɹ�
TEST_F(subwayLineTest, AddStation_AddTwoStaionGetDisSucc_ReturnSucc)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S2", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(1200 == dis);

    enValue = GetSubwayStationDis("S2", "S1", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(1200 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//������ʼվ�����Ʋ��ڷ�Χ�����ش���
TEST_F(subwayLineTest, QueryDis_SrcStationInvalidNo_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S101", "S2", dis);
    EXPECT_TRUE(EN_RETURN_INVALID_STATION == enValue);
    EXPECT_TRUE(0 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//����Ŀ��վ�����Ʋ��ڷ�Χ�����ش���
TEST_F(subwayLineTest, QueryDis_DstStationInvalidNo_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S102", dis);
    EXPECT_TRUE(EN_RETURN_INVALID_STATION == enValue);
    EXPECT_TRUE(0 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//������ʼվ��δͶ��ʹ�ã����ش���
TEST_F(subwayLineTest, QueryDis_SrcStationUnused_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S10", "S2", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);
    EXPECT_TRUE(0 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//����Ŀ��վ��δͶ��ʹ�ã����ش���
TEST_F(subwayLineTest, QueryDis_DstStationUnused_ReturnErr)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S12", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);
    EXPECT_TRUE(0 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}

//������ʼվ���Ŀ��վ�㶼����Ҫ�󣬷��سɹ�
TEST_F(subwayLineTest, QueryDis_StationOK_ReturnSucc)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    enValue = AddSubwayStation("S1", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S2", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S3", 2200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S4", 1000);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S4", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(4400 == dis);

    enValue = GetSubwayStationDis("S4", "S1", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(4400 == dis);

    enValue = GetSubwayStationDis("S1", "S3", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(3400 == dis);

    enValue = GetSubwayStationDis("S3", "S1", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(3400 == dis);

    //3  ����ʹ��gtest�Ķ�������������ͨ�������ж�
    
}


//û������վ��, ���ٺ󣬲�ѯ����վ���ľ�����ǡ�δ���õ�վ�㡱
TEST_F(subwayLineTest, DestroyLine_NoUsedStaion)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;
    (void)DelSubwayLine();

    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S3", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S3", "S90", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S99", "S1", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S0", "S50", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S99", "S0", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);
}

//������վ��, ���ٺ󣬲�ѯ����վ���ľ�����ǡ�δ���õ�վ�㡱
TEST_F(subwayLineTest, DestroyLine_UsedStaion)
{
  	//1 ��������,��ʼ��
    
     
    //2  �û�д�Լ��Ĳ������̣����ñ��⺯��
    EN_RETURN_CODE enValue = EN_RETURN_SUCC;

    enValue = AddSubwayStation("S0", 0);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S1", 1200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S50", 2200);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    enValue = AddSubwayStation("S99", 1000);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);

    //��ѯ��������
    unsigned int dis = 0;
    enValue = GetSubwayStationDis("S1", "S99", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(3200 == dis);

    enValue = GetSubwayStationDis("S50", "S99", dis);
    EXPECT_TRUE(EN_RETURN_SUCC == enValue);
    EXPECT_TRUE(1000 == dis);

    //����
    (void)DelSubwayLine();

    enValue = GetSubwayStationDis("S1", "S99", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S99", "S0", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S0", "S50", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S50", "S0", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S99", "S0", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);

    enValue = GetSubwayStationDis("S99", "S1", dis);
    EXPECT_TRUE(EN_RETURN_STATION_UNUSED == enValue);
}


#endif
