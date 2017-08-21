##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Jidelnicek
ConfigurationName      :=Debug
WorkspacePath          :=C:/C++
ProjectPath            :=C:/GitHub/Jidelnicek
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jiří Kudlata
Date                   :=22/08/2017
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Jidelnicek.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/SeznamJidel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Soubor.cpp$(ObjectSuffix) $(IntermediateDirectory)/Napoj.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pokrm.cpp$(ObjectSuffix) $(IntermediateDirectory)/Jidlo.cpp$(ObjectSuffix) $(IntermediateDirectory)/Jidelnicek.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/SeznamJidel.cpp$(ObjectSuffix): SeznamJidel.cpp $(IntermediateDirectory)/SeznamJidel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/SeznamJidel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SeznamJidel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SeznamJidel.cpp$(DependSuffix): SeznamJidel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SeznamJidel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SeznamJidel.cpp$(DependSuffix) -MM SeznamJidel.cpp

$(IntermediateDirectory)/SeznamJidel.cpp$(PreprocessSuffix): SeznamJidel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SeznamJidel.cpp$(PreprocessSuffix) SeznamJidel.cpp

$(IntermediateDirectory)/Soubor.cpp$(ObjectSuffix): Soubor.cpp $(IntermediateDirectory)/Soubor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/Soubor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Soubor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Soubor.cpp$(DependSuffix): Soubor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Soubor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Soubor.cpp$(DependSuffix) -MM Soubor.cpp

$(IntermediateDirectory)/Soubor.cpp$(PreprocessSuffix): Soubor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Soubor.cpp$(PreprocessSuffix) Soubor.cpp

$(IntermediateDirectory)/Napoj.cpp$(ObjectSuffix): Napoj.cpp $(IntermediateDirectory)/Napoj.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/Napoj.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Napoj.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Napoj.cpp$(DependSuffix): Napoj.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Napoj.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Napoj.cpp$(DependSuffix) -MM Napoj.cpp

$(IntermediateDirectory)/Napoj.cpp$(PreprocessSuffix): Napoj.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Napoj.cpp$(PreprocessSuffix) Napoj.cpp

$(IntermediateDirectory)/Pokrm.cpp$(ObjectSuffix): Pokrm.cpp $(IntermediateDirectory)/Pokrm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/Pokrm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pokrm.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pokrm.cpp$(DependSuffix): Pokrm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Pokrm.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Pokrm.cpp$(DependSuffix) -MM Pokrm.cpp

$(IntermediateDirectory)/Pokrm.cpp$(PreprocessSuffix): Pokrm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pokrm.cpp$(PreprocessSuffix) Pokrm.cpp

$(IntermediateDirectory)/Jidlo.cpp$(ObjectSuffix): Jidlo.cpp $(IntermediateDirectory)/Jidlo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/Jidlo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Jidlo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Jidlo.cpp$(DependSuffix): Jidlo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Jidlo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Jidlo.cpp$(DependSuffix) -MM Jidlo.cpp

$(IntermediateDirectory)/Jidlo.cpp$(PreprocessSuffix): Jidlo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Jidlo.cpp$(PreprocessSuffix) Jidlo.cpp

$(IntermediateDirectory)/Jidelnicek.cpp$(ObjectSuffix): Jidelnicek.cpp $(IntermediateDirectory)/Jidelnicek.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/GitHub/Jidelnicek/Jidelnicek.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Jidelnicek.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Jidelnicek.cpp$(DependSuffix): Jidelnicek.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Jidelnicek.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Jidelnicek.cpp$(DependSuffix) -MM Jidelnicek.cpp

$(IntermediateDirectory)/Jidelnicek.cpp$(PreprocessSuffix): Jidelnicek.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Jidelnicek.cpp$(PreprocessSuffix) Jidelnicek.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


