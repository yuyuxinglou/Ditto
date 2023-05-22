// Fill out your copyright notice in the Description page of Project Settings.


#include "SqliteBlueprintFunctionLibrary.h"
#include "SQLiteDatabaseConnection.h"



int USqliteBlueprintFunctionLibrary::OpenDataBase(FString DataPath)
{

	DataPath = FPaths::ProjectContentDir()+ DataPath;
	FSQLiteDatabaseConnection Database;
	// FSQLiteDatabase Database;
	if(!Database.Open(*DataPath, nullptr, nullptr))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, *DataPath);
		return 3;
	}
	


	

	FString query=FString::Printf(TEXT("Select * from TestTable"));

	FDataBaseRecordSet* outRecords=nullptr;
	
	if (!Database.Execute(*query,outRecords))
	{
		delete outRecords;
		return 0;
	}

	const int count =outRecords->GetRecordCount();
	if(count==0)
	{
		delete outRecords;
		return 0;
	}

	int result=-1;

	for (FDataBaseRecordSet::TIterator i(outRecords);i;++i)
	{
		for(FDatabaseColumnInfo Column: i->GetColumnNames())
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, Column.ColumnName);
		}
	}
	delete outRecords;
	Database.Close();
	//
	// FSQLiteDatabase db;
	//
	//
	//
	// if(!db.Open(*DataPath,ESQLiteDatabaseOpenMode::ReadWriteCreate))
	// {
	// 	return false;
	// }
	//
	// FSQLitePreparedStatement sm=db.PrepareStatement(TEXT("select * from Items"));
	//
	// const int count =sm.GetColumnNames().Num();
	//
	// db.Close();
	// sm.Destroy();
	return 1;
	
	// while (sm.Step()==ESQLitePreparedStatementStepResult::Row)
	// {
	// 	// sm.GetColumnValueByIndex(0,);
	// }
	
	
	return true;
}
