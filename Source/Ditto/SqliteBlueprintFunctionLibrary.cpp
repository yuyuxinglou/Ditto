// Fill out your copyright notice in the Description page of Project Settings.


#include "SqliteBlueprintFunctionLibrary.h"




int USqliteBlueprintFunctionLibrary::OpenDataBase(FString DataPath)
{

	// DataPath = FPaths::ProjectContentDir()+ DataPath;
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
