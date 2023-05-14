// Some copyright should be here...

using UnrealBuildTool;
using System.IO;


public class Test : ModuleRules
{

	public string ProjectDirectory
	{
		get
		{
			return Path.GetFullPath(Path.Combine(ModuleDirectory,"../../../../"));
		}
	}

	private void CopyToProjectBinaries(string FilePathName,ReadOnlyTargetRules Target)
	{
		string BineriesDirectory = Path.Combine(ProjectDirectory, "Binaries", Target.Platform.ToString());
		string FileName = Path.GetFileName(FilePathName);
		if (!Directory.Exists(BineriesDirectory))
		{
			Directory.CreateDirectory(BineriesDirectory);
		}

		string ProjectFileFullName = Path.Combine(BineriesDirectory, FileName);
		if (!File.Exists(ProjectFileFullName))
		{
			File.Copy(FilePathName,ProjectFileFullName,true);
		}
		
		RuntimeDependencies.Add(ProjectFileFullName);
	}
	
	public Test(ReadOnlyTargetRules Target) : base(Target)
	{
		
		bEnableUndefinedIdentifierWarnings = false;

		string PluginsDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));
		string SQLLibDirectory = Path.Combine(PluginsDirectory, "MySQL");
		string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
		string MySqlPath = Path.Combine(SQLLibDirectory, PlatformString);
		
		PublicIncludePaths.Add(MySqlPath);
		
		RuntimeDependencies.Add(Path.Combine(MySqlPath,"libmysql.dll"));
		PublicAdditionalLibraries.Add(Path.Combine(MySqlPath,"libmysql.lib"));
		
		CopyToProjectBinaries(Path.Combine(MySqlPath,"libmysql.dll"),Target);
		CopyToProjectBinaries(Path.Combine(MySqlPath,"libmysql.lib"),Target);
		
		
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
