// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestBPLibrary.h"
#include "Test.h"
#include "Test/Mysql/mysql.h"

UTestBPLibrary::UTestBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UTestBPLibrary::TestSampleFunction(float Param)
{
	return -1;
}

bool UTestBPLibrary::OpenMysql()
{
	MYSQL mysql;
	MYSQL_RES *result= nullptr;

	int result_int=INDEX_NONE;
	
	mysql_init(&mysql);
	
	
	if(mysql_real_connect(&mysql,"127.0.0.1","root","123456","test",3306,nullptr,0))
	{
		if(result_int==mysql_query(&mysql,"SELECT * FROM ItemsInfo")==0)
		{
			if((result = mysql_store_result(&mysql))!= nullptr)
			{
				while (MYSQL_ROW sql_row= mysql_fetch_row(result))
				{
					GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,*FString::Printf(TEXT("ID %s "),ANSI_TO_TCHAR(sql_row[0])));
				}
				
			}
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,*FString::Printf(TEXT("Query sql Failed")));
			GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,mysql_error(&mysql));
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,*FString::Printf(TEXT("Connect sql Failed")));
		GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,mysql_error(&mysql));
	}
	
	if(result != nullptr)
	{
		mysql_free_result(result);
	}
	
	
	
	mysql_close(&mysql);

	return true;
}

